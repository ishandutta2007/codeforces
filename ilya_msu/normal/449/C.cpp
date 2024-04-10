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
#include<cassert>

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<long double, long double> pdd;

typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 10;
const int N = 100 * 1000 + 10;
const int MOD = 1000 * 1000 * 1000 + 7;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;


int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> used(n + 1, false);
	vector<int> d(n + 1, 1);
	vector<int> p;
	for (int i = 2; i < d.size(); ++i) {
		if (d[i]) {
			p.push_back(i);
			for (int j = i + i; j < d.size(); j += i)
				d[j] = 0;
		}
	}
	reverse(p.begin(), p.end());
	vector<pii> res;
	for (int i = 0; i < p.size(); ++i) {
		vector<int> a;
		int pp = p[i];
		for (int i = pp; i <= n; i +=pp) {
			if (used[i])
				continue;
			a.push_back(i);
		}
		if (a.size() <= 1)
			continue;
		swap(a[1], a[a.size() - 1]);
		for (int i = 0; 2 * i + 1 < a.size(); ++i) {
			used[a[2 * i]] = used[a[2 * i + 1]] = 1;
			res.push_back(pii(a[2 * i], a[2 * i + 1]));
		}		
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); ++i)
		cout << res[i].first << " " << res[i].second << "\n";

	return 0;
}