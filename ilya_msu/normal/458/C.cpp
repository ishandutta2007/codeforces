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
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000;
const ll LLINF = (ll)8 * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const int N = 100 * 1000 + 1;
const ll MOD = 1000 * 1000 * 1000 + 7;



void solve() {
	int n;
	cin >> n;
	vector<vector<int> > cost(N);
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		cost[a].push_back(b);
		sum += b;
	}
	for (int i = 0; i < cost.size(); ++i) {
		sort(cost[i].begin(), cost[i].end());
		reverse(cost[i].begin(), cost[i].end());
	}
	vector<vector<int> > a(n + 1);
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < cost[i].size(); ++j) {
			a[j].push_back(cost[i][j]);
		}
	}
	ll res = sum;
	ll count = n;
	priority_queue<int> free, add;
	ll addNum = 0;

	for (int l = 1; l <= n; ++l) {
		
		for (int i = 0; i < a[l - 1].size(); ++i) {
			int x = a[l - 1][i];
			sum -= x;
			free.push(-x);
			--count;
		}
		if (count + add.size() > l) {
			res = min(res, sum);
			continue;
		}
		int need = l + 1 - count;
		if (free.size() + add.size() < need)
			break;
		while(add.size() < need) {
			int x = -free.top();
			free.pop();
			addNum += x;
			add.push(x);
		}
		res = min(res, sum + addNum);
		if ((!add.empty()) && (!free.empty()))
			assert(add.top() <= -free.top());
	}
	cout << res << endl;	
}


//#define LOCAL

int main() {
	ios_base::sync_with_stdio(0);
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	solve();
	
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
	return 0;
}