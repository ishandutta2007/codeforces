/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
	if (fopen(filein.c_str(), "r")){
		freopen(filein.c_str(), "r", stdin);
		freopen(fileout.c_str(), "w", stdout);
#ifdef hollwo_pelw_local
		freopen(fileerr.c_str(), "w", stderr);
#endif
	}
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
#ifdef hollwo_pelw_local
	FAST_IO("input.inp", "output.out", "error.err");
	auto start = chrono::steady_clock::now();
#else
	FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
#endif
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
	return 0;
}

#define int long long

int n, m;
vector<int> a[10];

struct node {
	vector<int> p; int tot;
	node (int n = 10) {
		p.assign(n, 0), tot = 0;
	}
};

bool operator < (const node &a, const node &o) {
	if (a.tot != o.tot)
		return a.tot < o.tot;
	return a.p < o.p;
}

set<node> ban, used;
priority_queue<node> pq;

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 0, c; i < n; i++) {
		cin >> c, a[i].resize(c);
		for (auto &v : a[i]) cin >> v;
	}
	for (cin >> m; m --; ) {
		node cur;
		for (int i = 0; i < n; i++)
			cin >> cur.p[i], cur.p[i] --;
		for (int i = 0; i < n; i++)
			cur.tot += a[i][cur.p[i]];
		ban.insert(cur);
		// cout << cur.tot << '\n';
	}
	node cur;
	for (int i = 0; i < n; i++) 
		cur.p[i] = a[i].size() - 1, cur.tot += a[i].back();
	pq.push(cur);
	while (!pq.empty()) {
		node cur = pq.top(); pq.pop();

		// cout << "cur = ";
		// for (int i = 0; i < n; i++)
		// 	cout << cur.p[i] + 1 << ' ';
		// cout << "\n";

		if (!ban.count(cur)) {
			for (int i = 0; i < n; i++)
				cout << cur.p[i] + 1 << ' ';
			return ;
		}

		// cout << "to next\n";

		for (int i = 0; i < n; i++) if (cur.p[i]) {
			node nxt = cur; nxt.p[i] --;
			nxt.tot += a[i][nxt.p[i]] - a[i][cur.p[i]];
			// for (int i = 0; i < n; i++)
			// 	cout << nxt.p[i] + 1 << ' ';
			// cout << '\n';
			if (!used.count(nxt))
				pq.push(nxt), used.insert(nxt);
		}
	}
}