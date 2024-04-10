#include <iostream>
#include <bitset>
#include <string>
#include <cstring>
using namespace std;
#define D(a) \
    do { cout << #a ": " << (a) << ' '; } while(false)

const int mxN = 101;

int n, a[mxN] = {};

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		n = s.length();
		int cur = 0;
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') {
				if (cur) a[cur]++;
				cur = 0;
			}
			else {
				cur++;
			}
		}
		if (cur) a[cur]++;
		int alice = 0;
		bool turn = true;
		for (int i = n; i >= 1; --i) {
			alice += i * ((a[i] + turn) / 2);
			if (a[i] % 2 == 1) turn = !turn;
		}
		cout << alice << '\n';

	}
}