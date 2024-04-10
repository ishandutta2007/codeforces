#include<iostream>

using namespace std;

int n, a, b, mini, naj, x, y, l1, l2;

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a >> b;
		if (i==0) {
			mini=b;
			x=a;
		} else {
			mini=min(mini, b);
			x=max(x, a);
		}
	}
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a >> b;
		if (i==0) {
			naj=a;
			y=b;
		} else {
			naj=max(naj, a);
			y=min(y, b);
		}
	}
	l1=max(naj-mini, 0);
	l2=max(x-y, 0);
	cout << max(l1, l2);
	return 0;
}