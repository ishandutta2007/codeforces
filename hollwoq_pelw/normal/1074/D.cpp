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
    // cin >> testcases;
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

const int N = 4e5 + 5;

int par[N], xr[N], sz[N], cnt;

map<int, int> mp;

int comp(int x) {
	if (mp.count(x))
		return mp[x];
	return mp[x] = cnt ++;
}

pair<int, int> find(int u) {
	if (par[u] == u) 
		return {u, 0};
	pair<int, int> v = find(par[u]);
	return {par[u] = v.first, xr[u] ^= v.second};
}

void merge(int u, int v, int x) {
	pair<int, int> pu = find(u), pv = find(v);
	if ((u = pu.first) == (v = pv.first))
		return ;
	x ^= pu.second ^ pv.second;
	if (sz[v] > sz[u]) swap(u, v);

	par[v] = u, xr[v] = x;

	sz[u] += sz[v];
}

void Hollwo_Pelw() {
	for (int i = 1; i < N; i++) 
		par[i] = i, sz[i] = 1;
	int q, lst = 0; cin >> q;
	for (int _ = 0, type, l, r, x; _ < q; _++) {
		cin >> type >> l >> r, l ^= lst, r ^= lst; 
		if (l > r) swap(l, r); l = comp(l), r = comp(++ r);

		if (type == 1) {
			cin >> x, x ^= lst;
			merge(l, r, x);
		} else {
			pair<int, int> pl = find(l), pr = find(r);
			if (pl.first != pr.first)
				cout << "-1\n", lst = 1;
			else
				cout << (lst = pl.second ^ pr.second) << "\n";
		}
	}
}