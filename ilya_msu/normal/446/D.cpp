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
#include<cassert>



 
using namespace std; 
 
typedef long long ll; 
typedef long double ld;
typedef unsigned int uint; 
typedef unsigned long long ull; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 9;
const ll N = 300100;

void print(vector<vector<double> > a, vector<vector<double> > b) {
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a[i].size(); ++j) {
			printf("%0.2f ", a[i][j]);
		}
		cout << "\t";
		for (int j = 0; j < b[i].size(); ++j)
			printf("%0.2f ", b[i][j]);

		cout << "\n";
	}
	cout << "\n";
}

vector<vector<double> > gauss(vector<vector<double> > a, vector<vector<double> > b) {
	int n = a.size(), m = b[0].size();
	for (int i = 0; i < n; ++i) {
		//print(a, b);
		double M = abs(a[i][i]);
		int ind = i;
		for (int j = i; j < n; ++j) {
			if (abs(a[j][i]) > M) {
				M = abs(a[j][i]);
				ind = j;
			}
		}
		M = a[ind][i];
		for (int j = i; j < n; ++j) {
			swap(a[i][j], a[ind][j]);
			a[i][j] /= M;
		}
		//print(a, b);
		for (int j = 0; j < m; ++j) {
			swap(b[i][j], b[ind][j]);
			b[i][j] /= M;
		}
		for (int r = 0; r < n; ++r) {
			if (r == i)
				continue;
			double d = a[r][i];
			for (int j = i; j < n; ++j) {
				a[r][j] -= d * a[i][j];
			}
			for (int j = 0; j < m; ++j) {
				b[r][j] -= d * b[i][j];
			}
		}
	}
	return b;
}

vector<vector<double> > mult(const vector<vector<double> >& a, const vector<vector<double> >& b) {
	int n = a.size();
	vector<vector<double> > res(n, vector<double>(n, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k)
				res[i][j] += a[i][k] * b[k][j];
	return res;
}

vector<vector<double> > power(vector<vector<double> > a, int n) {
	vector<vector<double> > res(a.size(), vector<double>(a.size(), 0));
	for (int i = 0; i < res.size(); ++i)
		res[i][i] = 1;
	while(n) {
		if (n & 1) 
			res = mult(res, a);
		a = mult(a, a);
		n /= 2;
	}
	return res;
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("INPUT.TXT", "r", stdin);
	//freopen("OUTPUT.TXT", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> trap(n);
	vector<int> trInd;
	vector<int> trId(n);
	for (int i = 0; i < n; ++i) {
		cin >> trap[i];
		if (trap[i]) {
			trId[i] = trInd.size();
			trInd.push_back(i);		
		}
		else
			trId[i] = -1;
	}
	int numTr = trInd.size();
	vector<vector<int> > g(n, vector<int> (n, 0));
	vector<int> deg(n, 0);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		++deg[a], ++deg[b];
		++g[a][b], ++g[b][a];
	}
	vector<vector<double> > ma(n, vector<double>(n, 0)), mb(n, vector<double>(numTr, 0));
	for (int i = 0; i < n; ++i) {
		ma[i][i] = 1;
		for (int j = 0; j < n; ++j) {
			if (trap[j]) {
				mb[i][trId[j]] = 1.0 * g[i][j] / deg[i];				
			}
			else {
				ma[i][j] -= 1.0 * g[i][j] / deg[i];				
			}
		}
	}
	vector<vector<double> > mc = gauss(ma, mb);
	vector<double> v0 = mc[0];
	vector<vector<double> > mp(numTr, vector<double>(numTr));
	for (int i = 0; i < trInd.size(); ++i)
		mp[i] = mc[trInd[i]];
	for (int i = 0; i < mp.size(); ++i)
		for (int j = i + 1; j < mp.size(); ++j)
			swap(mp[i][j], mp[j][i]);
	vector<vector<double> > mtr = power(mp, k - 2);
	double res = 0;
	for (int i = 0; i < v0.size(); ++i)
		res += mtr[numTr - 1][i] * v0[i];
	printf("%0.10f\n", res);
	
	
	return 0;
}