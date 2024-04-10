#include<iostream>

using namespace std;

int n, ok, a, b;
string s;

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> s >> a >> b;
		if (a>=2400 && b>a) ok=1;
	}
	if (ok==1) cout << "YES"; else cout << "NO";
	return 0;
}