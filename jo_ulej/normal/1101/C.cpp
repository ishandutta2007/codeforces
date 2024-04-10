#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9 + 7;
const bool BEGIN = false;
const bool END   = true;

const int MAX_N = 100011;

void solve()
{
	int n;
	vector<pair<int, pair<bool, int>>> events;
	vector<int> ans;

	cin >> n;
	ans.resize(n);

	for(int i = 0; i < n; ++i)
	{
		int l, r;
		cin >> l >> r;

		events.emplace_back(l, make_pair(BEGIN, i));
		events.emplace_back(r, make_pair(END, i));
	}

	sort(events.begin(), events.end());

	/*int mx = 0, cls = 0;

	for(auto& evt: events)
		if(evt.first == mx)
			evt.first = cls;
		else
			mx = evt.first, ++cls;*/

	int cur_color = 1;
	int cnt = 0;
	int color_cnt[] = {0, 0, 0};

	for(auto evt: events)
	{
		if(evt.second.first == BEGIN)
			++cnt;
		else
			--cnt;	

		//color[evt.first] = cur_color;
		++color_cnt[cur_color];
		ans[evt.second.second] = cur_color;
	
		if(cnt == 0)
			cur_color = 3 - cur_color;
	}

	if(color_cnt[1] == 0 || color_cnt[2] == 0)
	{
		cout << "-1" << endl;

		return;
	}

	for(auto el: ans)
		cout << el << " ";

	cout << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	int t;
	cin >> t;

	for(; t > 0; --t)
		solve();

	return 0;
}