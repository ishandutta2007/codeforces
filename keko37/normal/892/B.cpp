#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 1000005;

int n, sol, lim;
int l[MAXN];

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		scanf("%d", &l[i]);
	}
	lim=n;
	for (int i=n-1; i>=0; i--) {
		if (i<lim) sol++;
		lim=min(lim, i-l[i]);
	}
	cout << sol;
	return 0;
}