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
const int N = 300;


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> a(n);
	bool first = true;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	if (n == 1) 
		first = (a[0] > 0);
	if (n == 2) {
		vector<vector<int> > data(N, vector<int> (N, 0));
		for (int i = 0; i < N; ++i) 
			for (int j = 0; j < N; ++j) {
				if (data[i][j] == 1)
					continue;
				for (int jj = j + 1; jj < N; ++jj) 
					data[i][jj] = 1;
				for (int ii = i + 1; ii < N; ++ii)
					data[ii][j] = 1;
				for (int add = 1; (add + i < N) && (add + j < N); ++add)
					data[i + add][j + add] = 1;
			}
		first = data[a[0]][a[1]];
	}
	if (n == 3) {
		vector<vector<vector<int> > > data(N, vector<vector<int> > (N, vector<int> (N, 0)));
		for (int i = 0; i < N; ++i) 
			for (int j = 0; j < N; ++j) 
				for (int k = 0; k < N; ++k) {
					if (data[i][j][k] == 1)
						continue;
					for (int jj = j + 1; jj < N; ++jj) 
						data[i][jj][k] = 1;
					for (int ii = i + 1; ii < N; ++ii)
						data[ii][j][k] = 1;
					for (int kk = k + 1; kk < N; ++kk)
						data[i][j][kk] = 1;
					for (int add = 1; (add + i < N) && (add + j < N) && (add + k < N); ++add)
						data[i + add][j + add][k + add] = 1;
				}
		first = data[a[0]][a[1]][a[2]];
	}
	if (first)
		cout << "BitLGM" << endl;
	else
		cout << "BitAryo" << endl;
	return 0;
}