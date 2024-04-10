#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

llint tt, n, m, sum, bip;
llint s[MAXN], t[MAXN];
int bio[MAXN];
vector <int> v[MAXN];

void dfs (int x, int col) {
    bio[x] = col;
    for (auto sus : v[x]) {
        if (bio[sus] == 0) {
            dfs(sus, 3 - col);
        } else {
            if (bio[sus] == bio[x]) bip = 0;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> tt;
    while (tt--) {
        cin >> n >> m;
        sum = 0;
        for (int i = 1; i <= n; i++) {
            v[i].clear();
            bio[i] = 0;
            cin >> s[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> t[i];
            sum += t[i] - s[i];
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        if (abs(sum) % 2 == 1) {
            cout << "NO\n";
        } else {
            bip = 1;
            dfs(1, 1);
            if (bip == 0) {
                cout << "YES\n";
            } else {
                llint evn = 0, odd = 0;
                for (int i = 1; i <= n; i++) {
                    if (bio[i] == 1) evn += t[i] - s[i]; else odd += t[i] - s[i];
                }
                if (evn == odd) cout << "YES\n"; else cout << "NO\n";
            }
        }
    }
    return 0;
}