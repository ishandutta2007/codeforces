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
int n;
vector<string>arr(100005);
int cnt1(){
    int w = 0; int b = 0;
    int q = 0;
    for(int i = 1; i<=n; i++){
        w+=count(arr[i].begin(),arr[i].end(),'W');
        b+=count(arr[i].begin(),arr[i].end(),'B');
        q+=count(arr[i].begin(),arr[i].end(),'?');
    }
    if(w>n||b>n)return 0;
    return choose(q,n-w);
}
int cnt2(){
    int w = 0; int b = 0;
    int q = 0;
    for(int i = 1; i<=n; i++){
        if(arr[i]=="WW")return 0;
        if(arr[i]=="BB")return 0;
        if(arr[i][0]=='W'||arr[i][1]=='B')w++;
        else if(arr[i][0]=='B'||arr[i][1]=='W')b++;
        else q++;
    }
    if(w>n||b>n)return 0;
    int ans = modpow(2,q);
    if(b==0)ans+=mod-1;
    if(w==0)ans+=mod-1;
    ans%=mod;
    return ans;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false); precalc();
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
    }
    int ans = cnt1()-cnt2();
    //cout << cnt1() << " " << cnt2() << "\n";
    ans+=mod;
    ans%=mod;
    cout << ans << "\n";
    return 0;
}