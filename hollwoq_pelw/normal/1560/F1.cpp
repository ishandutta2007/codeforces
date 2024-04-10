#include <bits/stdc++.h>
using namespace std;

void FAST_IO(string filein = "", string fileout = ""){
	if (fopen(filein.c_str(), "r")){
		freopen(filein.c_str(), "r", stdin);
		freopen(fileout.c_str(), "w", stdout);
	}
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Why_Are_You_So_Orz();

signed main(){
#ifndef ONLINE_JUDGE
	FAST_IO("input.inp", "output.out");
	auto start = chrono::steady_clock::now();
#else
	FAST_IO("mike4235orz.inp", "mike4235orz.out");
#endif
	int testcases = 1;
	cin >> testcases;
	for (int test = 1; test <= testcases; test++)
		Why_Are_You_So_Orz();
#ifndef ONLINE_JUDGE
	auto end = chrono::steady_clock::now();
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

#define int long long

string n;
int k;

void Why_Are_You_So_Orz() {
	cin >> n >> k;
	while (1) {
		set<char> s;
		for (auto c : n)
			s.insert(c);
		if (s.size() <= k)
			return cout << n << '\n', (void) 0;
		s.clear();
		for (int i = 0; ; i++) {
			s.insert(n[i]);
			if (s.size() > k) {
				while (n[i] == '9')
					i --;
				n[i] ++;
				for (int j = i + 1; j < n.size(); j++)
					n[j] = '0';
				break ;
			}
		}
	}
}