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

int g[26], tmp[26], cnt[26];

int myfind(string s) {
	int j = s.size();
	while (g[s[j - 1] - 'a'])
		j--;
	return s[j - 1] - 'a';
}

string p[30];

bool check(string s, string t, char v) {
	string x = "";
	for (char c : s)
		if (c != v) x += c;
	return x == t;
}

void Why_Are_You_So_Orz() {
	string t, res = ""; cin >> t;
	for (int i = 0; i < 26; i++)
		cnt[i] = g[i] = 0;
	for (int i = 0; i < t.size(); i++)
		cnt[t[i] - 'a'] ++;
	int turn = 0, tot = 0;
	for (int i = 0; i < 26; i++)
		turn += cnt[i] > 0;
	
	for (int i = turn; i; i--) {
		// cout << t << '\n';
		int cur = myfind(t), x = cnt[cur];
		if (x % i != 0)
			return cout << "-1\n", (void) 0;
		g[cur] = x / i;
		tot += x / i;
		res += (char) (cur + 'a');
		
		p[i - 1] = t.substr(t.size() - tot);

		for (int j = 0; j < 26; j++)
			tmp[j] = g[j];

		for (int j = 0; j < tot; j++) {
			if (t.empty())
				return cout << "-1\n", (void) 0;
			tmp[t.back() - 'a'] --;
			t.pop_back();
		}

		for (int j = 0; j < 26; j++)
			if (tmp[j] != 0)
				return cout << "-1\n", (void) 0;

	}
	reverse(res.begin(), res.end());

	{
		for (int i = 1; i < turn; i++) {
			if (!check(p[i - 1], p[i], res[i - 1]))
				return cout << "-1\n", (void) 0;
		}
	}

	cout << p[0] << ' ' << res << '\n';
}