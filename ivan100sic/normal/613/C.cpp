#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[26], z;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		z += a[i];
	}
	for (int g=z; g>0; g--) {
		int c = 0;
		for (int i=0; i<26; i++) {
			if (a[i] % g)
				c = 2;
			else
				c += a[i] / g % 2;
		}
		if (c <= 1) {
			string s;
			for (int r=0; r<2; r++)
				for (int i=0; i<26; i++)
					if (a[i] / g % 2 == r) {
						string t(a[i]/g, 'a'+i);
						s.insert(s.begin()+s.size()/2, t.begin(), t.end());
					}
			cout << g*(1+(c==0 && z%2==0)) << '\n';
			for (int i=0; i<g; i++)
				cout << s;
			cout << '\n';
			return 0;
		}
	}

	string s;
	for (int i=0; i<26; i++)
		s += string(a[i], 'a'+i);
	cout << "0\n" << s << '\n';
}