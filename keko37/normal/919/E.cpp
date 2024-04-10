#include<iostream>

using namespace std;

typedef long long llint;

llint a, b, p, t, sol;

llint pot (llint bs, llint e, llint md) {
	if (e==0) return 1;
	if (e&1) {
		return bs*pot(bs, e-1, md)%md;
	} else {
		llint t=pot(bs, e/2, md);
		return t*t%md;
	}
}

int main () {
	cin >> a >> b >> p >> t;
	if (p==2) {
		cout << (t+1)/2;
		return 0;
	}
	sol+=t/(p*(p-1))*(p-1);
	t%=p*(p-1);
	for (int i=1; i<=p-1; i++) {
		llint x=i;
		llint y=b*pot(pot(a, x, p), p-2, p)%p;
		llint inv1=pot(p, p-3, p-1);
		llint inv2=pot(p-1, p-2, p);
		llint n = (x*p*inv1 + y*(p-1)*inv2) % (p*(p-1));
		if (n<=t) sol++;
	}
	cout << sol;
	return 0;
}