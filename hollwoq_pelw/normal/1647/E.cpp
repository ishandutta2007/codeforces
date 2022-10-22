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
	if (fopen("hollwo_pelw.inp", "r")){
		freopen("hollwo_pelw.inp", "r", stdin);
		freopen("hollwo_pelw.out", "w", stdout);
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

const int N = 1e5 + 5;

int n, p[N], a[N], cnt[N], go[30][N], b[N], vis[N];
vector<int> pos[N], vpos[N];

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++) cnt[p[i]] ++;
	int move = (*max_element(a + 1, a + n + 1) - n) / count(cnt + 1, cnt + n + 1, 0);

	copy(p + 1, p + n + 1, go[0] + 1);
	for (int i = 1; i < 30; i++)
		for (int j = 1; j <= n; j++)
			go[i][j] = go[i - 1][go[i - 1][j]];

	for (int i = n; i; i--) {
		int f = i;
		for (int j = 30; j --; )
			if (move >> j & 1) f = go[j][f];
		pos[f].push_back(i);
	}

	set<int> st;
	for (int i = 1; i <= n; i++) if (a[i] <= n) {
		b[pos[i].back()] = a[i], vis[a[i]] = 1;

		pos[i].pop_back();
		vpos[a[i]] = pos[i];
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) 
			b[*st.begin()] = i, st.erase(st.begin());

		for (int j : vpos[i]) st.insert(j);
	}

	for (int i = 1; i <= n; i++)
		cout << b[i] << ' ';
}