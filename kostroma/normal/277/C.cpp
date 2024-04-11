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
#include <unordered_map>

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

#define int li

int n[2], k;

unordered_map <int, vector<pair<int,int> > > segs[2];

vector <pair<int, int> > nums[2];

void solve(){
	cin >> n[0] >> n[1] >> k;
	for (int i = 0; i < k; ++i) {
		int x[2], y[2];
		cin >> x[0] >> y[0] >> x[1] >> y[1];
		if (x[0] > x[1])
			swap(x[0], x[1]);
		if (y[0] > y[1])
			swap(y[0], y[1]);

		if (x[0] == x[1]) {
			if (x[0] == 0 || x[0] == n[0])
				continue;
			segs[0][x[0]].push_back(mp(y[0], y[1]));
		}
		else {
			if (y[0] == 0 || y[0] == n[1])
				continue;
			segs[1][y[0]].push_back(mp(x[0], x[1]));
		}
	}
	for (int w = 0; w < 2; ++w) {
		for (auto it = segs[w].begin(); it != segs[w].end(); ++it) {
			sort(all(it->second));
			int sum = 0, border = 0;
			int len = it->second.size();
			for (int i = 0; i < len; ++i) {
				if (it->second[i].first > border) {
					sum += it->second[i].first - border;
				}
				border = max(border, it->second[i].second);
			}
			if (border < n[w ^ 1])
				sum += n[w ^ 1] - border;
			nums[w].push_back(mp(it->first, sum));
		}
	}

	int rest[2];
	for (int w = 0; w < 2; ++w) {
		rest[w] = n[w] - 1 - nums[w].size();
		sort(all(nums[w]));
	}

	int xor = 0;
	for (int w = 0; w < 2; ++w) {
		if (rest[w] & 1)
			xor ^= n[w ^ 1];
		for (int i = 0; i < nums[w].size(); ++i)
			xor ^= nums[w][i].second;
	}

	if (xor == 0) {
		cout << "SECOND\n";
		return;
	}

	cout << "FIRST\n";

	for (int w = 0; w < 2; ++w) {
		if (rest[w] > 0) {
			if ((xor ^ n[w ^ 1]) < n[w ^ 1]) {

				//cout << xor << endl;

				int hod = -(xor ^ n[w ^ 1]) + n[w ^ 1];

				int last = 0;

				for (int i = 0; i < nums[w].size(); ++i) {
					if (nums[w][i].first - last > 1) {

						int need = nums[w][i].first - 1;

						if (w == 1) {
							cout << "0" << " " << need << " " << hod << " " << need;
							return;
						}
						else {
							cout << need << " " << "0" << " " << need << " " << hod;
							return;
						}

					}
					last = nums[w][i].first;
				}

				assert(last != n[w] - 1);

				int need = last + 1;

				if (w == 1) {
					cout << "0" << " " << need << " " << hod << " " << need;
					return;
				}
				else {
					cout << need << " " << "0" << " " << need << " " << hod;
					return;
				}

			}
		}
			
		for (int i = 0; i < nums[w].size(); ++i) {
			if ((xor ^ nums[w][i].second) < nums[w][i].second) {
				int hod = -(xor ^ nums[w][i].second) + nums[w][i].second;
				//cout << hod << endl;
				vector <pair<int, int> > now = segs[w][nums[w][i].first];
				now.push_back(mp(n[w ^ 1], n[w ^ 1]));

				int sum = 0, border = 0;

				for (int j = 0; j < now.size(); ++j) {
					if (now[j].first > border) {
						sum += now[j].first - border;
						if (sum >= hod) {
							border = now[j].first;
							break;
						}
					}
					border = max(border, now[j].second);
				}

				assert(sum >= hod);

				border -= (sum - hod);

				int need = nums[w][i].first;

				assert(border > 0);

				if (w == 1) {
					cout << "0" << " " << need << " " << border << " " << need;
					return;
				}
				else {
					cout << need << " " << "0" << " " << need << " " << border;
					return;
				}

			}
		}
	}

	assert(false);

}