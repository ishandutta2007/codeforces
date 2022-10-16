#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second


const int N = 100100;
int n, k, m, b;

vector <pair<int, int> > v;
int ans[N], aib[N];

string op[N];
int val[N], q, a[N];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> q;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		v.push_back({abs(a[i]), i});
	}

	sort(v.begin(), v.end());

	for(int i = 1; i <= q; i++)
		cin >> op[i] >> val[i];

	int swap = 0;
	while(q) {
		int lim = abs(val[q]);
		if(op[q] == ">" && val[q] > 0) lim++;
		if(op[q] == "<" && val[q] < 0) lim++;

		while(!v.empty() && v.back().st >= lim) {

			if(op[q] == ">")
				ans[v.back().nd] = -v.back().st;
			else 
				ans[v.back().nd] = v.back().st;
			if(swap % 2) ans[v.back().nd] = -ans[v.back().nd];
			v.pop_back();
		}
		if(op[q] == ">" && val[q] < 0 || op[q] == "<" && val[q] > 0)
			swap++;
		q--;
	}

	while(!v.empty()) {
		if(swap % 2)
			ans[v.back().nd] = -a[v.back().nd];
		else 
			ans[v.back().nd] = a[v.back().nd];
		v.pop_back();
	}

	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';

}