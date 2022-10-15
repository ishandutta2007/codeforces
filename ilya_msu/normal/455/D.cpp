#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:128000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>

 
using namespace std; 
#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000;
//const int N = 1000 * 1000 * 1000 + 10;
const int mod = 1000 * 1000 * 1000 + 7;


int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int sz = n;
	if (n > 100)
		sz = sqrt(1.0 * n);
	vector<deque<int> > a((n + sz - 1) / sz);
	vector<vector<int> > count(a.size(), vector<int> (n + 1, 0));
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		a[i / sz].push_back(x);
		count[i / sz][x]++;
	}
	int q;
	cin >> q;
	int last = 0;
	for (int i = 0; i < q; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r;
			cin >> l >> r;
			l = (last + l - 1) % n;
			r = (last + r - 1) % n;
			if (l > r)
				swap(l, r);
			int x = a[l / sz][l % sz];
			a[l / sz][l % sz] = a[r / sz][r % sz];
			int i1 = l / sz, i2 = r / sz;
			if (i1 == i2) {
				for (int j = (l % sz) + 1; j <= (r % sz); ++j) {
					swap(x, a[i1][j]);
				}
				continue;
			}
			for (int j = (l % sz) + 1; j < sz; ++j) {
				swap(x, a[i1][j]);
			}
			count[i1][x]--;
			count[i1][a[l / sz][l % sz]]++;
			count[i2][a[l / sz][l % sz]]--;
			for (int j = i1 + 1; j < i2; ++j) {
				a[j].push_front(x);
				count[j][x]++;
				x = a[j][sz];
				a[j].pop_back();
				count[j][x]--;
			}
			count[i2][x]++;
			for (int j = 0; j <= (r % sz); ++j)
				swap(a[i2][j], x);
		}
		else {
			int l, r, k;
			cin >> l >> r >> k;
			l = (l + last - 1) % n;
			r = (r + last - 1) % n;
			k = (k + last - 1) % n + 1;
			if (l > r)
				swap(l, r);
			int i1 = l / sz, i2 = r / sz;
			int res = 0;
			if (i1 == i2) {
				for (int j = (l % sz); j <= (r % sz); ++j)
					res += (a[i1][j] == k);
				cout << res << "\n";
				last = res;
				continue;
			}
			for (int j = i1 + 1; j < i2; ++j)
				res += count[j][k];
			for (int j = (l % sz); j < sz; ++j)
				res += (a[i1][j] == k);
			for (int j = 0; j <= (r % sz); ++j)
				res += (a[i2][j] == k);
			cout << res << "\n";
			last = res;
		}
	}
    return 0;
}