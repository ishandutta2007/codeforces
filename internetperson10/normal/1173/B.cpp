#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	cout << (n+2)/2 << '\n';
	for(int a=0; a<n; a++) {
		int k = (a+2)/2;
		cout << k << ' ';
		if(a%2==0) cout << k << '\n';
		else cout << k+1 << '\n';
	}
}