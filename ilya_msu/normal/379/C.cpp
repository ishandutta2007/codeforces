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
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<long double, long double> pdd;

typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 10000000;
//const int N = 1000 * 1000 * 1000 + 10;
const int MOD = 1000 * 1000 * 1000 + 7;

int main() {
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<pii> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	int m = 0;
	vector<int> b(n);
	for (int i = 0; i < n; ++i) {
		int x = max(m + 1, a[i].first);
		m = x;
		b[a[i].second] = x;
	}
	for (int i = 0; i < n; ++i)
		cout << b[i] << " ";
	cout << "\n";
    
    return 0;
}