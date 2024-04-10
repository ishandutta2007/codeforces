#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 300005;
const int MOD = 1000000007;

typedef long long llint;

llint n, a, b, sol;
llint l[MAXN];

llint add (llint x, llint y) {
	if (x+y>=MOD) return x+y-MOD; else return x+y;
}

llint sub (llint x, llint y) {
	if (x-y<0) return x-y+MOD; else return x-y;
}

llint mul (llint x, llint y) {
	return (x*y)%MOD;
}

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		int inp;
		scanf("%d", &inp);
		l[i]=inp;
	}
	sort(l, l+n);
	llint mid, pot=1;
	if (n%2==0) {
		mid=n/2+1;
		for (int i=1; i<n; i++) {
			if (i+1<=mid) {
				a=add(a, l[i-1]);
				b=add(b, l[n-i]);
			} else {
				a=sub(a, l[n-i]);
				b=sub(b, l[i-1]);
			}
			sol=add(sol, mul(pot, sub(b, a)));
			pot=mul(pot, 2);
		}
	} else {
		mid=(n+1)/2;
		for (int i=1; i<n; i++) {
			if (i+1<=mid) {
				a=add(a, l[i-1]);
				b=add(b, l[n-i]);
			} else if (i+1==mid+1) {
			} else {
				a=sub(a, l[n-i]);
				b=sub(b, l[i-1]);
			}
			sol=add(sol, mul(pot, sub(b, a)));
			pot=mul(pot, 2);
		}
	}
	cout << sol;
	return 0;
}