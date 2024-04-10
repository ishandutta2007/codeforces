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

int n, s;
 
int sum(int v) {
	int r = 0;
	while (v)
		r += v % 10, v /= 10;
	return r;
}
 
void Hollwo_Pelw() {
	cin >> s >> n;
	if (sum(s) >= n) {
		int p = 1;
		while (n > 1) {
			if (s % (p * 10) != 0)
				cout << p << ' ', s -= p, -- n;
			else
				p *= 10;
		}
		cout << s << "\n";
	} else {
		vector<int> d, res;
		while (s)
			d.push_back(s % 10), s /= 10;
		for (auto v : d) n -= v;
		
		while (n >= 9) {
			for (int i = 1, p = 1; i < d.size(); i++, p *= 10)
				if (d[i]) {
					d[i] --, n -= 9;
					d[i - 1] += 10;
					break;
				}
		}
 
		if (n) {
			for (int i = 1, p = 1; i < d.size(); i++, p *= 10)
				if (d[i]) {
					d[i] --;
					d[i - 1] += n;
					res.push_back((10 - n) * p);
					break ;
				}
		}
 
		for (int i = 0, p = 1; i < d.size(); i ++, p *= 10)
			while (d[i] --) res.push_back(p);
		for (auto v : res) cout << v << ' ';
		cout << '\n';
	}
}