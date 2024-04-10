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
typedef pair<double, double> pdd;

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 2 * 1000 * 1000 * 1000 + 10;
//const int N = 1000 * 1000 * 1000 + 10;
const int mod = 1000 * 1000 * 1000 + 7;

double inter(vector<pdd>& x, const vector<pdd> y) {
	double res = 0;
	vector<pdd> a = x;
	vector<pdd> b(a.size());
	int j = 0;
	for (int i = 0; i < a.size(); ++i) {
		b[i].first = a[i].first;
		if (b[i].first > j + 1 - 1e-8)
			++j;
		if (j + 1 < y.size())
			b[i].second = y[j + 1].second * (b[i].first - j) + y[j].second * (j + 1 - b[i].first);
		else
			b[i].second = y[j].second;
	}
	x.clear();
	if (b[0].second > a[0].second)
		x.push_back(b[0]);
	else
		x.push_back(a[0]);

	for (int i = 0; i + 1 < a.size(); ++i) {
		
		if ((a[i].second + 1e-8 > b[i].second) && (a[i + 1].second + 1e-8 > b[i + 1].second)) {
			x.push_back(a[i + 1]);
			continue;
		}
		if ((a[i].second < b[i].second + 1e-8) && (a[i + 1].second < b[i + 1].second + 1e-8)) {
			x.push_back(b[i + 1]);
			res += (b[i].second - a[i].second + b[i + 1].second - a[i + 1].second) * (a[i + 1].first - a[i].first) / 2;
			continue;
		}
		if ((a[i].second < b[i].second + 1e-8) && (a[i + 1].second + 1e-8 > b[i + 1].second)) {
			if (abs(a[i + 1].second - a[i].second - b[i + 1].second + b[i].second) > 1e-6) {
				double h = (b[i].second - a[i].second) / (a[i + 1].second - a[i].second - b[i + 1].second + b[i].second) * (a[i + 1].first - a[i].first);
				res += h * (b[i].second - a[i].second) / 2;
				x.push_back(pdd(a[i].first + h, a[i].second + h / (a[i + 1].first - a[i].first) * (a[i + 1].second - a[i].second)));
			}
			x.push_back(a[i + 1]);
			continue;
		}
		res += (b[i].second + b[i + 1].second - a[i].second - a[i + 1].second) * (a[i + 1].first - a[i].first) / 2;
		if (abs(a[i + 1].second - a[i].second - b[i + 1].second + b[i].second) > 1e-6) {
			double h = (b[i].second - a[i].second) / (a[i + 1].second - a[i].second - b[i + 1].second + b[i].second) * (a[i + 1].first - a[i].first);
			res -= h * (b[i].second - a[i].second) / 2;
			x.push_back(pdd(a[i].first + h, a[i].second + h / (a[i + 1].first - a[i].first) * (a[i + 1].second - a[i].second)));
		}
		x.push_back(b[i + 1]);
	}
	sort(x.begin(), x.end());
	return res;	
}


int main() {
	ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<pdd> x(k + 1);
	for (int i = 0; i < k + 1; ++i)
		x[i] = pdd(i, 0);
	vector<pdd> lom(k + 1);
	vector<double> res(n, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k + 1; ++j) {
			cin >> lom[j].second;
			lom[j].first = j;
		}
		res[i] = inter(x, lom);
		cout.precision(18);
		cout << res[i] << "\n";
	}
	
    return 0;
}