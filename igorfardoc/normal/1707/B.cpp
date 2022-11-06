#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vi a;
		int am = 0;
		for(int i = 0; i < n; i++) {
			int ch;
			cin >> ch;
			if(ch > 0) {
				a.push_back(ch);
			} else {
				++am;
			}
		}
		while(a.size() + am > 1) {
			vi b;
			if(am > 0 && !a.empty()) b.push_back(a[0]);
			if(am > 0) --am;
			for(int i = 1; i < (int)a.size(); i++) {
				int ch = a[i] - a[i - 1];
				if(ch > 0) {
					b.push_back(ch);
				} else {
					++am;
				}
			}
			sort(b.begin(), b.end());
			swap(a, b);
		}
		if(am > 0) {
			cout << 0 << '\n';
		} else {
			cout << a[0] << '\n';
		}
	}
}