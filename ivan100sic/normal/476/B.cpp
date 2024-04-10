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

	string s, p;
	cin >> s >> p;
	int skor = 0;
	for (char x : s)
		if (x == '+')
			skor++;
		else
			skor--;

	map<int, double> prob = {{0, 1.0}};
	for (char x : p) {
		map<int, double> tmp;
		if (x == '+') {
			for (auto e : prob)
				tmp[e.first + 1] += e.second;
		} else if (x == '-') {
			for (auto e : prob)
				tmp[e.first - 1] += e.second;
		} else {
			for (auto e : prob) {
				tmp[e.first - 1] += e.second / 2;
				tmp[e.first + 1] += e.second / 2;
			}
		}
		swap(prob, tmp);
	}

	cout.precision(20); cout << fixed;
	cout << prob[skor] << '\n';
}