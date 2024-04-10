#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int tt, n;
string s, t;
int a[25][25];

void mv (int x, int y) {
    for (int i = x + 1; i < 20; i++) a[y][i] += a[x][i], a[x][i] = 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> tt;
    while (tt--) {
        memset(a, 0, sizeof a);
        cin >> n >> s >> t;
        bool moze = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] > t[i]) moze = 0;
            a[s[i] - 'a'][t[i] - 'a']++;
        }
        if (moze == 0) {
            cout << -1 << '\n';
        } else {
            int sol = 0;
            for (int i = 0; i < 20; i++) {
                for (int j = 0; j < i; j++) {
                    if (a[j][i]) mv(j, i), sol++;
                }
            }
            cout << sol << '\n';
        }
    }
    return 0;
}