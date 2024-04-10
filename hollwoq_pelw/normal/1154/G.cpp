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

const int N = 1e6 + 5, M = 1e7 + 5;

int vis[M], id1, id2, n, a[N];
long long ans = 1ll * M * M;

void check(long long v, int i, int j) {
	if (v < ans)
		ans = v, id1 = i, id2 = j;
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (vis[a[i]])
			check(a[i], vis[a[i]], i);
		vis[a[i]] = i;
	}
	for (int i = 1; i < M && i < ans; i++) {
		for (int j = i, v = 0; j < M; j += i) if (vis[j]) {
			if (!v) {
				v = j;
			}
			else {
				check(1ll * v / i * j, vis[v], vis[j]);
				break ;
			}
		}
	}
	if (id1 > id2)
		swap(id1, id2);
	cout << id1 << ' ' << id2;
}