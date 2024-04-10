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
#include<cassert>

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)
 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000;
const ll LLINF = (ll)8 * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const int N = 100 * 1000 + 1;
const ll MOD = 1000 * 1000 * 1000 + 7;
const int root = 239;

struct Fenvick {
	int n;
	vector<int> a;
	Fenvick(int nn) {
		n = nn;
		a.assign(n, 0);
	}
	int sum(int r) {
		int res = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1)
			res += a[r];
		return res;
	}
	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
	void inc(int id, int d) {
		for (; id < n; id = id | (id + 1))
			a[id] += d;
	}
};

bool brute(const vector<int>& a) {
	int n = a.size();
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = i + 1; k < j; ++k) {
				if (a[k] * 2 == a[i] + a[j])
					return true;
			}
		}
	}
	return false;
}

int power(int a, int n) {
	int res = 1;
	while(n) {
		if (n & 1)
			res *= a;
		a *= a;
		n /= 2;
	}
	return res;
}

bool solve(const vector<int>& a) {
	int n = a.size();
	Fenvick tr1(n + 1), tr2(n + 1);
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		int len = min(x, n - x + 1);
		int h1 = tr1.sum(x - len + 1, x) * power(root, n - x);
		int h2 = tr2.sum(x, x + len - 1) * power(root, x - 1);
		if (h1 != h2)
			return true;
		tr1.inc(a[i], power(root, x));
		tr2.inc(a[i], power(root, n - x + 1));

	}
	return false;
}

void print(const vector<int>& a) {
	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << " ";
	cout << endl;
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//int n;
	//cin >> n;
	//vector<int> a(n);
	//int count1 = 0, count2 = 0;;
	//for (int i = 0; i < a.size(); ++i)
	//	a[i] = i + 1;
	//sort(a.begin(), a.end());
	//do {
	//	if (!brute(a)) {
	//		++count1;
	//		//print(a);
	//	}
	//	if (!naive(a))
	//		++count2;
	//	if ((brute(a) == 1) && (naive(a) == 0))
	//		print(a);
	//} while(next_permutation(a.begin(), a.end()));
	//cout << count1 << " " << count2 << endl;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	if (solve(a))
		cout << "YES\n";
	else
		cout << "NO\n";	
	return 0;
}