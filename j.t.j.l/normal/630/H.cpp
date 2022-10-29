#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e2 + 10;
const int MM = 1e9 + 7;

ll f[MAXN][10];

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
	int n;
	cin>>n;
	f[0][0] = 1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= 5; j++)
			if (f[i][j]){
				f[i+1][j] += f[i][j];
				f[i+1][j+1] += f[i][j] * (n - j);
			}
	cout<<f[n][5]<<endl;
	return 0;
}