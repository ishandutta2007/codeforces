#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
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
typedef unsigned int uint; 
typedef unsigned long long ull; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;


const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-7;
const int INF = 1000 * 1000 * 1000 + 1;
const ll N = 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;


int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	if (m < n - 1) {
		cout << -1 << endl;
		return 0;
	}
	if (n < (m + 1) / 2 - 1) {
		cout << - 1 << endl;
		return 0;
	}
	while((m > n + 1) && (n > 0)) {
		cout << 110;
		m -= 2;
		--n;
	}
	if (n > m) {
		cout << 0;
		--n;
	}
	for (int i = 0; i < n; ++i)
		cout << 10;
	for (int i = 0; i < m - n; ++i)
		cout << 1;
	cout << endl;

    return 0;
}