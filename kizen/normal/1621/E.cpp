#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<int> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		vector<int> imsi;
		for(int i = n - m; i < n; ++i) imsi.push_back(a[i]);
		a = imsi; n = m;
		vector<vector<int>> b(m);
		vector<vector<int>> srt(m);
		for(int i = 0; i < m; ++i){
			int sz; cin >> sz;
			b[i].resize(sz);
			srt[i] = {0, 0, i};
			for(int j = 0; j < sz; ++j){
				cin >> b[i][j];
				srt[i][0] += b[i][j];
				++srt[i][1];
			}
		}
		auto out = b;
		auto comp = [&](vector<int> x, vector<int> y){return x[0] * y[1] < x[1] * y[0];};
		sort(srt.begin(), srt.end(), comp);
		vector<int> c0(n + 1), c1(n + 1), cm1(n + 1);
		for(int i = 0; i < n; ++i){
			if(a[i] * srt[i][1] >= srt[i][0]) ++c0[i];
			if(i + 1 < n && a[i] * srt[i + 1][1] >= srt[i + 1][0]) ++c1[i];
			if(i && a[i] * srt[i - 1][1] >= srt[i - 1][0]) ++cm1[i];
			if(i) c0[i] += c0[i - 1], c1[i] += c1[i - 1], cm1[i] += cm1[i - 1];
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < srt[i][1]; ++j){
				int nsum = srt[i][0] - b[srt[i][2]][j], ncnt = srt[i][1] - 1;
				vector<int> now = {nsum, ncnt, 0};
				int lb = lower_bound(srt.begin(), srt.end(), now, comp) - srt.begin();
				if(lb == i) ++lb;
				int ans = 0;
				if(lb == i + 1){
					ans += (a[i] * ncnt >= nsum);
					ans += c0[n - 1] - c0[i];
					if(i) ans += c0[i - 1];
				}
				else if(lb > i + 1){
					if(i) ans += c0[i - 1];
					ans += c0[n - 1] - c0[lb - 1];
					ans += (a[lb - 1] * ncnt >= nsum);
					ans += c1[lb - 2];
					if(i) ans -= c1[i - 1];
				}
				else{
					if(lb - 1 >= 0) ans += c0[lb - 1];
					ans += c0[n - 1] - c0[i];
					ans += (a[lb] * ncnt >= nsum);
					ans += cm1[i] - cm1[lb];
				}
				if(ans == n) out[srt[i][2]][j] = 1;
				else out[srt[i][2]][j] = 0;
			}
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < (int)b[i].size(); ++j){
				cout << out[i][j];
			}
		}
		cout << '\n';
	}
	return 0;
}