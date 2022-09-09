#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <map>
#include <cassert>
#include <memory.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();
//void precalc();
#define FILENAME "change me please"
int main(){
	string s = FILENAME;
#ifdef room210
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//cout<<FILENAME<<endl;
	//assert (s != "change me please");
	clock_t start = clock();
#else
	//freopen(FILENAME ".in", "r", stdin);
	//freopen(FILENAME".out", "w", stdout);
#endif
	//cout.sync_with_stdio(0);
	int t = 1;
	//precalc();
	//cout << "done!\n";
	//cin >> t;
	//gen();
	while (t--)
		solve();
#ifdef room210
	cout<<"\n\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
	return 0;
}

//#define int li

int n, k;
vector <int> masks;

void solve () {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int a[4];
		scanf("%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]);
		masks.push_back(a[3] + a[2] * (1 << 8) + a[1] * (1 << 16) + a[0] * (1 << 24));
	}

	for (int i = 1; i < 32; ++i) {
		int cur = 0;
		for (int j = 0; j < i; ++j)
			cur += (1 << (31 - j));

		set <int> now;
		for (int j = 0; j < n; ++j)
			now.insert(cur & masks[j]);

		if (now.size() == k) {
			vector<int> res;
			for (int w = 0; w < 4; ++w) {
				res.push_back(cur & ((1 << 8) - 1));
				cur >>= 8;
			}
			printf("%d.%d.%d.%d\n", res[3], res[2], res[1], res[0]);
			return;
		}

	}

	cout << "-1";

}