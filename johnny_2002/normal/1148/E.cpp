#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define X first
#define Y second

const int N = 3e5 + 10;
int n;
set<ii> mSet;

int a[N];
int t[N];
int ansn;
int anso[6 * N][3];

void shift(int x, int y, int dist) {
    int len = a[y] - a[x];
    assert(len > 0); 
    assert(dist * 2 <= len);

    ansn++;
    anso[ansn][0] = x, anso[ansn][1] = y, anso[ansn][2] = dist;
    a[x] += dist;
    a[y] -= dist;
    //mSet.insert(p1);
    //mSet.insert(p2);
}

void solve() {
    int odd = 0;
    for(auto i : mSet) odd ^= i.X;
    for(int i = 1; i <= n; i++) odd ^= t[i];
    if (odd & 1) {
        cout << "NO";
        return;
    }


    stack<ii> s;
    int i = 0;
    for(auto point : mSet) {
        int cur = point.Y; i++;
        //cout << a[cur] << " " << t[i] << '\n';
        if (a[cur] < t[i]) {
            s.push(ii(cur, t[i]));
            continue;
        }
        while (a[cur] > t[i]) {
            if (s.empty()) {
                cout << "NO";
                return;
            }
            ii choose = s.top(); 
            int sLen = min(a[cur] - t[i], choose.Y - a[choose.X]);
            shift(choose.X, cur, sLen);
            if (a[choose.X] == choose.Y) s.pop();
        }
        //for(int j = 1; j <= n; j++) cout << a[j] << " \n"[j == n];
    }
    if (!s.empty()) {
        cout << "NO";
        return;
    }
    cout << "YES\n" << ansn << '\n';
    for(int i = 1; i <= ansn; i++) 
        for(int j = 0; j < 3; j++) cout << anso[i][j] << " \n"[j == 2];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i]; 
        mSet.insert(ii(a[i], i));
    }
    for(int i = 1; i <= n; i++) cin >> t[i];
    sort(t + 1, t + n + 1);


    solve(); 

    
}