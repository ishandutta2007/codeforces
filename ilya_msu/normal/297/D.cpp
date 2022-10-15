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

void print(const vector<vector<int> >& a) {
	int n = a.size();
	for (int i = 0; i < n; ++i) {
		int m = a[i].size();
		for (int j = 0; j < m - 1; ++j)
			printf("%d ", a[i][j] + 1);
		printf("%d\n", a[i][m - 1] + 1);
	}
	return;
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int h, w, k;
	cin >> h >> w >> k;
	bool tr = false;
	int bounds = 2 * h * w - h - w;
	int eq = 0;
	//if (h > w) {
	//	tr = true;
	//	swap(h, w);
	//}
	vector<vector<int> > gor(h, vector<int> (w - 1)), ver(h - 1, vector<int>(w));
	string s;
	for (int i = 0; i < 2 * h - 1; ++i) {
		cin >> s;
		for (int j = 0; j < s.size(); ++j)
			if (s[j] == 'E')
				++eq;
		if (i & 1) {
			for (int j = 0; j < w; ++j)
				ver[i / 2][j] = (s[j] == 'E');
		}
		else {
			for (int j = 0; j < w - 1; ++j)
				gor[i / 2][j] = (s[j] == 'E');
		}
	}
	vector<vector<int> > color(h, vector<int>(w, 0));
	if (k == 1) {
		if (4 * eq >= 3 * bounds) {
			printf("YES\n");
			print(color);
		}
		else
			printf("NO\n");
		return 0;
	}
	if (h <= w) {
		for (int i = 0; i < h; ++i) {
			for (int j = 1; j < w; ++j)
				if (gor[i][j - 1])
					color[i][j] = color[i][j - 1];
				else
					color[i][j] = 1 - color[i][j - 1];
		}
		for (int i = 1; i < h; ++i) {
			int count = 0;
			for (int j = 0; j < w; ++j)
				if ((color[i][j] == color[i - 1][j]) != (ver[i - 1][j]))
					++count;
			if (count * 2 > w) {
				for (int j = 0; j < w; ++j)
					color[i][j] = 1 - color[i][j];
			}
		}
	}
	else {
		for (int i = 0; i < w; ++i) {
			for (int j = 1; j < h; ++j)
				if (ver[j - 1][i])
					color[j][i] = color[j - 1][i];
				else
					color[j][i] = 1 - color[j - 1][i];
		}
		for (int i = 1; i < w; ++i) {
			int count = 0;
			for (int j = 0; j < h; ++j)
				if ((color[j][i] == color[j][i - 1]) != (gor[j][i - 1]))
					++count;
			if (count * 2 > h) {
				for (int j = 0; j < h; ++j)
					color[j][i] = 1 - color[j][i];
			}
		}
	}
	cout << "YES" << endl;
	print(color);
	
	return 0;
}