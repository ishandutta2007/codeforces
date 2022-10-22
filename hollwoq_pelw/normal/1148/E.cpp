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

const int N = 3e5 + 5;

int n, t[N];
set<pair<int, int>> s;

struct opt {
	int i, j, d;
	opt () {}
	opt (int _i, int _j, int _d)
		: i(_i), j(_j), d(_d) {}
};

vector<opt> opts;

pair<int, int> do_opt(pair<int, int> l, pair<int, int> r, int mid) {
	int dist = min(mid - l.first, r.first - mid);
	if (dist) opts.emplace_back(l.second, r.second, dist);
	l.first += dist, r.first -= dist;
	return l.first == mid ? r : l;
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, x; i <= n; i++) 
		cin >> x, s.emplace(x, i);
	for (int i = 1; i <= n; i++) cin >> t[i];
	sort(t + 1, t + n + 1);
	for (int i = 1; i < n; i++) {
		auto x = *s.begin();
		s.erase(x);
		if (x.first > t[i])
			return cout << "NO", (void) 0;
		auto it = s.lower_bound({t[i], 0});
		if (it == s.end())
			return cout << "NO", (void) 0;
		auto y = *it;
		s.erase(y);
		s.insert(do_opt(x, y, t[i]));
	}
	if (s.begin() -> first != t[n])
		return cout << "NO", (void) 0;
	cout << "YES\n" << opts.size() << '\n';
	for (auto ijd : opts)
		cout << ijd.i << ' ' << ijd.j << ' ' << ijd.d << '\n';
}