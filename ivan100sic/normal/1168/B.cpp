#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T>
bool ima(T s) {
	int n = s.size();
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			int k = 2*j-i;
			if (k >= n)
				break;
			if (s[i] == s[j] && s[j] == s[k])
				return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	ll z = 0;
	int n = s.size();
	for (int l=0; l<n; l++) {
		int r = l;
		while (r <= n && !ima(s.substr(l, r-l)))
			r++;
		z += n-r+1;
	}
	cout << z << '\n';
}