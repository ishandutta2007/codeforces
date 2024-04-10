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
			ret = ret * p;
		p = p * p;
	}
	return ret;
}

double pw2(double p, ll q){
	double ret = 1;
	for(; q; q >>= 1){
		if (q & 1)
			ret = ret * p;
		p = p * p;
	}
	return ret;
}

ll getInv(ll p){
	return pw(p, MM - 2);
}

int main(){
	ll n, t;
	cin>>n;
	cout<<pw(2, n + 1) - 2<<endl;
	return 0;
}