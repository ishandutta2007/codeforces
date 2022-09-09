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
int main() {
#ifdef room111
    freopen("in.txt", "r", stdin);
#else
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    int t = 1;
	//cin >> t;
    while (t--)
        solve();
    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

int n;
int p[5000];
vector<int> poses[100500];
int inf = 1000000000;

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		p[i] = abs(p[i]);
		poses[p[i]].push_back(i);
	}
	vector<int> res(n, inf);
	for (int num = 0; num <= 100000; ++num) {
		for (int i = 0; i < poses[num].size(); ++i) {
			int curId = poses[num][i];
			int lef = 0, rig = 0;
			for (int j = 0; j < curId; ++j)
				if (res[j] != inf && res[j] > -num)
					++lef;
			for (int j = curId + 1; j < n; ++j)
				if (res[j] != inf && res[j] < num)
					++rig;
			if (lef <= rig) {
				res[curId] = -num;
			}
			else {
				res[curId] = num;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (res[i] > res[j])
				++ans;
	cout << ans;

}