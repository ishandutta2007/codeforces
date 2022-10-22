#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

void Hollwo_Pelw();

signed main(){
#ifndef hollwo_pelw_local
	if (fopen("E.inp", "r")){
		freopen("E.inp", "r", stdin);
		freopen("E.out", "w", stdout);
	}
#else
	auto start = chrono::steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

#define pts pair<int, int> 

inline pts rev(const pts &o) { return {o.second, o.first}; }

inline void move(set<pts> &oldx, set<pts> &oldy, set<pts> &newx, set<pts> &newy, pts vx) {
	oldx.erase(vx), newx.insert(vx);
	pts vy = rev(vx);
	oldy.erase(vy), newy.insert(vy);
}

int solve(set<pts> &stx, set<pts> &sty) {
	if (stx.size() == 1) return 1;

	auto pre_x = stx.begin(); auto suf_x = stx.rbegin();
	auto pre_y = sty.begin(); auto suf_y = sty.rbegin();

	set<pts> ntx, nty;

	do {
		{
			int cur_x = pre_x -> first; pre_x ++;
			if (abs(pre_x -> first - cur_x) > 1) {
				
				while (stx.begin() -> first <= cur_x)
					move(stx, sty, ntx, nty, *stx.begin());

				return solve(stx, sty) + solve(ntx, nty);
			}
		}
		{
			int cur_x = suf_x -> first; suf_x ++;
			if (abs(suf_x -> first - cur_x) > 1) {
				
				while (stx.rbegin() -> first >= cur_x)
					move(stx, sty, ntx, nty, *stx.rbegin());

				return solve(stx, sty) + solve(ntx, nty);
			}
		}
		{
			int cur_y = pre_y -> first; pre_y ++;
			if (abs(pre_y -> first - cur_y) > 1) {
				
				while (sty.begin() -> first <= cur_y)
					move(sty, stx, nty, ntx, *sty.begin());

				return solve(stx, sty) + solve(ntx, nty);
			}
		}
		{
			int cur_y = suf_y -> first; suf_y ++;
			if (abs(suf_y -> first - cur_y) > 1) {
				
				while (sty.rbegin() -> first >= cur_y)
					move(sty, stx, nty, ntx, *sty.rbegin());

				return solve(stx, sty) + solve(ntx, nty);
			}
		}
	} while (*pre_x < *suf_x);

	return 1;
}

void Hollwo_Pelw(){
	set<pts> stX, stY;
	int n; cin >> n;
	for (int x, y; n --; ) {
		cin >> x >> y;
		stX.emplace(x, y);
		stY.emplace(y, x);
	}
	cout << solve(stX, stY);
}