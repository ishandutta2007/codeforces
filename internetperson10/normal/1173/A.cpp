#include <bits/stdc++.h>

using namespace std;

int main() {
	int u, d, q;
	cin >> u >> d >> q;
	int ans = u-d;
	if(ans>0) {
		if(ans-q>0) cout << "+";
		else cout << "?";
	}
	else if(ans<0) {
		if(ans+q<0) cout << "-";
		else cout << "?";
	}
	else {
		if(q==0) cout << "0";
		else cout << "?";
	}
}