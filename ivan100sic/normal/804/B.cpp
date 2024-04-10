#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

const int MOD = 1'000'000'007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int b = 0, jumps = 0;
	string s;
	cin >> s;
	int n = s.size();
	for (int i=n-1; i>=0; i--) {
		if (s[i] == 'b') {
			b++;
		} else {
			jumps = (jumps + b) % MOD;
			b = (b + b) % MOD;
		}
	}
	cout << jumps;
}