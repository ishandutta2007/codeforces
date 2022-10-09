#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

set<string> good = {
	"great!",
	"cool",
	"not bad",
	"don't think so",
	"don't touch me",
};

set<string> bad = {
	"no way",
	"go die in a hole",
	"are you serious",
	"worse",
	"terrible",
	"no way",
	"don't even",
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<4; i++) {
		cout << i << '\n' << flush;
		string s;
		getline(cin, s);
		if (good.count(s)) {
			cout << "normal\n" << flush;
			return 0;
		} else if (bad.count(s)) {
			cout << "grumpy\n" << flush;
			return 0;
		}
	}

	// ako je dala 4 puta no onda je normal
	cout << "normal\n" << flush;
}