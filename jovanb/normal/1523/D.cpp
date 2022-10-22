#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 200000;

string s[MAXN+5];
int u[65];
int od[65];
int dp[(1<<15)];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m, p;
    cin >> n >> m >> p;
    for(int i=1; i<=n; i++){
        cin >> s[i];
    }
    int turns = 50;
    int mx = 0;
    int treba = (n+1)/2;
    string res = "";
    for(int j=0; j<m; j++) res += '0';
    while(turns--){
        int pr = rnd()%n + 1;
        for(int j=0; j<m; j++){
            u[j] = -1;
            od[j] = -1;
        }
        int cnt = 0;
        for(int j=0; j<m; j++){
            if(s[pr][j] == '1'){
                od[cnt] = j;
                u[j] = cnt;
                cnt++;
            }
        }
        for(int i=0; i<(1<<p); i++) dp[i] = 0;
        for(int i=1; i<=n; i++){
            int br = 0;
            for(int j=0; j<m; j++){
                if(u[j] != -1 && s[i][j] == '1') br += (1 << u[j]);
            }
            dp[br]++;
        }
        for(int i=0; i<p; i++){
            for(int mask=0; mask<(1<<p); mask++){
                if(!((1 << i) & mask)) dp[mask] += dp[mask ^ (1 << i)];
            }
        }
        for(int mask=0; mask<(1<<p); mask++){
            if(__builtin_popcount(mask) > mx && dp[mask] >= treba){
                mx = __builtin_popcount(mask);
                for(int j=0; j<m; j++) res[j] = '0';
                for(int j=0; j<p; j++) if((1 << j) & mask) res[od[j]] = '1';
            }
        }
    }
    cout << res << "\n";
    return 0;
}