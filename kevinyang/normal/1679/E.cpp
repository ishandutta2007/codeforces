#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int modpow(int x, int y) {
    return !y?1:((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    vector<vector<int>>ans(18,vector<int>((1<<17)+5));
    for(int len = 1; len<=17; len++){
        vector<int>dp((1<<17)+5);
        vector<int>pw(n+5);
        pw[0] = 1;
        for(int i = 1; i<=n; i++){
            pw[i] = pw[i-1]*len; pw[i]%=mod;
        }
        for(int i = 1; i<=n; i++){
            int mask = 0;
            int rem = count(s.begin(),s.end(),'?');
            
            dp[mask]+=pw[rem];
            dp[mask]%=mod;
            for(int j = 1; j<=n; j++){
                if(i-j<1||i+j>n)break;
                if(s[i-j]=='?'&&s[i+j]!='?'){
                    int v = (s[i+j]-'a');
                    mask|=(1<<v);
                }
                else if(s[i-j]!='?'&&s[i+j]=='?'){
                    int v = (s[i-j]-'a');
                    mask|=(1<<v);
                }
                else if(s[i-j]!='?'&&s[i+j]!='?'&&s[i+j]!=s[i-j]){
                    break;
                }
                if(s[i-j]=='?'||s[i+j]=='?')rem--;
                dp[mask]+=pw[rem];
                dp[mask]%=mod;
            }
        }
        for(int i = 1; i<n; i++){
            int mask = 0;
            int rem = count(s.begin(),s.end(),'?');
            for(int j = 0; j<=n; j++){
                if(i-j<1||i+j+1>n)break;
                if(s[i-j]=='?'&&s[i+j+1]!='?'){
                    int v = (s[i+j+1]-'a');
                    mask|=(1<<v);
                }
                else if(s[i-j]!='?'&&s[i+j+1]=='?'){
                    int v = (s[i-j]-'a');
                    mask|=(1<<v);
                }
                else if(s[i-j]!='?'&&s[i+j+1]!='?'&&s[i+j+1]!=s[i-j]){
                    break;
                }
                if(s[i-j]=='?'||s[i+j+1]=='?')rem--;
                dp[mask]+=pw[rem];
                dp[mask]%=mod;
            }
        }
        /*
        int v = dp[0];
        for(int i = 0; i<17; i++){
            dp[(1<<i)]+=v;
        }
        dp[0] = 0;
        */
        for(int j = 0; j<17; j++){
            for(int i = 0; i<(1<<17); i++){
                if(i&(1<<j)){
                    dp[i]+=dp[i^(1<<j)];
                    dp[i]%=mod;
                }
            }
        }
        for(int i = 0; i<(1<<17); i++){
            ans[len][i] = dp[i];
        }
    }
    
    int q;
    cin >> q;
    while(q--){
        string t;
        cin >> t;
        int mask = 0;
        for(char nxt: t){
            int v = nxt-'a';
            mask+=(1<<v);
        }
        cout << ans[t.size()][mask] << "\n";
    }
    return 0;
}