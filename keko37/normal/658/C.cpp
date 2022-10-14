#include<iostream>
#include<cstdio>

using namespace std;

int n, d, h, cnt=1;

int main () {
	cin >> n >> d >> h;
	if (d>2*h || d+1>n) {
		cout << -1;
		return 0;
	}
	if (d==h) {
		if (h==1) {
			if (n>2) cout << -1; else cout << "1 2";
			return 0;
		}
		for (int i=1; i<=h; i++) cout << i << " " << i+1 << endl;
		for (int i=h+2; i<=n; i++) cout << 2 << " " << i << endl;
		return 0;
	}
	for (int i=1; i<=h; i++) {
		cout << i << " " << i+1 << endl;
	}
	cout << "1 " << h+2 << endl;
	for (int i=h+2; i<=d; i++) {
		cout << i << " " << i+1 << endl;
	}
	for (int i=d+2; i<=n; i++) {
		cout << "1 " << i << endl;
	}
	return 0;
}