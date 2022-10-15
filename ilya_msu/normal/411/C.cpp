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
typedef pair<long double, long double> pdd;

typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 10;
const int N = 100 * 1000 + 10;
const int MOD = 1000 * 1000 * 1000 + 7;

int get(int a, int b, int c, int d) {
	if ((a > d) && (b > c))
		return 1;
	if ((a < d) && (b < c))
		return -1;
	return 0;
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<pii> t(4);
	for (int i = 0; i < 4; ++i)
		cin >> t[i].first >> t[i].second;
	vector<int> res(4);
	res[0] = get(t[0].first, t[1].second, t[2].first, t[3].second);
	res[1] = get(t[0].first, t[1].second, t[3].first, t[2].second);
	res[2] = get(t[1].first, t[0].second, t[2].first, t[3].second);
	res[3] = get(t[1].first, t[0].second, t[3].first, t[2].second);
	if (((res[0] == 1) && (res[1] == 1)) || ((res[2] == 1) && (res[3] == 1))) {
		cout << "Team 1" << endl;
		return 0;
	}
	if (((res[0] == -1) || (res[1] == -1)) && ((res[2] == -1) || (res[3] == -1)))  {
		cout << "Team 2" << endl;
		return 0;
	}
	cout << "Draw" << endl;

	return 0;
}