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
const int INF = 1000 * 1000 * 10 + 10;
const int N = 1000 * 10000 + 10;


int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	set<int> s;
	for (int i = 3; i <= 360; ++i) {
		if ((180 * (i - 2)) % i == 0)
			s.insert(180 * (i - 2) / i);
	}
	int t;
	cin >> t;
	int a;
	for (int i = 0; i < t; ++i) {
		cin >> a;
		if (s.find(a) != s.end())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}