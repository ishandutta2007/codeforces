#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string a, b;
basic_string<int> p, q, r, s;
//               00,10,01,11

template<class... T>
int nneg(T... x) {
	return ((x >= 0) && ...);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> a >> b;
	for (int i=0; i<n; i++) {
		if (a[i] == b[i]) {
			if (a[i] == '0')
				p += i;
			else
				s += i;
		}
		else if (a[i] > b[i])
			q += i;
		else
			r += i;
	}

	int p = ::p.size();
	int q = ::q.size();
	int r = ::r.size();
	int s = ::s.size();

	for (int p1=0; p1<=p; p1++) {
		for (int q1=0; q1<=q; q1++) {
			int p2 = p-p1;
			int q2 = q-q1;
			int r1 = n-2*p1-q1-r-s;
			int r2 = r-r1;
			int s1 = p1+r+s-n/2;
			int s2 = s-s1;

			if (nneg(p1, p2, q1, q2, r1, r2, s1, s2)) {
				basic_string<int> sol;
				sol += ::p.substr(0, p1);
				sol += ::q.substr(0, q1);
				sol += ::r.substr(0, r1);
				sol += ::s.substr(0, s1);
				for (int x : sol)
					cout << x+1 << ' ';
				cout << '\n';
				return 0;
			}
		}
	}
	cout << "-1\n";
}