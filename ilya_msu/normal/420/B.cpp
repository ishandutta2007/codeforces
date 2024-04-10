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

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)
 
using namespace std;  
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 2 * 1000 * 1000 * 1000 + 10;
const ll LLINF = (ll)4 * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const int N = 1000 * 1000 * 1000 + 100;
const int mod = 1000 * 1000 * 1000 + 7;



int main() {
	//ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> used(n, true);
	int cur = 0;
	vector<vector<int> > a(n);
	vector<int> c(m);
	for (int i = 0; i < m; ++i) {
		char x = ' ';
		int y;
		while((x != '+') && (x != '-')) 
			cin >> x;
		cin >> y;
		if (x == '-') {
			a[y - 1].push_back(-i - 1);
		}
		else
			a[y - 1].push_back(i + 1);
		if (x == '-')
			y = -y;
		c[i] = y;		
	}
	for (int i = 0; i < n; ++i)
		if (a[i].size() > 0)
			if (a[i][0] < 0)
				++cur;
	for (int i = 0; i < m; ++i) {
		int sign = 1;
		if (c[i] < 0)
			sign = -1;
		int y = abs(c[i]);
		if (sign == 1) {
			if (cur > 0)
				used[y - 1] = false;
			++cur;
		}
		else {
			--cur;
			if (cur > 0)
				used[y - 1] = false;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (a[i].empty())
			continue;
		int s = 1;
		if (a[i][0] < 0)
			s = -1;
		int y = abs(a[i][0]);
		if (s == 1) {
			if (y != 1) {
				used[i] = false;
				continue;
			}
		}
		for (int j = 1; j < a[i].size(); ++j) {
			s = -s;
			if ((s > 0) && (abs(a[i][j]) - abs(y) != 1)) {
				used[i] = false;
				continue;
			}
			y = abs(a[i][j]);
		}
		if (s < 0)
			if (abs(a[i][a[i].size() - 1]) != m)
				used[i] = false;
	}
	vector<int> res;
	for (int i = 0; i < n; ++i)
		if (used[i])
			res.push_back(i + 1);
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << " ";
	if (res.size() > 0)
		cout << endl;
    return 0;
}