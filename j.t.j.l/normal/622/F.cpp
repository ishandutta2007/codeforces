#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;
typedef long long ll;
typedef pair<int, int> PII;

ll pw(ll p, ll q){
	ll ret = 1;
	for(; q; q>>=1){
		if (q & 1){
			ret = ret * p % MM;
		}
		p = p * p % MM;
	}
	return ret;
}

ll getInv(ll p){
	return pw(p, MM - 2);
}

ll f[MAXN << 1];

int main(){
	ll n, k;
	cin>>n>>k;
	for(int i = 1; i <= k + 3; i++)
		f[i] = pw(i , k);
	for(int i = 2; i <= k + 3; i++)
		f[i] = (f[i] + f[i-1]) % MM;
	if (n <= k + 3)
		cout<<f[n]<<endl;
	else{
		ll ans = 1;
		k++;
		for(int i = 1; i <= k + 1; i++)
			ans = ans * (n - i) % MM;
		ll now = 1;
		int flag;
		if (k & 1)
			flag = -1;
		else
			flag = 1;
		for(int i = 1; i <= k; i++)
			now = now * i % MM;
		ll Nico = 0;
	//	for(int i = 1; i <= k + 1; i++)
	//		cout<<f[i]<<' '; cout<<endl;
	//	cout<<"ans: "<<ans<<endl;
	//	cout<<"now: "<<now<<endl;
		for(int i = 1; i <= k + 1; i++){
			Nico += ans * getInv(n - i) % MM * f[i] % MM * getInv(now) * flag % MM;
			flag = -flag;
			now = now * getInv(k + 1 - i) % MM * i % MM;
		}
		cout<<(Nico % MM + MM ) % MM <<endl;
	}
	return 0;
}