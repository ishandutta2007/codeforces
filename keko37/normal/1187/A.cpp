#include<bits/stdc++.h>

using namespace std;

int t;

int main () {
	cin >> t;
	for (int i=0; i<t; i++) {
		int n, s, t;
		cin >> n >> s >> t;
		int z = s + t - n;
		int x = s - z;
		int y = t - z;
		cout << max(x, y) + 1 << endl;
	}
	return 0;
}