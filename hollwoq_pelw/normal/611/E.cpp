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

const int N = 2e5 + 5;

int n, v[3];

multiset<int> s;

inline bool del(int x) {
	auto it = s.upper_bound(x);
	return it != s.begin() ? s.erase(-- it), 1 : 0;
}

inline int get() {
	return s.empty() ? 0 : *s.rbegin();
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 0, x; i < 3; i++)
		cin >> v[i];
	sort(v, v + 3);
	for (int i = 1, x; i <= n; i++)
		cin >> x, s.insert(x);

	if (get() > v[0] + v[1] + v[2]) 
		return cout << -1, (void) 0;

	int ans = 0;

	while (get() > v[1] + v[2]) 
		ans ++, del(v[0] + v[1] + v[2]);
	while (get() > v[0] + v[2])
		ans ++, del(v[1] + v[2]), del(v[0]);
	while (get() > v[0] + v[1] && get() > v[2])
		ans ++, del(v[0] + v[2]), del(v[1]);
	while (get() > v[2] && v[0] + v[1] > v[2])
		ans ++, del(v[0] + v[1]), del(v[2]);
	while (get() && del(v[1]))
		ans ++, del(v[0]), del(v[2]);
	while (get())
		ans ++, del(v[0] + v[1]), del(v[2]);
	cout << ans;
}