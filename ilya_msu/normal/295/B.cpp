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

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<vector<int> > g(n, vector<int> (n, 0));
	vector<vector<int> > d(n, vector<int> (n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> g[i][j];
			d[i][j] = g[i][j];
		}
	}
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}
	reverse(a.begin(), a.end());
	//vector<vector<int> > count(n, vector<int> (n, 0));
	vector<ll> s(n, 0);
	for (int i = 1; i < n; ++i) {
		s[i] = s[i - 1];
		vector<int> used(i, false);
		for (int j = 0; j < i; ++j) {
			int ind = 0;
			int dist = 1000000;
			for (int k = 0; k < i; ++k) {
				if (used[k])
					continue;
				if (d[a[i]][a[k]] < dist) {
					dist = d[a[i]][a[k]];
					ind = k;
				}
			}
			s[i] += d[a[i]][a[ind]];
			used[ind] = true;
			for (int k = 0; k < i; ++k) {
				d[a[i]][a[k]] = min(d[a[i]][a[k]], d[a[i]][a[ind]] + d[a[ind]][a[k]]);
			}
		}
		used.assign(i, false);
		for (int j = 0; j < i; ++j) {
			int ind = 0;
			int dist = 1000000;
			for (int k = 0; k < i; ++k) {
				if (used[k])
					continue;
				if (d[a[k]][a[i]] < dist) {
					dist = d[a[k]][a[i]];
					ind = k;
				}
			}
			s[i] += d[a[ind]][a[i]];
			used[ind] = true;
			for (int k = 0; k < i; ++k) {
				d[a[k]][a[i]] = min(d[a[k]][a[i]], d[a[ind]][a[i]] + d[a[k]][a[ind]]);
			}
		}
		for (int j = 0; j < i; ++j) {
			for (int k = 0; k < i; ++k) {
				if (j == k)
					continue;
				if (d[a[j]][a[k]] > d[a[j]][a[i]] + d[a[i]][a[k]]) {
					s[i] -= (d[a[j]][a[k]] - d[a[j]][a[i]] - d[a[i]][a[k]]);
					d[a[j]][a[k]] = d[a[j]][a[i]] + d[a[i]][a[k]];
					//count[i][k] += count[j][k];
					//count[j][i] += count[j][k];
					//count[j][k] = 0;
				}
			}
		}
	}
	for (int i = n - 1; i >= 0; --i)
		cout << s[i] << " ";
	cout << endl;
	return 0;
}