#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int a, b, c;
	cin >> a >> b >> c;
	if(a - b - c > 0){
		cout << "+";
		return 0;
	}
	if(b - a - c > 0){
		cout << "-";
		return 0;
	}
	if(c == 0 && a == b){
		cout << 0;
		return 0;
	}
	cout << "?";
}