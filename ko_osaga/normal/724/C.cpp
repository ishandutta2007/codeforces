#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long lint;

lint n, m, q;
lint gcd;
int pp, qq;

lint g(lint x, lint y){
	return y ? g(y, x%y) : x;
}

lint mul_inv(lint a, lint b)
{
	lint b0 = b, t, q;
	lint x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

lint chinese_remainder(lint *n, lint *a, int len)
{
	lint p, i, prod = 1, sum = 0;

	for (i = 0; i < len; i++) prod *= n[i];

	for (i = 0; i < len; i++) {
		p = prod / n[i];
		sum += a[i] * mul_inv(p, n[i]) * p;
	}

	return sum % prod;
}

lint solve2(int x, int y){
	lint n[3] = {pp, qq};
	lint a[3] = {x, y};
	return chinese_remainder(n, a, 2);
	assert(0);
}

lint solve(int x, int y){
	if(x % gcd != y % gcd) return 1e18;
	return 1ll * solve2(x / gcd, y / gcd) * gcd + x % gcd;
}

int main(){
	cin >> n >> m >> q;
	gcd = g(2*n, 2*m);
	pp = 2 * n;
	qq = 2 * m;
	pp /= gcd;
	qq /= gcd;
	while(q--){
		int x, y;
		scanf("%d %d",&x,&y);
		lint ret = min({solve(x, y), solve(2*n-x, y), solve(2*n-x, 2*m-y), solve(x, 2*m-y)});
		if(ret > 1e17) puts("-1");
		else printf("%lld\n", ret);
	}
}