#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int c[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int k, v=0, u=0;
	string s;

	cin >> k >> s;
	for (char x : s) {
		c[x - '0']++;
		v += x - '0';
	}

	for (int i=0; i<10; i++) {
		while (v < k && c[i] > 0) {
			c[i]--;
			v += 9-i;
			u++;
		}
	}

	cout << u;

	
}