/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include<bits/stdc++.h>
using namespace std;

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
    cin >> testcases;
    for (int test = 1; test <= testcases; test++){
        // cout << "Case #" << test << ": ";
        Hollwo_Pelw();
    }
#ifdef hollwo_pelw_local
    auto end = chrono::steady_clock::now();
    cout << endl;
    cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
    return 0;
}

const int N = 3e5 + 5;

vector<int> sor[N], kes[N];
set<pair<int, int>> st;
int tin[N], tout[N], timer, ans, n;

void dfs_kes(int u) {
	tin[u] = ++ timer;
	for (auto v : kes[u])
		dfs_kes(v);
	tout[u] = timer;
}

bool is_ancestor(int u, int v) {
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}

void dfs_sor(int u, int now = 0) {
	auto it = st.lower_bound({tin[u], 0});
	if (it != st.end())
		now += !is_ancestor(u, it -> second);
	// cout << "solve " << u << endl;
	// cout << it -> second << endl;
	if (it != st.begin()) {
		auto nit = prev(it);
		now += !is_ancestor(nit -> second, u);
		if (it != st.end())
			now -= !is_ancestor(nit -> second, it -> second);
		// cout << nit -> second << endl;
	}
	// cout << "=> " << now << endl;
	ans = max(ans, now);

	st.insert({tin[u], u});

	for (auto v : sor[u])
		dfs_sor(v, now);

	st.erase({tin[u], u});
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++) 
		sor[i].clear(), kes[i].clear();
	for (int i = 2, p; i <= n; i++)
		cin >> p, sor[p].push_back(i);
	for (int i = 2, p; i <= n; i++)
		cin >> p, kes[p].push_back(i);
	
	timer = ans = 0;
	dfs_kes(1);
	dfs_sor(1);
	cout << ans + 1 << '\n';
}