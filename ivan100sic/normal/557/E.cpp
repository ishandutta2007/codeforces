#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
string s;
short d[5005][5005];
bool p[5005][5005];

struct stvar {
	short l, r;
	bool operator< (const stvar& o) const {
		short w = d[l][o.l];
		if (w < r-l && w < o.r-o.l) {
			return s[l+w] < s[o.l+w];
		} else {
			return r-l < o.r-o.l;
		}
	}
};

vector<stvar> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s >> k;
	k--;
	n = s.size();
	s += ' ';

	for (int i=n-1; i>=0; i--) {
		for (int j=n-1; j>=0; j--) {
			d[i][j] = d[i+1][j+1] + 1;
			if (s[i] != s[j])
				d[i][j] = 0;
		}
	}

	v.reserve(n*(n+1) / 2);

	for (short l=n-1; l>=0; l--) {
		for (short r=l; r<n; r++) {
			if (r-l+1 <= 4) {
				p[l][r] = s[l] == s[r];				
			} else {
				p[l][r] = s[l] == s[r] && p[l+2][r-2];
			}
			if (p[l][r])
				v.push_back({l, (short)(r+1)});
		}
	}

	nth_element(v.begin(), v.begin()+k, v.end());
	cout << s.substr(v[k].l, v[k].r-v[k].l) << '\n';

}