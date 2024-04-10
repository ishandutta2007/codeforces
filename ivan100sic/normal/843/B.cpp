#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
#include <ctime>
using namespace std;

int n, start, x;

map<int, pair<int, int>> cache;

pair<int, int> ask(int x) {
	auto& p = cache[x];
	if (p.second != 0) {
		return p;
	}

	cout << "? " << x << '\n' << flush;
	cin >> p.first >> p.second;
	return p;
}

vector<int> kand;

void ans(int x) {
	cout << "! " << x << '\n' << flush;
	exit(0);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> start >> x;

	srand(time(nullptr));

	for (int i=1; i<=n; i++) {
		kand.push_back(i);
	}

	random_shuffle(kand.begin(), kand.end());

	int pos = -1;
	int val = -1;

	for (int i=0; i<min(1337, n); i++) {
		int y = kand[i];
		auto p = ask(y);
		if (p.first <= x) {
			if (pos == -1 || p.first > val) {
				val = p.first;
				pos = y;
			}
		}
	}

	if (pos == -1) {
		pos = start;
	}

	while (pos != -1) {
		auto p = ask(pos);
		if (p.first >= x) {
			ans(p.first);
		} else {
			pos = p.second;
		}
	}

	ans(-1);

}