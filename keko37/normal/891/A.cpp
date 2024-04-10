#include<iostream>

using namespace std;

const int MAXN = 2005;

int n, cnt, sol;
int l[MAXN];

int gcd (int a, int b) {
	if (b==0) return a;
	return gcd(b, a%b);
}

int main () {
	cin >> n;
	sol=n+1;
	for (int i=0; i<n; i++) {
		cin >> l[i];
		if (l[i]==1) cnt++;
	}
	if (cnt) {
		cout << n-cnt;
		return 0;
	}
	for (int i=0; i<n; i++) {
		int val=l[i];
		for (int j=i; j<n; j++) {
			val=gcd(val, l[j]);
			if (val==1) sol=min(sol, j-i);
		}
	}
	if (sol==n+1) cout << -1; else cout << sol+n-1;
	return 0;
}