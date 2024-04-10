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
const int INF = 1000 * 1000 * 1000;
const int N = 1000 * 100 + 10;


int main() {
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<pii> s(n);
	vector<int> a(n, 0), b(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> s[i].first;
		s[i].second = i;
	}
	sort(s.begin(), s.end());
	int k = (n + 2) / 3;
	for (int i = 0; i < min(k, n); ++i) {
		a[s[i].second] = 0;
		b[s[i].second] = s[i].first;
	}
	for (int i = k; i < min(2 * k, n); ++i) {
		b[s[i].second] = 0;
		a[s[i].second] = s[i].first;
	}
	for (int i = 2 * k; i < n; ++i) {
		a[s[i].second] = 3 * k - i;
		b[s[i].second] = s[i].first - a[s[i].second];
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; ++i) {
		cout << b[i] << " ";
	}
	cout << endl;
	return 0;
}