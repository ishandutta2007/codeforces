#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
//#define FILENAME "1dembedding"
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
void solve();
void precalc();
int main() {
#ifdef room111
    freopen("in.txt", "r", stdin);
#else
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    int t = 1;
	precalc();
	cin >> t;
    while (t--)
        solve();
    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

#define int li

vector<int> composition[60];
void precalc() {
	for (int i = 0; i <= 6; ++i)
		for (int j = 0; i + j <= 6; ++j) {
			int k = 6 - i - j;
			composition[j * 4 + k * 7].push_back(i);
			composition[j * 4 + k * 7].push_back(j);
			composition[j * 4 + k * 7].push_back(k);
		}
}

pair<int, int> pred[20][6];

void solve() {
	int n;
	cin >> n;
	vector<int> now;
	int k = n;
	for (int i = 0; i < 19; ++i) {
		now.push_back(k % 10);
		k /= 10;
	}
	for (int i = 0; i < 20; ++i)
		for (int j = 0; j < 6; ++j)
			pred[i][j] = mp(-1, -1);
	for (int i = 0; i < 60; ++i)
		if (composition[i].size() == 3 && (i % 10) == now[0]) {
			//cout << i << ' ' << composition[i][0] << ' ' << composition[i][1] << ' ' << composition[i][2] << "\n";
			pred[0][i / 10] = mp(0, i);
		}
	for (int i = 0; i < 18; ++i) 
		for (int carry = 0; carry < 6; ++carry) {
			if (pred[i][carry].first == -1)
				continue;
			for (int nex = 0; nex < 60; ++nex)
				if (composition[nex].size() == 3) {
					int nexSum = nex + carry;
					if (nexSum % 10 != now[i + 1])
						continue;
					pred[i + 1][nexSum / 10] = mp(carry, nex);
				}
		}
	if (pred[18][0].first == -1) {
		cout << "-1\n";
		return;
	}
	vector <int> res[6];
	int cur = 18;
	int sum = pred[18][0].second;
	int carry = 0;
	do {
		
		for (int i = 0; i < composition[sum][0]; ++i)
			res[i].push_back(0);
		for (int i = composition[sum][0]; i < composition[sum][0] + composition[sum][1]; ++i)
			res[i].push_back(4);
		for (int i = composition[sum][0] + composition[sum][1]; i < 6; ++i)
			res[i].push_back(7);

		sum = pred[cur][carry].second;
		carry = pred[cur][carry].first;
		--cur;
	}
	while (cur >= 0);

	for (int i = 0; i < composition[sum][0]; ++i)
			res[i].push_back(0);
		for (int i = composition[sum][0]; i < composition[sum][0] + composition[sum][1]; ++i)
			res[i].push_back(4);
		for (int i = composition[sum][0] + composition[sum][1]; i < 6; ++i)
			res[i].push_back(7);

	for (int i = 0; i < 6; ++i) {
		int cur = 0;
		for (int j = 0; j < res[i].size(); ++j)
			cur = cur * 10 + res[i][j];
		cout << cur << ' ';
	}
	cout << "\n";

}