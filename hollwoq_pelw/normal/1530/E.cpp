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
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

string s;
int cnt[26];

int count_large() {
	int c = 0;
	for (int i = 0; i < 26; i++)
		c += cnt[i] > 0;
	return c;
}

int find_one() {
	for (int i = 0; i < 26; i++)
		if (cnt[i] == 1) return i;
	return -1;
}

void Hollwo_Pelw() {
	memset(cnt, 0, sizeof cnt);
	cin >> s;
	for (auto c : s) cnt[c - 'a'] ++;
	
	if (count_large() == 1)
		return cout << s << '\n', (void) 0;
	// result = 0
	int p = find_one();
	if (p != -1) {
		cout << (char) (p + 'a'), cnt[p] --;
		for (int i = 0; i < 26; i++)
			cout << string(cnt[i], (char) (i + 'a'));
		return cout << '\n', (void) 0;
	}

	for (int i = 0, j, k; i < 26; i++) if (cnt[i]) {
		if (cnt[i] <= s.size() / 2 + 1) {
			// start with ii
			cout << string(2, (char) (i + 'a')), cnt[i] -= 2;
			for (j = i + 1; j < 26; j++)
				while (cnt[j] --) {
					cout << (char) (j + 'a');
					if (cnt[i] > 0)
						cout << (char) (i + 'a'), cnt[i] --;
				}
			cout << '\n';
			return; 
		}
		// start with ij
		if (count_large() == 2) {
			// ijjjjjjiiiiii...
			cout << (char) (i + 'a'), cnt[i] --;
			for (j = i + 1; j < 26; j++) if (cnt[j]) break ;
			cout << string(cnt[j], (char) (j + 'a'));
			cout << string(cnt[i], (char) (i + 'a'));
			cout << '\n';
			return ;
		}

		cout << (char) (i + 'a'), cnt[i] --;
		// must have oth
		for (j = i + 1; j < 26; j++) if (cnt[j]) {
			cout << (char) (j + 'a'), cnt[j] --; break ;
		}
		for (k = j + 1; k < 26; k++) if (cnt[k]) {
			// ijiiiiiik...
			cout << string(cnt[i], (char) (i + 'a'));
			cout << (char) (k + 'a'), cnt[k] --;
			for (; j < 26; j++)
				cout << string(cnt[j], (char) (j + 'a'));
			cout << '\n';
			return ;
		}
	}
}