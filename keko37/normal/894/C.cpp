#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 1005;

int n;
int l[MAXN];

int gcd (int a, int b) {
	if (b==0) return a;
	return gcd(b, a%b);
}

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> l[i];
	}
	sort(l, l+n);
	int val=l[n-1];
	for (int i=n-1; i>=0; i--) {
		val=gcd(val, l[i]);
	}
	if (val!=l[0]) {
		cout << -1;
		return 0;
	}
	cout << 2*n << endl;
	for (int i=0; i<n; i++) {
		cout << l[i] << " " << l[0] << " ";
	}
	return 0;
}