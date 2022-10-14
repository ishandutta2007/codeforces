#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
using namespace std;

long long n, m, s, e;
vector<long long> a, ans, add;
vector<pi> al;
map<int, vector<int>> seg;
map<int, vector<int>> seg2;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	a.resize(n);
	for (auto& i : a)
		cin >> i;
	if(m == 0) {
		cout << ((*max_element(a.begin(), a.end())) - (*min_element(a.begin(), a.end())));
		cout << "\n" << "0";
		return 0;
	}
	while (m--) {
		cin >> s >> e;
		seg[--e].push_back(--s);
		seg2[s].push_back(e);
		al.pb(mp(s, e));
	}


	ans.resize(n, -1000000000);
	add.resize(n, 0);
	long long mn = a[0];
	for (int i = 0; i < n; i++) {
		ans[i] = max(ans[i], a[i] - mn);
		for (auto& l : seg[i])
			for (int tl = l; tl <= i; tl++)
				--add[tl], mn = min(mn, a[tl] + add[tl]);
		mn = min(mn, a[i] + add[i]);
	}

	long long id = 0;
	for(int i= 1; i < n; i++)
		if(ans[id] < ans[i])
			id  = i;
	int val = ans[id];
	ans.assign(n, -1000000000);
	add.assign(n, 0);
	mn = a[n - 1];
	for (int i = n - 1; i >= 0; i--) {
		ans[i] = max(ans[i], a[i] - mn);
		for (auto& r : seg2[i])
			for (int t = i; t <= r; t++)
				add[t]--, mn = min(mn, a[t] + add[t]);
		mn = min(mn, a[i] + add[i]);
	}

	int id2 = 0;
	for(int i= 1; i < n; i++)
		if(ans[id2] < ans[i])
			id2  = i;
	cout << max(ans[id2], (long long)val) << "\n";
	if(ans[id2] > val)
		id = id2;
	vector<int> r;
	for(int i = 0;i < al.size(); i++) {
		if(al[i].first > id || al[i].second < id)
			r.push_back(i + 1);
	}
	cout << r.size() << "\n";
	for(auto& i : r)
		cout << i << " ";


}