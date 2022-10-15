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
const ll N1 = 100 * 1000, N2 = 1000 * 1000 * 1000, N3 = 2000;
const ll MOD = 1000 * 1000 * 1000 + 7;

struct SegmentTree {
	vector<int> a;
	int n;
	int build(int v, int l, int r, const vector<int>& b) {
		if (l == r) {
			a[v] = b[l];
			return a[v];
		}
		int m = (l + r) / 2;
		a[v] = min(build(2 * v, l, m, b), build(2 * v + 1, m + 1, r, b));
		return a[v];
	}
	SegmentTree(const vector<int>& b) {
		n = b.size();
		a.resize(4 * n + 10);
		build(1, 0, n - 1, b);
	}
	int get(int v, int tl, int tr, int l, int r) {
		if ((tl >= l) && (tr <= r))
			return a[v];
		if ((tl > r) || (tr < l))
			return INF;
		int m = (tl + tr) / 2;
		return min(get(2 * v, tl, m, l, r), get(2 * v + 1, m + 1, tr, l, r));
	}
	int get(int l, int r) {
		return get(1, 0, n - 1, l, r);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(')
			a[i] = 1;
		else
			a[i] = -1;
	}
	vector<int> sum(n + 1, 0), sumz(n + 1, 0);
	for (int i = 1; i < n + 1; ++i) {
		sum[i] = sum[i - 1] + a[i - 1];
		sumz[i] = sumz[i - 1];
		if (a[i - 1] == -1)
			sumz[i]++;
	}
	SegmentTree tr(sum);
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		int m = tr.get(l, r);
		m -= sum[l - 1];
		int x = sumz[r] - sumz[l - 1];
		int y = r - l + 1 - x;
		if (m < 0)
			x += m;
		cout << min(x, y) * 2 << "\n";
	}    
    return 0;
}