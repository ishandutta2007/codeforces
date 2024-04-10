#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<int> v = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<string> w = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string a, b;
	cin >> a >> b;
	int x = find(w.begin(), w.end(), a) - w.begin();
	int y = find(w.begin(), w.end(), b) - w.begin();

	for (int i=0; i<12; i++) {
		int r = (y-x - v[i]) % 7;
		if (r == 0)
			return cout << "YES", 0;
	}
	cout << "NO";
}