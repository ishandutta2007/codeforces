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

#define int long long
const int N = 2e5 + 5;

pair<int, int> cmax(pair<int, int> a, pair<int, int> b) {
	if (a.second - a.first > b.second - b.first) return a;
	if (a.second - a.first < b.second - b.first) return b;
	return min(a, b);
}

int n, k, d, a[N];

#define tm (tl + tr >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

int st[N << 2], lz[N << 2];

inline void apply(int id, int v) {
	st[id] += v, lz[id] += v;
}

inline void push(int id) {
	apply(id << 1, lz[id]), apply(id << 1 | 1, lz[id]), lz[id] = 0;
}

void upd(int l, int r, int v, int id = 1, int tl = 1, int tr = n) {
	if (l > tr || tl > r) return ;
	if (l <= tl && tr <= r) return apply(id, v);
	push(id), upd(l, r, v, left), upd(l, r, v, right);
	st[id] = min(st[id << 1], st[id << 1 | 1]);
}

int query(int l, int r, int id = 1, int tl = 1, int tr = n) {
	if (l > tr || tl > r || st[id] > k) return -1;
	if (tl == tr) return tl;
	push(id); int res = query(l, r, left);
	return res != -1 ? res : query(l, r, right);;
}

#undef tm
#undef left
#undef right

pair<int, int> solve(int l, int r) {
	map<int, int> cnt;
	pair<int, int> res = {l, l};
	vector<int> mx(1, l - 1), mn(1, l - 1);

	for (int i = l; i <= r; i++) {
		a[i] = (a[i] + 1e9) / d;
		while (cnt[a[i]])
			cnt[a[l ++]] --;
		cnt[a[i]] = 1;
		// query l => i
		upd(l, i - 1, -1);
		while (mx.size() > 1 && a[mx.back()] <= a[i]) {
			upd(mx[mx.size() - 2] + 1, mx.back(), a[i] - a[mx.back()]);
			mx.pop_back();
		}
		while (mn.size() > 1 && a[mn.back()] >= a[i]) {
			upd(mn[mn.size() - 2] + 1, mn.back(), a[mn.back()] - a[i]);
			mn.pop_back();
		}
		mx.push_back(i), mn.push_back(i);
		res = cmax(res, {query(l, i), i});
	}
	return res;
}

void Hollwo_Pelw() {
	cin >> n >> k >> d;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];

	pair<int, int> ans = {1, 1};
	if (d == 0) {
		for (int i = 1; i <= n; ) {
			int j = i;
			while (j <= n && a[i] == a[j]) j++;
			ans = cmax(ans, {i, j - 1}); i = j;
		}
	} else {
		for (int i = 1; i <= n; ) {
			int j = i;
			while (j <= n && (a[i] - a[j]) % d == 0) j++;
			ans = cmax(ans, solve(i, j - 1)); i = j;
		}
	}
	cout << ans.first << ' ' << ans.second; 
}