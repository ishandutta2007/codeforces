#include <bits/stdc++.h>
using namespace std;

int target(string s, string kraj) {
	// nadji poslednji koji je jednak kraj[1], zameni
	int j = -1, n = s.size();
	for (int i=0; i<n; i++)
		if (s[i] == kraj[1]) {
			j = i;
		}
	if (j == -1)
		return 123123123;

	int k = 0;

	while (j != n-1) {
		if (j == 0 && s[1] == '0') {
			int z = 1;
			while (s[z] == '0')
				z++;

			swap(s[1], s[z]); k += z-1;
			swap(s[0], s[1]); k += 1;
			j = 1;
		} else {
			swap(s[j], s[j+1]);
			j++;
			k++;
		}
	}

	j = -1;
	for (int i=0; i<n-1; i++)
		if (s[i] == kraj[0]) {
			j = i;
		}

	if (j == -1)
		return 123123123;

	while (j != n-2) {
		if (j == 0 && s[1] == '0') {
			int z = 1;
			while (s[z] == '0')
				z++;

			swap(s[1], s[z]); k += z-1;
			swap(s[0], s[1]); k += 1;
			j = 1;
		} else {
			swap(s[j], s[j+1]);
			j++;
			k++;
		}
	}

	return k;
}

void resi2(string s) {
	if (s == "25" || s == "50" || s == "75")
		cout << 0;
	else if (s == "52" || s == "57")
		cout << 1;
	else
		cout << -1;

	exit(0);
}

void rek(string& s, int dub, int& sol) {
	if (s[0] == '0')
		return;
	if (dub > 6)
		return;

	if (stoi(s) % 25 == 0)
		sol = min(sol, dub);

	for (int i=0; i<2; i++) {
		int j = i+1;
		swap(s[i], s[j]);
		rek(s, dub+1, sol);
		swap(s[i], s[j]);
	}

	return;

}

void resi3(string s) {
	int sol = 123123123;
	rek(s, 0, sol);
	if (sol == 123123123)
		sol = -1;
	cout << sol;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;

	if (s.size() == 1)
		return cout << -1, 0;

	if (s.size() == 2) {
		resi2(s);
	}

	if (s.size() == 3) {
		resi3(s);
	}

	cerr << "tesko\n";

	int a1 = target(s, "25");
	int a2 = target(s, "50");
	int a3 = target(s, "75");
	int a4 = target(s, "00");

	int a5 = target(s, "52") + 1;
	int a6 = target(s, "05") + 1;
	int a7 = target(s, "57") + 1;

	int a = min({a1, a2, a3, a4, a5, a6, a7});
	if (a == 123123123)
		a = -1;
	cout << a;
}