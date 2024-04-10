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

int main(){
	ll a, b, c;
	cin>>a>>b>>c;
	if (a < 0){
		a = -a, b = -b, c = -c;
	}
	double del = sqrt(b * b - 4 * a * c);
	printf("%.20lf\n", (-b + del) / (2 * a));
	printf("%.20lf\n", (-b - del) / (2 * a));
	return 0;
}