#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define X first
#define Y second


int n, k;
string s[3];

int ans[26], h[26];
int DFS(int pos, int m1, int m2) {
    if (pos == n) {
        return 1;
    }
    if (m1 && m2) return 1;
    int fro = s[0][pos] - 'a';
    int to1 = s[1][pos] - 'a', to2 = s[2][pos] - 'a';
    if (ans[fro] != -1) {
        if (!m1 && ans[fro] < to1 ) return 0;
        if (!m2 && ans[fro] > to2) return 0;
        return DFS(pos + 1, m1 || (ans[fro] > to1), m2 || (ans[fro] < to2));
    }
    int L = m1 ? 0 : s[1][pos] - 'a';
    int R = m2 ? k - 1 : s[2][pos] - 'a';
    int len = R - L + 1;
    //cout << fro << " " << L << " " << R << " " << to1 << " " << to2 << '\n';
    
    for(int i = 1; i <= len + 1; i++){
        int use = L + (i % len);
        if (h[use] == -1) {
            ans[fro] = use;
            h[use] = fro;
            if (DFS(pos + 1, m1 || (use > to1) , m2 || (use < to2))) return 1;
            ans[fro] = -1;
            h[use] = -1;
        }
    }
    return 0;
}
bool solve() {
    n = s[0].length();
    memset(ans, -1, sizeof(ans));
    memset(h, -1, sizeof(h));
    return DFS(0, 0, 0);
}
void fillintheblank() {
    for(int i = 0; i < k; i++) if (ans[i] == -1) 
        for(int j = 0; j < k; j++) if (h[j] == -1) {
            ans[i] = j;
            h[j] = i;
            break;
        }
    cout << "YES\n";
    for(int i = 0; i < k; i++) cout << char(ans[i] + 'a');
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test;
    cin >> test;
    while (test--) {
        cin >> k;
        for(int i = 0; i < 3; i++) cin >> s[i];
        if (solve()) {
            fillintheblank();
        } else cout << "NO\n";
    }
}