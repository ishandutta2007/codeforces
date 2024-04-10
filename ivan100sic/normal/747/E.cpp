#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int pos;
string s;

vector<string> o[1000005];
int dmax = 0;

void parse(int depth) {

	dmax = max(dmax, depth);

	string p;
	while (s[pos] != ',') {
		p += s[pos++];
	}

	pos++;

	int num = 0;
	while (s[pos] != ',') {
		num = 10*num + s[pos++] - '0';
	}

	pos++;

	o[depth].push_back(move(p));

	for (int i=0; i<num; i++) {
		parse(depth+1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s;
	s += ',';

	while (pos < s.size()) {
		parse(0);
	}
	

	cout << dmax + 1 << '\n';

	for (int i=0; i<=dmax; i++) {
		for (string q : o[i]) {
			cout << q << ' ';
		}
		cout << '\n';
	}

}