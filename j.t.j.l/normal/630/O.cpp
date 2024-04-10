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
	double px, py, vx,vy,a,b,c,d;
	cin>>px>>py>>vx>>vy>>a>>b>>c>>d;
	double l = sqrt(vx *vx + vy*vy);
	a /= 2.0; c /= 2.0;
	printf("%.20lf %.20lf\n", px + vx / l * b, py + vy / l * b);//
	printf("%.20lf %.20lf\n", px - vy / l * a, py + vx / l * a);//
	printf("%.20lf %.20lf\n", px - vy / l * c, py + vx / l * c);//
	printf("%.20lf %.20lf\n", px - vy / l * c - vx / l * d, py + vx / l * c - vy / l * d);
	printf("%.20lf %.20lf\n", px + vy / l * c - vx / l * d, py - vx / l * c - vy / l * d);
	printf("%.20lf %.20lf\n", px + vy / l * c, py - vx / l * c);//
	printf("%.20lf %.20lf\n", px + vy / l * a, py - vx / l * a);//
	return 0;
}