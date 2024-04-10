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

 
using namespace std; 
 
typedef long long ll; 
typedef unsigned int uint; 
typedef unsigned long long ull; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;


const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-7;
const int INF = 1000 * 1000 * 1000 + 1;
const ll N = 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;


int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int x, k;
	cin >> x >> k;
	vector<int> a;
	for (int i = 0; i < k; ++i) {
		int t;
		cin >> t;
		int n, m;
		cin >> n;
		a.push_back(n);
		if (t == 1) {
			cin >> m;
			a.push_back(m);
		}
	}
	a.push_back(x);
	a.push_back(0);
	sort(a.begin(), a.end());
	int mini = 0, maxi = 0;
	for (int i = 1; i < a.size(); ++i) {
		mini += (a[i] - a[i - 1]) / 2;
		maxi += a[i] - a[i - 1] - 1;
	}
	cout << mini << " " << maxi << endl;
	

    return 0;
}