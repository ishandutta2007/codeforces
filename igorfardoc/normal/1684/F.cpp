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
		int n, m;
		cin >> n >> m;
		vi a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<pair<int, int>> otr(m);
		for(int i = 0; i < m; i++) {
			cin >> otr[i].first >> otr[i].second;
			--otr[i].first;
			--otr[i].second;
		}
		sort(otr.begin(), otr.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {if(a.first != b.first) return a.first < b.first; return a.second > b.second;});
		{
			int maxr = -1;
			vector<pair<int, int>> otr1;
			for(int i = 0; i < m; i++) {
				if(otr[i].second <= maxr) continue;
				maxr = otr[i].second;
				otr1.push_back(otr[i]);
			}
			swap(otr1, otr);
		}
		m = otr.size();
		{
			set<int> all;
			for(int i = 0; i < n; i++) {
				all.insert(a[i]);
			}
			map<int, int> d;
			int now = 0;
			for(const auto& el : all) {
				d[el] = now++;
			}
			for(int i = 0; i < n; i++) {
				a[i] = d[a[i]];
			}
		}
		auto otr1 = otr;
		for(int i = 0; i < m; i++) {
			swap(otr1[i].first, otr1[i].second);
		}
		vvi pos(n);
		for(int i = 0; i < n; i++) {
			pos[a[i]].push_back(i);
		}
		vector<array<int, 4>> nxt;
		for(int c = 0; c < n; c++) {
			int fir = -1;
			int sec = -1;
			int firid;
			for(int i = 0; i < (int)pos[c].size() - 1; i++) {
				int id1 = lower_bound(otr.begin(), otr.end(), (pair<int, int>){pos[c][i] + 1, -1}) - otr.begin() - 1;
				if(id1 != -1 && otr[id1].second >= pos[c][i + 1]) {
					fir = i;
					firid = id1;
					break;
				}
			}
			for(int i = (int)pos[c].size() - 1; i > 0; i--) {
				int id1 = lower_bound(otr1.begin(), otr1.end(), (pair<int, int>){pos[c][i], -1}) - otr1.begin();
				if(id1 != otr1.size() && otr1[id1].second <= pos[c][i - 1]) {
					sec = i;
					break;
				}
			}
			if(fir == -1) continue;
			if(otr[firid].second >= pos[c][sec]) {
				nxt.push_back({pos[c][fir], pos[c][sec - 1], pos[c][fir + 1], pos[c][sec]});
			} else {
				nxt.push_back({pos[c][fir + 1], pos[c][sec - 1], pos[c][fir + 1], pos[c][sec - 1]});
			}
		}
		sort(nxt.begin(), nxt.end());
		vector<array<int, 5>> nxt1;
		for(int i = 0; i < nxt.size(); i++) {
			nxt1.push_back({nxt[i][0], nxt[i][1], nxt[i][2], nxt[i][3], i});
		}
		sort(nxt1.begin(), nxt1.end(), [&](const array<int, 5>& a, const array<int, 5>& b) {return a[3] > b[3];});
		vi where(nxt.size());
		for(int i = 0; i < nxt.size(); i++) {
			where[nxt1[i][4]] = i;
		}
		int ans = 0;
		for(int i = 0; i < nxt1.size(); i++) {
			ans = max(ans, nxt1[0][3] - nxt1[i][2] + 1);
		}
		multiset<int> r;
		for(int i = 0; i < nxt.size(); i++) {
			r.insert(nxt[i][1]);
		}
		vector<bool> used(nxt.size(), false);
		int l1 = n;
		int r1 = -1;
		for(int i = 0; i < nxt.size(); i++) {
			if(used[i]) continue;
			ans = min(ans, max(r1, *(r.rbegin())) - min(l1, nxt[i][0]) + 1);
			int now = where[i];
			while(now < nxt.size() && !used[nxt1[now][4]]) {
				l1 = min(l1, nxt1[now][2]);
				r1 = max(r1, nxt1[now][3]);
				r.erase(r.find(nxt1[now][1]));
				used[nxt1[now][4]] = true;
				++now;
			}
		}
		cout << ans << '\n';
	}

}