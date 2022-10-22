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

pair<int, int> p[N], s[N];

int n, m, a[N], b[N], okp[N], oks[N], res, ans;

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> p[i].first, p[i].second = i;
	for (int j = 0; j < m; j++) cin >> s[j].first, s[j].second = j;
	sort(p, p + n), sort(s, s + m);
	for (int x = 0; x < 32; x++) {
		// cout << "solve " << x << endl;
		for (int i = 0, j = 0; i < n && j < m;) {
			if (oks[j] || p[i].first > s[j].first) ++ j;
			else if (okp[i] || p[i].first < s[j].first) ++ i;
			else if (p[i].first == s[j].first) {
				a[s[j].second] = x, b[p[i].second] = s[j].second + 1;
				okp[i] = oks[j] = 1, ++ res, ans += x; ++ i, ++ j;
			}
			// cout << i << ' ' << j << endl;
		}
		for (int i = 0; i < m; i++)
			s[i].first = (s[i].first + 1) / 2;
	}
	cout << res << ' ' << ans << '\n';
	for (int i = 0; i < m; i++) cout << a[i] << ' '; cout << '\n';
	for (int i = 0; i < n; i++) cout << b[i] << ' '; cout << '\n';
}