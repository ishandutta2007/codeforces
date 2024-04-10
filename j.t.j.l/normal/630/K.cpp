#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

ll gcd(ll p, ll q){
	return q ? gcd(q, p % q) : p;
}

ll pw(ll p, ll q){
	ll ret = 1;
	for(; q; q >>= 1){
		if (q & 1)
			ret = ret * p % MM;
		p = p * p % MM;
	}
	return ret;
}

ll getInv(ll p){
	return pw(p, MM - 2);
}

ll work(int n){
	ll cnt = 1;
	for(int i = 2; i <= 10; i++)
		if ((n >> (i - 2)) & 1)
			cnt = cnt * i / gcd(cnt, i);
	return cnt;
}

int main(){
	ll n;
	cin>>n;
	ll ans = 0;
	ans += n / 2;
	ans += n / 3;
	ans -= n / 6;
	ans += n / 5;
	ans += n / 7;
	ans -= n / 10;
	ans -= n / 14;
	ans -= n / 15;
	ans -= n / 21;
	ans -= n / 35;
	ans += n / 2 / 3 / 5;
	ans += n / 2 / 3 / 7;
	ans += n / 2 / 7 / 5;
	ans += n / 7 / 3 / 5;
	ans -= n / 2 / 3 / 5 / 7;
	cout<<n - ans<<endl;
	return 0;
	/*
	ll ans = 0;
	int tt = (1 << 9) - 1;
	for(int i = 0; i < tt; i++){
		int tp = __builtin_popcount(i);
		if (tp & 1)
			ans -= n / work(i);
		else
			ans += n / work(i);
	}
	cout<<ans<<endl;
	return 0;*/
}