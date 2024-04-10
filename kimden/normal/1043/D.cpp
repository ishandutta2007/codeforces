#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(m, vector<int>(n));
    vector<int> nxt(n, -1);
    for(int j = 0; j < m; ++j){
        for(int i = 0; i < n; ++i){
            cin >> v[j][i];
            --v[j][i];
            if(i){
                if(nxt[v[j][i - 1]] == -1 || nxt[v[j][i - 1]] == v[j][i]){
                    nxt[v[j][i - 1]] = v[j][i];
                }else{
                    nxt[v[j][i - 1]] = -2;
                }
            }
        }
        nxt[v[j][n - 1]] = -2;
    }
    vector<int> prv(n, -2);
    for(int i = 0; i < n; ++i){
        if(nxt[i] != -2){
            prv[nxt[i]] = i;
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        if(prv[i] == -2){
            int cnt = 1;
            int cur = i;
            while(nxt[cur] != -2){
                cur = nxt[cur];
                ++cnt;
            }
            ans += cnt * ll(cnt + 1) / 2;
        }
    }
    cout << ans << endl;



}