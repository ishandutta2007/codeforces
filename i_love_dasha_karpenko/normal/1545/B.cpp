#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int DIM = 1E5+7;
const ll MOD = 998244353;
int A[DIM];
ll fact[DIM],rev[DIM];
ll C(int n,int k){
    return ((fact[n]*rev[k])%MOD*rev[n-k])%MOD;
}
int solve() {

    int n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        A[i] = ch-'0';
    }
    int len = 0,cnt = 0;
    for(int i = 1;i<=n;++i){
        if (A[i] && A[i]==A[i+1]){
            ++cnt;
            ++len;
            ++i;
            continue;
        }
        if (A[i]==0)
            ++len;
    }
    cout<<C(len,cnt)<<endl;
	return 1;
}
ll binpow(ll x,int power){
    ll mult = x%MOD;
    x = 1;
    while(power){
        if (power&1)
            x = (x*mult)%MOD;
        power/=2;
        mult = (mult*mult)%MOD;
    }
    return x;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fact[0] = rev[0] = 1;
    for(int i = 1;i<DIM;++i){
        fact[i] = (fact[i-1]*i)%MOD;
        rev[i] = binpow(fact[i],MOD-2);
    }
	int t;
	cin>>t;
	while(t--)
		assert(solve());
}