#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
void solve();
//void precalc();
clock_t start;
int main() {
#ifdef YA
    freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    int t = 1;
	//cout.sync_with_stdio(0);
	//precalc();
	//cin >> t;
	start = clock();
    while (t--)
        solve();

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

int n;

li a[1000500];

li gcd (li q, li w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

void solve(){

	/*freopen("input.txt", "w", stdout);
	cout << 1000000 << "\n";
	for (int i = 0; i < 1000000; ++i) {
		int cur = (rand() << 16) | rand();
		cout << cur % 1000000;
		cur = (rand() << 16) | rand();
		cout << cur % 1000000;
		cout << ' ';
	}
	cout << "\n";

	return;*/

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%I64d", &a[i]);
		//cin >> a[i];
		/*if (a[i] == 0)
			cout << "bad" << i << "\n";*/
	}
	li ans = 1;
	set<li> checked;
	for (int it = 0; it < 20; ++it) {
		//cout << it << "\n";
		int first = ((rand() << 16) | rand()) % n;
		int second = ((rand() << 16) | rand()) % n;
		li g = gcd(a[first], a[second]);
		if (g == 1)
			continue;
		/*bool flag = true;
		for (set<li>::iterator it = checked.begin(); it != checked.end(); ++it) {
			if (*it % g == 0) {
				flag = false;
				break;
			}
		}
		checked.insert(g);
		if (!flag)
			continue;*/
		vector<li> dels;
		for (li d = 1; d * d <= g; ++d)
			if (g % d == 0) {
				dels.push_back(d);
				if (d * d != g)
					dels.push_back(g / d);
			}
		sort(all(dels));
		vector<int> cnt(dels.size());
		for (int i = 0; i < n; ++i) {
			li cur = gcd(g, a[i]);
			//cout << g << ' ' << cur << "\n";
			int id = lower_bound(all(dels), cur) - dels.begin();
			++cnt[id];
		}
		
		int have = 0;
		for (int i = dels.size() - 1; i >= 0; --i) {
			int sum = 0;
			have += cnt[i];
			if (have * 2 < n)
				continue;
			int antisum = 0;
			for (int j = i; j < dels.size(); ++j) {
				if (dels[j] % dels[i] == 0)
					sum += cnt[j];
				else
					antisum += cnt[j];
				if ((have - antisum) * 2 < n)
					break;
				if (sum * 2 >= n)
					break;
			}
			if (sum * 2 >= n) {
				ans = max(ans, dels[i]);
				break;
			}
		}

		/*if ((clock() - start) / 1.0 / CLOCKS_PER_SEC > 3.8)
			break;*/

	}
	cout << ans;
}