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


int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, p;
	scanf("%d %d", &n, &p);
	vector<int> d(n);
	int a, b;
	vector<pii> ed(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &a, &b);
		--a, --b;
		++d[a], ++d[b];
		if (a > b)
			swap(a, b);
		ed[i] = pii(a, b);
	}
	
	ll res = 0;
	vector<int> dd(n);
	for (int i = 0; i < n; ++i)
		dd[i] = d[i];
	sort(dd.begin(), dd.end());
	int r = n - 1;
	for (int i = 0; i < n; ++i) {
		if (dd[i] * 2 >= p)
			--res;
		while((r >= 0) && (dd[i] + dd[r] >= p))
			--r;
		res += n - 1 - r;
	}
	res /= 2;
	sort(ed.begin(), ed.end());
	for (int i = 0; i < n; ++i) {
		pii e = ed[i];
		int c = 1;
		while(i + 1 < n) {
			if (ed[i + 1] == e) {
				++c;
				++i;
			}
			else
				break;
		}
		if (d[e.first] + d[e.second] >= p)
			--res;
		if (d[e.first] + d[e.second] - c >= p)
			++res;
	}
	cout << res << endl;


	return 0;
}