#include<iostream>

using namespace std;

int n, c, a, b, ta, tb;
int l[55];
int p[55];

int main () {
	cin >> n >> c;
	for (int i=0; i<n; i++) cin >> l[i];
	for (int i=0; i<n; i++) cin >> p[i];
	for (int i=0; i<n; i++) {
		ta+=p[i];
		tb+=p[n-i-1];
		a+=max(0, l[i]-c*ta);
		b+=max(0, l[n-i-1]-c*tb);
	}
	if (a<b) {
		cout << "Radewoosh";
	} else if (a>b) {
		cout << "Limak";
	} else {
		cout << "Tie";
	}
	return 0;
}