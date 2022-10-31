//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n';
const int N = 3e5+7;
const ll MOD = 998244353;
ll fact[N],rev[N],pr[N];
ll binpow(ll x,int power){
	ll mult = x%MOD;
	x = 1;
	while(power){
		if (power&1){
			x = x*mult%MOD;
		}
		power /= 2;
		mult = mult*mult%MOD;
	}
	return x;
}
ll A(int n,int k){
	if (n<k || n<0){
		return 0;
	}
	return fact[n]*rev[n-k]%MOD;
}
ll C(int n,int k){
	if (n<k || n<0){
		return 0;
	}
	return A(n,k)*rev[k]%MOD;
}
int dist[N];
void solve(){
	int n,m;
	cin>>n>>m;
	pr[0] = 1;
	for(int i = 1;i<N;i+=1){
		pr[i] = pr[i-1]*m%MOD;
	}
	ll total = 0;
	for(int i = 0;i<n;i+=1){
		cin>>dist[i];
		total += dist[i];
	}
	if (total%2!=0){
		cout<<binpow(m,n)<<endl;
		return;
	}
	int ptr = 0,all = 0;
	ll csum = 0;
	for(int i = 0;i<n;i+=1){
		while(csum<total/2){
			csum += dist[ptr];
			ptr += 1;
			if (ptr==n){
				ptr -= n;
			}
		}
		if (csum*2==total){
			all += 1;
		}
		csum -= dist[i];
	}
//	cout<<all<<endl;
	all /= 2;
	ll res = 0;
	for(int x = 0;x<=min(m,all);x+=1){
		if ((n-all-x>0 && m<x) || (all>x && m-x-1<0)){
			continue;
		}
		res = (res + C(all,x)*A(m,x)%MOD*binpow(m-x,n-all-x)%MOD*binpow(m-x-1,all-x))%MOD;
	}
	cout<<res<<endl;
}
signed main(){
	fact[0] = 1;
	for(int i = 1;i<N;i+=1){
		fact[i] = fact[i-1]*i%MOD;
	}
	rev[N-1] = binpow(fact[N-1],MOD-2);
	for(int i = N-1;i>0;i-=1){
		rev[i-1] = rev[i]*i%MOD;
	}
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt = 1;
//	cin>>tt;
	while(tt--){
		solve();
	}
}