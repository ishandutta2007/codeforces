#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	int r = 0;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		int cur = (r + a[i]) / m;
		r = (r + a[i]) % m;
		if(i){
			cout << " ";
		}
		cout << cur;
	}
	cout << endl;
}