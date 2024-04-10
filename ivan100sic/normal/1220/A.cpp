#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	string s;
	cin >> n >> s;
	int kec = count(s.begin(), s.end(), 'n');
	int nul = count(s.begin(), s.end(), 'z');
	while (kec--)
		cout << "1 ";
	while (nul--)
		cout << "0 ";
}