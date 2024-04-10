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
			ret = ret * p % 100000;
		p = p * p % 100000;
	}
	return ret;
}

ll getInv(ll p){
	return pw(p, MM - 2);
}

int main(){
	char s[100];
	scanf("%s", s);
	for(int i = 0; i < 5; i++)
		s[i] -= '0';
	ll n = 0;
	n = n * 10 + s[0];
	n = n * 10 + s[2];
	n = n * 10 + s[4];
	n = n * 10 + s[3];
	n = n * 10 + s[1];
	printf("%05lld\n", pw(n, 5));
//	cout<<pw(n, 5)<<endl;
	return 0;
}