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

const int N = 5e5 + 5, S = 800;

int n, q, grp_cnt;
long long a[N], lz[N];

pair<long long, int> g[S + 5][S + 5];

inline int group(int id) {
	return id / S;
}

inline int tl(int id) {
	return id * S;
}

inline int tr(int id) {
	return min((id + 1) * S, n);
}

void sort_grp(int grp) {
	int cnt = 0;
	for (int i = tl(grp); i < tr(grp); i++) {
		g[grp][cnt ++] = {a[i], i};
	}
	sort(g[grp], g[grp] + cnt);
}


void __init__() {
	for (int i = 0; i < n; i += S)
		sort_grp(grp_cnt ++);
}

void upd(int l, int r, int x){
	int gl = group(l), gr = group(r - 1);
	if (gl == gr) {
		for (int i = l; i < r; i++) a[i] += x;
		sort_grp(gl);
	} else {
		for (int i = l; i < tr(gl); i++) a[i] += x;
		for (int i = tl(gr); i < r; i++) a[i] += x;
		sort_grp(gl), sort_grp(gr);
		for (int i = gl + 1; i <= gr - 1; i++) lz[i] += x;
	}
}

int find_min(int x) {
	for (int i = 0; i < grp_cnt; i++) {
		int len = tr(i) - tl(i);
		int pos = lower_bound(g[i], g[i] + len, 
					pair<long long, int>(x - lz[i], 0)) - g[i];
		if (pos < len && g[i][pos].first == x - lz[i])
			return g[i][pos].second;
	}
	return -1;
}

int find_max(int x) {
	for (int i = grp_cnt - 1; ~i; i--) {
		int len = tr(i) - tl(i);
		int pos = lower_bound(g[i], g[i] + len,
					pair<long long, int>(x - lz[i] + 1, 0)) - g[i] - 1;
		if (pos >= 0 && g[i][pos].first == x - lz[i])
			return g[i][pos].second;
	}
	return -1;
}

int query(int x) {
	int maxpos = find_max(x), minpos = find_min(x);
	if (maxpos == -1 || minpos == -1)
		return -1;
	return maxpos - minpos;
}

void Hollwo_Pelw() {
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	__init__();

	for (int _ = 0, t, l, r, x; _ < q; _++) {
		cin >> t;
		if (t == 1) 
			cin >> l >> r >> x, upd(-- l, r, x);
		else
			cin >> x,  cout << query(x) << '\n';
	}
}