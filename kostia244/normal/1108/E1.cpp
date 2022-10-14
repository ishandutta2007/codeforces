#include <bits/stdc++.h>
using namespace std;

int n, m, mdiff;
vector<int> a, b, c;
vector<pair<int, int>> seg;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	a.resize(n);
	seg.resize(m);
	for(auto& i : a)
		cin >> i;
	for(auto& i : seg)
		cin >> i.first >> i.second, i.second--, i.first--;
		
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int d = i, e = j;
			b.clear();
			int diff = (a[e] - a[d]);
			for(int k = 0; k < seg.size(); k++) {
				if(seg[k].first <= d && d <= seg[k].second)
					if(seg[k].first > e || e > seg[k].second)
						diff++, b.push_back(k);
			}
			if(diff > mdiff) {
				mdiff = diff;
				c = b;
			}
		}
	}
	cout << mdiff << "\n";
	cout << c.size() << "\n";
	for(auto& i : c)
		cout << (i + 1) << " ";
}