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

string s, p;

int c[256];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n >> s >> p;

	// maximum da dam
	for (char x : p) {
		c[x]++;
	}

	int f = 0;
	for (char x : s) {
		for (char y=x+1; y<='9'; y++) {
			if (c[y]) {
				c[y]--;
				f++;
				break;
			}
		}
	}

	memset(c, 0, sizeof(c));
	
	for (char x : p) {
		c[x]++;
	}

	int g = n;
	for (char x : s) {
		for (char y=x; y<='9'; y++) {
			if (c[y]) {
				c[y]--;
				g--;
				break;
			}
		}
	}

	cout << g << '\n';
	cout << f << '\n';
}