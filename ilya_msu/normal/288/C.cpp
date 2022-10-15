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
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000;
//const int N = 300;
vector<int> p;
int l = 1;
void solve(int n) {
	if (n < 0)
		return;
	if (n == 0) {
		p[0] = 0;
		return;
	}
	while (l > n)
		l /= 2;
	for (int i = l; i <= n; ++i) {
		p[i] = l * 2 - 1 - i;
		p[l * 2 - 1 - i] = i;
	}
	solve(2 * l - n - 2);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	while(l * 2 <= n)
		l *= 2;
	p.resize(n + 1);
	solve(n);
	ll res = 0;
	for (int i = 0; i <= n; ++i)
		res += i ^ p[i];
	cout << res << endl;
	for (int i = 0; i <= n; ++i)
		cout << p[i] << " ";
	cout << endl;

	return 0;
}