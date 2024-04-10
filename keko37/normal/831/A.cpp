#include<iostream>

using namespace std;

int n, x, y, tip=1, sol=1;
int l[105];

int main () {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> l[i];
		int novi;
		if (l[i]>l[i-1]) {
			novi=1;
		} else if (l[i]==l[i-1]) {
			novi=0;
		} else {
			novi=-1;
		}
		if (tip<novi) {
			sol=0;
		}
		tip=novi;
	}
	if (sol) cout << "YES"; else cout << "NO";
	return 0;
}