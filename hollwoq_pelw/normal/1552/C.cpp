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

const int N = 202;

int n, k, x[N], y[N], used[N];

bool check(int sx, int ex, int sy, int ey) {
	if (sx > sy) swap(sx, sy);
	if (ex > ey) swap(ex, ey);
	if (sx > ex) swap(sx, ex), swap(sy, ey);
	return sx < ex && ex < sy && sy < ey;
}

void Hollwo_Pelw() {
	cin >> n >> k;
	for (int i = 1; i <= n << 1; i++) used[i] = 0;
	for (int i = 1; i <= k; i++)
		cin >> x[i] >> y[i], used[x[i]] = used[y[i]] = 1;
	vector<int> st;
	for (int i = 1; i <= n << 1; i++) {
		if (!used[i])
			st.push_back(i);
	}
	for (int i = 0, j = k + 1; i < n - k; i++, j++) {
		x[j] = st[i], y[j] = st[i + n - k];
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			if (check(x[i], x[j], y[i], y[j]))
				res ++;
	cout << res << '\n';
}