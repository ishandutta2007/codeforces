#include<iostream>

using namespace std;

int n, a, b, x;
int sol, pola;

int main () {
	cin >> n >> a >> b;
	for (int i=0; i<n; i++) {
		cin >> x;
		if (x==1) {
			if (a>0) {
				a--;
			} else if (b>0) {
				b--;
				pola++;
			} else if (pola>0) {
				pola--;
			} else {
				sol++;
			}
		} else {
			if (b>0) {
				b--;
			} else {
				sol+=2;
			}
		}
	}
	cout << sol;
	return 0;
}