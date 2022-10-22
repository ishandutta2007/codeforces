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

const int N = 5e3 + 5;

int n, a[N], p[N << 1], res[N], cnt[N];

vector<int> sqr_pr, allp;

void Hollwo_Pelw() {
	fill(p + 2, p + (N << 1), 1);
	for (int i = 2; i < N << 1; i++) if (p[i]) {
		for (int j = i * i; j < N << 1; j += i) 
			p[j] = 0;
		sqr_pr.push_back(i * i);
	}

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i]) {
			for (auto v : sqr_pr)
				while (a[i] % v == 0) a[i] /= v;
			allp.push_back(a[i]);
		}
	}

	sort(allp.begin(), allp.end());
	allp.erase(unique(allp.begin(), allp.end()), allp.end());
	for (int i = 1; i <= n; i++) if (a[i])
		a[i] = lower_bound(allp.begin(), allp.end(), a[i]) - allp.begin() + 1;
	int sz = allp.size(), val = 0;

#define do_add(v) val += v && cnt[v] == 0, cnt[v] ++

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++)
			do_add(a[j]), res[max(val, 1)] ++;
		val = 0, memset(cnt, 0, sizeof cnt);
	}

	for (int i = 1; i <= n; i++)
		cout << res[i] << ' ';
}