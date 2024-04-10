#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<string, int> sz = {
	{"S", 0},
	{"M", 1},
	{"L", 2},
	{"XL", 3},
	{"XXL", 4},
};

string st[5] = {"S", "M", "L", "XL", "XXL"};
int a[5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<5; i++)
		cin >> a[i];

	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		int x = sz[s];
		int bi = -1, bv = 123123123;
		for (int i=0; i<5; i++) {
			if (!a[i])
				continue;
			int v = 2*abs(i-x) + (i < x);
			if (v < bv) {
				bv = v;
				bi = i;
			}
		}
		a[bi]--;
		cout << st[bi] << '\n';
	}
}