#include <set>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int Y[50005], N;
int X[50005];

void izvrsi(int lim) {
	multiset<int> s, bad;
	map<int, int> c;

	for (int i = 1; i <= N; i++) {
		s.insert(Y[i]);
		c[Y[i]]++;

		if (c[Y[i]] > 1 || Y[i] > lim) {
			bad.insert(Y[i]);
		}
	}

	while (1) {
		if (bad.empty()) break;

		auto it = bad.begin();
		int x = *it;
		bad.erase(it);

		// ukloni x, dodaj x/2
		s.erase(s.find(x));
		c[x]--;

		x /= 2;
		s.insert(x);
		c[x]++;

		if (c[x] > 1 || x > lim) {
			bad.insert(x);
		}
	}

	int m = 0;
	for (auto p : s) {
		X[++m] = p;
	}
}

int probaj() {
	multiset<int> s, bad;
	map<int, int> c;
	int sol = 1e9;

	for (int i = 1; i <= N; i++) {
		s.insert(Y[i]);
		c[Y[i]]++;
		sol = max(sol, Y[i]);

		if (c[Y[i]] > 1) {
			bad.insert(Y[i]);
		}
	}

	while (1) {
		if (c[1] > 1) break;

		int x;

		if (bad.empty()) {

			auto it = s.rbegin();
			x = *it;
			s.erase(s.find(x));
			sol = min(sol, x);
			c[x]--;

		} else {
			auto it = bad.begin();
			x = *it;
			bad.erase(it);
			s.erase(s.find(x));
			c[x]--;
		}

		x /= 2;
		s.insert(x);
		c[x]++;

		if (c[x] > 1) {
			bad.insert(x);
		}
	}

	return sol;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> Y[i];
	}
	
	if (N==1){
		cout << 1 << endl;
		return 0;
	}

	int l = probaj();
	izvrsi(l);

	for (int i = 1; i <= N; i++) {
		cout << X[i] << ' ';
	}
	cout << endl;

	cin >> N;

	return 0;
}