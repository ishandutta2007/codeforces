#include<iostream>

using namespace std;

int n, m;
string s;

int main () {
	cin >> n >> m >> s;
	for (int i=0; i<m; i++) {
		int l, r;
		char c1, c2;
		cin >> l >> r >> c1 >> c2;
		for (int j=l-1; j<=r-1; j++) {
			if (s[j]==c1) s[j]=c2;
		}
	}
	cout << s;
	return 0;
}