#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

char opposite(char x) {
	switch(x) {
		case 'R': return 'L';
		case 'U': return 'D';
		case 'D': return 'U';
		case 'L': return 'R';
	}
	return x;
}

int main() {
	/*
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	*/
	string s;

	map<char, bool> used;

	int n, c = 0;
	cin >> n >> s;

	for (char x : s) {
		if (used[opposite(x)]) {
			used.clear();
			c++;
		}
		used[x] = true;
	}

	if (used.size()) {
		c++;
	}
	cout << c;
}