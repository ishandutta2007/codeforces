#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[6];
basic_string<int> b[5], c[6];

map<string, int> mp = {
	{"S", 0},
	{"M", 1},
	{"L", 2},
	{"XL", 3},
	{"XXL", 4},
	{"XXXL", 5}
};

string inv[6] = {"S", "M", "L", "XL", "XXL", "XXXL"};

string sol[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<6; i++)
		cin >> a[i];
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		int z = s.find(',');
		if (z != -1) {
			string s1 = s.substr(0, z);
			string s2 = s.substr(z+1);
			b[min(mp[s1], mp[s2])] += i;
		} else {
			c[mp[s]] += i;
		}
	}
	
	for (int i=0; i<6; i++) {
		while (a[i] && c[i].size()) {
			int x = c[i].back();
			sol[x] = inv[i];
			a[i]--;
			c[i].pop_back();
		}
	}

	for (int i=0; i<5; i++) {
		while (a[i] && b[i].size()) {
			int x = b[i].back();
			sol[x] = inv[i];
			a[i]--;
			b[i].pop_back();
		}
		while (a[i+1] && b[i].size()) {
			int x = b[i].back();
			sol[x] = inv[i+1];
			a[i+1]--;
			b[i].pop_back();
		}
	}

	int ok = 1;
	for (int i=0; i<n; i++)
		if (sol[i].empty())
			ok = 0;
	if (!ok)
		cout << "NO\n";
	else {
		cout << "YES\n";
		for (int i=0; i<n; i++)
			cout << sol[i] << '\n';
	}
}