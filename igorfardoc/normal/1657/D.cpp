#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
#define maxc 1000000


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n, c;
	cin >> n >> c;
	vector<pair<ll, int>> d;
	{
		vector<pair<ll, int>> curr1;
		curr1.reserve(maxc * 15);
		{
			vector<ll> now(maxc + 1, 0);
			for(int i = 0; i < n; i++) {
				int c, d, h;
				cin >> c >> d >> h;
				now[c] = max(now[c], (ll)d * h);
			}
			
			for(int i = 1; i <= maxc; i++) {
				if(now[i] == 0) continue;
				for(int j = 1; i * j <= c; j++) {
					curr1.push_back({now[i] * j - 1, i * j});
				}
			}
		}
		sort(curr1.begin(), curr1.end());
		//if(n == 300000) return -1;
		d.reserve(maxc + 10);
		int nowmax = maxc + 10;
		for(int i = curr1.size() - 1; i >= 0; i--) {
			if(curr1[i].second < nowmax) {
				nowmax = curr1[i].second;
				d.push_back(curr1[i]);
			}
		}
		curr1.clear();
		curr1.shrink_to_fit();
	}
	reverse(d.begin(), d.end());
	int m;
	cin >> m;
	vector<pair<ll, int>> q(m);
	for(int i = 0; i < m; i++) {
		int d;
		ll h;
		cin >> d >> h;
		q[i].first = d * h;
		q[i].second = i;
	}
	sort(q.begin(), q.end());
	vi ans(m);
	int now1 = (int)d.size() - 1;
	int curr = maxc + 1;
	for(int i = m - 1; i >= 0; i--) {
		while(now1 > -1 && d[now1].first >= q[i].first) {
			curr = min(curr, d[now1].second);
			--now1;
		}
		ans[q[i].second] = curr;
	}
	for(const auto& el : ans) {
		if(el == maxc + 1) {
			cout << -1 << ' ';
		} else {
			cout << el << ' ';
		}
	}
}