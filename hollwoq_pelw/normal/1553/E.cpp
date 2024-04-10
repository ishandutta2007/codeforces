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

int n, m, p[N], q[N], cnt_shift[N];

bool check(int sh) {
	for (int i = 1; i <= n; i++) {
		q[i] = p[(i - 1 + sh) % n + 1];
		// cout << q[i] << " \n"[i == n];
	}
	int used = 0;
	for (int i = 1; i <= n; i++) if (q[i] != i) {
		while (q[i] != i) {
			int j = q[i];
			swap(q[j], q[i]);
			++ used;
		}
	}
	// cout << sh << ' ' << used << "\n\n";
	return used <= m;
}

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cnt_shift[i] = 0;
	for (int i = 1; i <= n; i++)
		cin >> p[i], cnt_shift[(i - p[i] + n) % n] ++;
	int ntc = n - 2 * m; // must keep 
	vector<int> res;
	for (int i = 0; i < n; i++)
		if (cnt_shift[i] >= ntc) {
			if (check(i)) 
				res.push_back(i);
		}
	cout << res.size() << ' ';
	for (auto v : res) cout << v << ' ';
	cout << '\n';
}