#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k;
	cin >> k;
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	int n = (1 << k) - 1;
	v.resize(2*n+2);
	for(int i = n; i < 2*n+2; i++) {
		v[i] = 1;
	}
	for(int i = n-1; i >= 0; i--) {
		if(s.at(i) == '0') {
			v[i] = v[2*i+2];
		}
		else if(s.at(i) == '1') {
			v[i] = v[2*i+1];
		}
		else {
			v[i] = v[2*i+1] + v[2*i+2];
		}
	}
	int q;
	cin >> q;
	while(q--) {
		int i;
		char c;
		cin >> i >> c;
		i = n - i;
		s.at(i) = c;
		while(true) {
			if(s.at(i) == '0') {
				v[i] = v[2*i+2];
			}
			else if(s.at(i) == '1') {
				v[i] = v[2*i+1];
			}
			else {
				v[i] = v[2*i+1] + v[2*i+2];
			}
			if(i == 0) break;
			i = (i-1)/2;
		}
		cout << v[0] << '\n';
	}
}