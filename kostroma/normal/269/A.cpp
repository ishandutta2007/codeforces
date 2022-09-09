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
void precalc();
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

int n;
pair <int, int> a[100500];

void solve(){
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	for (int i = 0; i < n - 1; ++i) {
		int cur = a[i].second;
		for (int j = a[i + 1].first; j > a[i].first; --j) {
			cur = (cur + 3) / 4;
			if (cur <= a[i + 1].second) {
				cur = a[i + 1].second;
				break;
			}
		}
		a[i + 1].second = cur;
	}
	int cur = a[n - 1].second;
	if (cur == 1) {
		cout << a[n - 1].first + 1;
		return;
	}
	int ans = a[n - 1].first;
	int res = 1;
	while (res < cur) {
		res *= 4;
		++ans;
	}
	cout << ans;
}