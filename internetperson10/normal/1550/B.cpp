#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, a, b;
		cin >> n >> a >> b;
		string s;
		cin >> s;
		int k = 1;
		for(int i = 0; i < n-1; i++) {
			if(s.at(i) != s.at(i+1)) k++;
		}
		k = k/2 + 1;
		if(b < 0) cout << a*n + b*k << '\n';
		else cout << (a+b)*n << '\n';
	}
}