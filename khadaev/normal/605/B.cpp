#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<pair<int, int>> in, out;
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (b == 0) out.push_back({a, i});
		else in.push_back({a, i});
	}
	sort(in.begin(), in.end());
	sort(out.begin(), out.end());
	vector<pair<int, int>> ans(m);
	int ix = 0;
	for (int i = 0; i < n - 1 && ix < out.size(); ++i)
		for (int j = 0; j < i && ix < out.size(); ++j) {
			if (out[ix].first < in[i].first) {
				printf("-1\n");
				return 0;
			} else {
				ans[out[ix].second] = {i + 1, j + 1};
				//cout << out[ix].second << ' ' << i << ' ' << j << '\n';	
				++ix;
			}	
		}
	for (int i = 0; i < n - 1; ++i) {
		ans[in[i].second] = {0, i + 1};
		//cout << in[i].second << ' ' << 0 << ' ' << i << '\n';	
	}
	//cout << '\n';
	for (auto p : ans) printf("%d %d\n", p.first + 1, p.second + 1);
		
}