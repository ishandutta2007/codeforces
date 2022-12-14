#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

struct Seg{
	int n;
	vector<int> tree;
	Seg(int N):n(N){
		tree.resize(n * 4, -1);
	}
	void push(int x, int l, int r, int pl, int pr, int val){
		if(pr < l || pl > r || pl > pr) return;
		if(l >= pl && r <= pr){
			tree[x] = val;
			return;
		}
		if(tree[x] != -1){
			tree[x * 2] = tree[x * 2 + 1] = tree[x];
			tree[x] = -1;
		}
		int mid = (l + r) >> 1;
		push(x * 2, l, mid, pl, pr, val), push(x * 2 + 1, mid + 1, r, pl, pr, val);
	}
	int get(int x, int l, int r, int fl, int fr){
		if(l == r) return tree[x];
		if(tree[x] != -1){
			tree[x * 2] = tree[x * 2 + 1] = tree[x];
			tree[x] = -1;
		}
		int mid = (l + r) >> 1;
		if(fl <= mid) return get(x * 2, l, mid, fl, fr);
		return get(x * 2 + 1, mid + 1, r, fl, fr);
	}
};

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, t; cin >> n >> t;

	vector<vector<int>> a(n, vector<int>(2));
	for(int i = 0; i < n; ++i){
		cin >> a[i][0] >> a[i][1];

		int x = a[i][0], y = t;
		x = (x - a[i][1] + t) % t;
		y = (y - a[i][1] + t) % t;

		a[i][0] = x, a[i][1] = y;
	}

	vector<int> d(n - 1), dpsum(n - 1);
	vector<int> srt;

	for(int i = 0; i + 1 < n; ++i){
		cin >> d[i];

		dpsum[i] = d[i];
		if(i){
			dpsum[i] += dpsum[i - 1];
		}

		a[i + 1][0] = (a[i + 1][0] - dpsum[i] % t + t) % t;
		a[i + 1][1] = (a[i + 1][1] - dpsum[i] % t + t) % t;
	}

	for(int i = 0; i < n; ++i){
		srt.push_back(a[i][0]);
		srt.push_back(a[i][1]);

		srt.push_back((a[i][0] + 1) % t);
		srt.push_back((a[i][0] + 1) % t);
		srt.push_back((a[i][0] + t - 1) % t);
		srt.push_back((a[i][0] + t - 1) % t);
	}
	sort(srt.begin(), srt.end());
	srt.erase(unique(srt.begin(), srt.end()), srt.end());

	Seg tr((int)srt.size() + 4);
	vector<int> dp(n);
	auto b = a;

	for(int i = n - 1; i >= 0; --i){
		b[i][1] = lower_bound(srt.begin(), srt.end(), b[i][1]) - srt.begin();
		b[i][0] = lower_bound(srt.begin(), srt.end(), b[i][0]) - srt.begin();

		int p = tr.get(1, 0, (int)srt.size() - 1, b[i][1], b[i][1]);

		if(p == -1){
			dp[i] = dpsum[n - 2] - (i > 0 ? dpsum[i - 1] : 0);
		}
		else{
			dp[i] = dp[p] + dpsum[p - 1] - (i > 0 ? dpsum[i - 1] : 0);

			int mstgo = a[p][1], now = a[i][1];
			dp[i] += (mstgo - now + t) % t;
		}

		if(b[i][0] <= b[i][1]) tr.push(1, 0, (int)srt.size() - 1, b[i][0], b[i][1], i);
		else{
			tr.push(1, 0, (int)srt.size() - 1, b[i][0], (int)srt.size() - 1, i);
			tr.push(1, 0, (int)srt.size() - 1, 0, b[i][1], i);
		}
	}

	int ans = (int)1e18;
	for(int i = 0; i < (int)srt.size(); ++i){
		int st = i;

		int p = tr.get(1, 0, (int)srt.size() - 1, st, st);

		if(p == -1){
			ans = dpsum[n - 2];

			break;
		}
		else{
			int nans = (p ? dpsum[p - 1] : 0) + dp[p];

			int mstgo = a[p][1], now = srt[st];
			nans += (mstgo - now + t) % t;

			ans = min(ans, nans);
		}
	}

	cout << ans << '\n';
	
	return 0;
}