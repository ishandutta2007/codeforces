#include <bits/stdc++.h>
using namespace std;

int main() {
	for (int i=0; i<8; i++) {
		string s;
		cin >> s;
		if (s != "WBWBWBWB" && s != "BWBWBWBW") {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}