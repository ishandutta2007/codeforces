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
//const int N = 100 * 1000 + 1;

int solve(const vector<int>& s) {
	stack<int> st;
	int n = s.size();
	vector<int> next(n, 0);
	for (int i = 0; i < n; ++i) {
		while((!st.empty()) && (s[st.top()] < s[i])) {
			next[st.top()] = s[i];
			st.pop();
		}
		st.push(i);
	}
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (next[i])
			res = max(res, s[i] ^ next[i]);
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x = 0;
	cin >> n;
	string s = "";
	int a, g;
	for (int i = 0; i < n; ++i) {
		cin >> a >> g;
		if (a + x <= 500) {
			x += a;
			s += 'A';
		}
		else {
			x -= g;
			s += 'G';
		}
	}
	cout << s << endl;
	return 0;
}