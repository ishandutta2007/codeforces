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

const int N = 1e5 + 5;

int nxt[N], cur[N], a[N], n, l1, l2, res;

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	memset(cur, 0x7f, sizeof cur);
	for (int i = n; i >= 0; i--)
		nxt[i] = cur[a[i]], cur[a[i]] = i;

	for (int i = 1; i <= n; i++) {
		if (a[i] == a[l1] || a[i] == a[l2]) {
			(a[i] == a[l1] ? l1 = i : l2 = i);
			continue ;
		}
		(nxt[l1] > nxt[l2] ? l1 = i : l2 = i), ++ res;
	}
	cout << res;
}