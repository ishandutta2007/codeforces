#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>fact(2000010);
vector<int>inv(2000010);
const int mod = 998244353;
int modpow(int x, int y) {
    return !y?1:((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}
int choose(int x, int y){
    if(y>x)return 0;
    return (fact[x]*inv[y]%mod)*inv[x-y]%mod;
}
int permute(int x, int y){
    if(y>x)return 0;
    return (fact[x]*inv[x-y])%mod;
}
void precalc(){
    fact[0] = 1; inv[0] = 1;
    for(int i = 1; i<=2000000; i++){
        fact[i] = fact[i-1]*i%mod;
    }
    inv[2000000] = modpow(fact[2000000],mod-2);
    for(int i = 1999999; i>0; i--){
        inv[i] = inv[i+1]*(i+1)%mod;
    }
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false); precalc();
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = " " + s;
    if(k==0){
        cout << "1\n";
        return 0;
    }
    vector<int>idx;
    idx.push_back(0);
    for(int i = 1; i<=n; i++){
        if(s[i]=='1')idx.push_back(i);
    }
    idx.push_back(n+1);
    int ans = 1;
    for(int i = k+1; i<idx.size(); i++){
        int l = idx[i-k-1]+1; int r = idx[i]-1;
        
        if(i==k+1){
            ans+=choose(r-l+1,k)-1;
            ans+=mod;
            ans%=mod;
        }
        else if(k==1){
            ans+=choose(r-l+1,k)-1;
            ans+=mod;
            ans%=mod;
        }
        else{
            int ind = idx[i-1];
            ans+=choose(ind-l,k);
            ans%=mod;
            for(int j = ind+1; j<=r; j++){
                int v = choose(j-l,k-1)%mod;
                ans+=v;
                ans%=mod;
            }
        }
        //cout << ans << " ";
    }
    cout << ans << "\n";
    return 0;
}