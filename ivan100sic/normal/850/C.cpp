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

map<int, int> num;

int find_num(int mask) {
	if (num.find(mask) != num.end()) {
		return num[mask];
	}

	set<int> mx;
	for (int i=1; i<=30; i++) {
		int iznad = mask >> i;
		int ispod = mask & ((1 << i) - 1);

		int numask = ispod | iznad;

		if (iznad == 0) {
			continue;
		}

		mx.insert(find_num(numask));
	}

	int j = 0;
	while (mx.count(j)) {
		j++;
	}

	return num[mask] = j;
}


const int SITO_MAX = 40000;

int f[SITO_MAX+1];
vector<int> prosti;

struct sito {
	sito() {
		for (int i=2; i<=SITO_MAX; i++) {
			if (f[i] == 0) {
				f[i] = i;
				prosti.push_back(i);
			}
			int j = 0;
			while (j < (int)prosti.size()) {
				if (prosti[j] > f[i]) {
					break;
				}
				int x = i * prosti[j];
				if (x > SITO_MAX) {
					break;
				}
				f[x] = prosti[j];
				j++;
			}
		}
	}
} sito_obj_983431;

map<int, int> faktorisi(int x) {
	map<int, int> fs;

	for (int p : prosti) {
		if (x % p == 0) {
			fs[p] = 0;
			while (x % p == 0) {
				x /= p;
				fs[p]++;
			}
		}
	}

	if (x > 1) {
		fs[x] = 1;
	}

	return fs;
}

void zez() {
	num[1] = 0;

	for (int i=1; i<1<<16; i++) {
		find_num(i);
	}

	int j = 1;
	for (int i=1; i<(1<<16); i = 2*i+1) {
		cerr << i << ' ' << j << ' ' << find_num(i) << '\n';
		j++;
	}
}

void z2() {
	// 463887029	272513423	645802606	453620266	784212349
	int x = 463887029;
	find_num(x);
	cerr << num.size() << '\n';
}

map<int, int> gg;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// zez();
	z2();

	int n;
	cin >> n;

	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		auto fs = faktorisi(x);

		for (auto p : fs) {
			gg[p.first] |= 1 << p.second;
		}
	}

	// izracunaj nimber za svaku masku u gg i xoruj

	int xr = 0;

	for (auto p : gg) {
		xr ^= find_num(p.second);
	}

	cout << (xr ? "Mojtaba" : "Arpa");


}