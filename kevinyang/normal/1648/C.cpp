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
struct BIT{
    vector<int>arr;
    int size;
    void init(int n){
        size = n;
        arr.resize(n+5);
    }
    void update(int x, int val){
        for(int a = x; a<=size; a+=a&-a){
            arr[a]+=val;
            arr[a]%=mod;
        }
    }
    int query(int x){
        int sum = 0;
        for(int a = x; a>0; a-=a&-a){
            sum+=arr[a];
            sum%=mod;
        }
        return sum;
    }
    void change(int x, int val){
        int v = val-(query(x)-query(x-1));
        v%=mod; v+=mod; v%=mod;
        update(x,v);
    }
    int query(int x, int y){//inclusive
        int v = query(y)-query(x-1);
        v%=mod; v+=mod; v%=mod;
        return v;
    }
};
const int mxn = 200005;
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false); precalc();
    int n,m;
    cin >> n >> m;
    vector<int>arr(n+5);
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
    }
    vector<int>arr2(m+5);
    for(int i = 1; i<=m; i++){
        cin >> arr2[i];
    }
    vector<int>freq(mxn);
    vector<int>val(mxn);
    for(int i = 1; i<=n; i++){
        freq[arr[i]]++;
    }
    BIT bit;
    bit.init(mxn);
    if(true){
        int total = fact[n-1];
        for(int i = 1; i<mxn; i++){
            total*=inv[freq[i]]; total%=mod;
        }
        for(int i = 1; i<mxn; i++){
            if(freq[i]==0){
                continue;
            }
            if(freq[i]==1){
                val[i] = total;
                bit.update(i,val[i]);
            }
            else{
                val[i] = total*fact[freq[i]]%mod*inv[freq[i]-1]%mod;
                bit.update(i,val[i]);
            }
        }
    }
    int mul = 1;
    int ans = 0;
    if(n<m){
        vector<int>freq2(mxn);
        for(int i = 1; i<=n; i++){
            freq2[arr2[i]]++;
        }
        bool f = true;
        for(int i = 1; i<mxn; i++){
            if(freq[i]>freq2[i])f = false;
        }
        if(f)ans++;
    }
    for(int i = 1; i<=min(n,m); i++){
        ans+=bit.query(arr2[i]-1)%mod*mul%mod;
        ans%=mod;
        freq[arr2[i]]--;
        if(freq[arr2[i]]<0){
            break;
        }
        if(i==min(n,m))break;
        mul*=inv[n-i]; mul%=mod;
        mul*=fact[n-i-1]; mul%=mod;
        int val = bit.query(arr2[i],arr2[i]);
        mul*=fact[freq[arr2[i]]+1]; mul%=mod;
        val*=inv[freq[arr2[i]]+1]; val%=mod;
        mul*=inv[freq[arr2[i]]]; mul%=mod;
        val*=fact[freq[arr2[i]]]; val%=mod; 
        if(freq[arr2[i]]==0){
            val = 0;
        }
        else{
            val*=fact[freq[arr2[i]]]; val%=mod;
            val*=inv[freq[arr2[i]]-1]; val%=mod;
        }
        bit.change(arr2[i],val);
        //cout << ans << "\n";
    }
    cout << ans << "\n";
    return 0;
}