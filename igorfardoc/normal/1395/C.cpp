#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vi a(n);
    vi b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int j = 0; j < m; j++) {
        cin >> b[j];
    }
    vvi mass(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            mass[i].push_back(b[j]);
        }
    }
    int ans = 0;
    for(int st = 8; st >= 0; st--) {
        bool can = true;
        for(int i = 0; i < n; i++) {
            if(!((a[i] >> st) & 1)) {
                continue;
            }
            bool here = false;
            for(int j = 0; j < mass[i].size(); j++) {
                if(!((mass[i][j] >> st) & 1)) {
                    here = true;
                    break;
                }
            }
            if(!here) {
                can = false;
                break;
            }
        }
        if(!can) {
            ans ^= (1 << st);
            continue;
        }
        for(int i = 0; i < n; i++) {
            if(!((a[i] >> st) & 1)) {
                continue;
            }
            vi new1;
            for(int j = 0; j < mass[i].size(); j++) {
                if(!((mass[i][j] >> st) & 1)) {
                    new1.push_back(mass[i][j]);
                }
            }
            mass[i] = new1;
        }
    }
    cout << ans;
}