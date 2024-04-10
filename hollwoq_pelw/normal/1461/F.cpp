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
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 1e5 + 5, BIG = 1e7;

int n, a[N], type[3]; // 0 -> +, 1 -> -, 2 -> *

char op[N];

int p[N], dp[N], tr[N];

void solve(int l, int r) {
	while (l < r && a[l] == 1) l ++;
	while (l < r && a[r] == 1) r --;
	if (l >= r) return ;
	fill(op + l, op + r, '*');
	p[l - 1] = 1, dp[l - 1] = 0;
	for (int i = l; i <= r; i++)
		if ((p[i] = p[i - 1] * a[i]) > BIG) return ;
	vector<int> v; // not one (size < log)
	for (int i = l; i <= r; i++) {
		dp[i] = dp[i - 1] + a[i], tr[i] = i - 1;
		if (a[i] != 1) {
			for (int j : v) if (dp[i] < dp[j] + p[i] / p[j])
				dp[i] = dp[j] + p[i] / p[j], tr[i] = j;
			v.push_back(i - 1);
		}
	}
	for (int i = r; i >= l; i = tr[i]) 
		if (i < r) op[i] = '+';
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	string s; cin >> s;
	for (auto o : s) {
		if (o == '+') type[0] = 1;
		if (o == '-') type[1] = 1;
		if (o == '*') type[2] = 1;
	}
	if (type[0] && type[1]) type[1] = 0;
	if (type[0] + type[1] + type[2] == 1) {
		char c = type[0] ? '+' : type[1] ? '-' : '*';
		for (int i = 1; i < n; i++)
			cout << a[i] << c;
		cout << a[n];
		return ;
	}
	if (type[1]) { // *-
		if (!a[1]) {
			for (int i = 1; i < n; i++)
				cout << a[i] << '*';
			cout << a[n];
		} else {
			cout << a[1];
			for (int i = 2, ok = 0; i <= n; i++) {
				if (ok || a[i])
					cout << '*' << a[i];
				else
					cout << '-' << a[i], ok = 1;
			}
		}
		return ;
	}
	// *+
	fill(op + 1, op + n, '+');
	for (int i = 1, j = 1; i <= n + 1; i++) 
		if (!a[i]) solve(j, i - 1), j = i + 1;
	for (int i = 1; i < n; i++)
		cout << a[i] << op[i];
	cout << a[n];
}