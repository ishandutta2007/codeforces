#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:64000000")
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
const long double eps = 1e-8;
const int INF = 1000 * 1000 * 1000;
const int N = 200 * 1000 * 1000 + 1;



int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	vector<int> data(n, 0), res(n);
	int last = 0, beg = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'l') {
			data[i] += n - last - 1;
			++last;
		}
		else {
			data[i] = beg;
			++beg;
		}
		res[data[i]] = i + 1;
	}
	for (int i = 0; i < n; ++i)
		printf("%d\n", res[i]);
	return 0;
}