#include<bits/stdc++.h>
#define pb push_back
using namespace std;
using vi = vector<int>;
int n, c = 0;
vi x, y;
vector<pair<int, int>> b;
int main() {
	cin >> n;
	for(int t, i = 0; i < n; i++) {
		cin >> t, t -= i;
		auto it = upper_bound(x.begin(), x.end(), t);
		int p = it-x.begin();
		if(it==x.end()) x.pb(t);
		else *it = t;
		++t;
		it = upper_bound(y.begin(), y.end(), t);
		if(it==y.end()) y.pb(t);
		else *it = t;
		if(i) {
			if(y.size() < b.back().first)
				y.pb(b.back().second);
			else
				y[b.back().first] = min(y[b.back().first], b.back().second);
		}
		b.pb({p, t-1});
	}
	cout << max(0, n - (int)max(x.size(), y.size()) - 1);
}