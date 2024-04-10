#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int cnt[10], t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	int n = s.size();
	for (char x : s)
		cnt[x-'0']++;
	while (t + (int)to_string(t).size() != n)
		t++;
	cerr << t << '\n';
	for (char x : to_string(t))
		cnt[x-'0']--;
	string p;
	cin >> p;
	for (char x : p)
		cnt[x-'0']--;

	if (accumulate(cnt, cnt+10, 0) == 0) {
		cout << p << '\n';
		return 0;
	}

	string sol = "a", tmp;

	// scenario jedan: stavljamo t na pocetak
	if (p[0] != '0') {
		tmp = p;
		for (int i=0; i<10; i++)
			tmp += string(cnt[i], i+'0');
		sol = min(sol, tmp);
	}

	// scenario dva: uzimamo neku nenula brojku i stavljamo na pocetak,
	// ostali idu lex
	int j = -1;
	for (int i=1; i<10; i++) {
		if (cnt[i]) {
			j = i;
			cnt[i]--;
			break;
		}
	}

	if (j != -1) {
		tmp = string(1, j+'0');

		vector<string> pa = {p};
		for (int i=0; i<10; i++)
			while (cnt[i]--)
				pa.push_back(string(1, i+'0'));

		sort(pa.begin(), pa.end(), [&](const string& a, const string& b) {
			return a+b < b+a;
		});

		for (string s : pa)
			tmp += s;


		sol = min(sol, tmp);
	}

	cout << sol << '\n';
}