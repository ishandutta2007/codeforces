#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<int> v;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		v.resize(2*n);
		for(int i= 0; i < 2*n; i++) cin >> v[i];
		sort(v.begin(), v.end());
		for(int i = 0; i < n; i++) {
			cout << v[i] << ' ' << v[2*n-i-1] << ' ';
		}
		cout << '\n';
		vector<int>().swap(v);
	}
}