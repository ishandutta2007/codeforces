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
	FAST_IO(".inp", ".out");
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

int n, a[N], b[N];

bool check() {
	for (int i = 1; i < n; i++)
		if (b[i] != b[i - 1]) return 0;
	if (b[0])
		return cout << "NO", 1;
	cout << "YES\n";
	for (int i = 0; i < n; i++)
		cout << 1 << ' ';
	return 1;
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> b[i];
	if (check()) return ;
	int v = *max_element(b, b + n);
	for (int id = 0; id < n; id++) {
		if (b[(id + 1) % n] == v && b[(id + 1) % n] > b[id]) {
			id = (id + 1) % n, v = b[id] * 100;

			a[id] = b[id];
			for (int i = 1; i < n; i++) {
				int j = (id - i + n) % n;
				a[j] = (v += b[j]);
			}

			cout << "YES\n";
			for (int i = 0; i < n; i++)
				cout << a[i] << ' ';

			return ;
		}
	}
}