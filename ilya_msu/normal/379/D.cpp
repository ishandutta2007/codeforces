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
//const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000;
//const int N = 1000 * 1000 * 1000 + 10;

string s1, s2;

bool construct(int a, int b, int c12, int c21, int c22, int n, int m) {
	s1 = "";
	s2 = "";
	for (int i = 0; i < a; ++i)
		s1 += "AC";
	for (int i = 0; i < b; ++i)
		s2 += "AC";
	string b1 = "", b2 = "", e1 = "", e2 = "";
	if (c12) {
		e1 = "A";
		b2 = "C";
	}
	if (c21) {
		e2 = "A";
		b1 = "C";		
	}
	if (c22) {
		b2 = "C";
		e2 = "A";
	}
	while(b1.size() + e1.size() + s1.size() < n)
		s1 += 'B';
	while(b2.size() + e2.size() + s2.size() < m)
		s2 += 'B';
	s1 = b1 + s1 + e1;
	s2 = b2 + s2 + e2;
	if ((c12 == 0) && (e1 == "A") && (b2 == "C"))
		return false;
	if ((c21 == 0) && (e2 == "A") && (b1 == "C"))
		return false;
	if ((c22 == 0) && (e2 == "A") && (b2 == "C"))
		return false;
	return ((s1.size() == n) && (s2.size() == m));
}

void print(string& s1, string& s2) {
	cout << s1 << "\n";
	cout << s2 << "\n";
}

void fail() {
	cout << "Happy new year!\n";
}

vector<pii> get(ll x1, ll x2, ll x) {
	vector<pii> res;
	if (x < 0)
		return res;
	for (int i1 = 0; i1 <= 100; ++i1)
		for (int i2 = 0; i2 <= 100; ++i2)
			if (x1 * i1 + x2 * i2 == x)
				res.push_back(pii(i1, i2));
	return res;
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll k, x, n, m;
	cin >> k >> x >> n >> m;
	vector<ll> f1(k + 1), a1(k + 1), a2(k + 1), a12(k + 1), a21(k + 1), a22(k + 1);
	f1[0] = 0, f1[1] = 1;
	a1[0] = -1, a1[1] = 1;
	a2[0] = 1, a2[1] = 0;
	for (int i = 2; i <= k; ++i) {
		f1[i] = f1[i - 1] + f1[i - 2];
		a1[i] = a1[i - 1] + a1[i - 2];
		a2[i] = a2[i - 1] + a2[i - 2];
	}
	ll x1 = a1[k], x2 = a2[k], x12 = x1, x21 = x1 - 1 + ((k + 1) & 1), x22 = x1 + x2 - 1 - x12 - x21;
	//x1 * a + x2 * b + x12 * 
	for (int c12 = 0; c12 < 2; ++c12) {
		for (int c21 = 0; c21 < 2; ++c21) {
			for (int c22 = 0; c22 < 2; ++c22) {
				vector<pii> res = get(x1, x2, x - c12 * x12 - c21 * x21 - c22 * x22);
				for (int i = 0; i < res.size(); ++i) {
					if (construct(res[i].first, res[i].second, c12, c21, c22, n, m)) {
						print(s1, s2);
						return 0;
					}
				}
			}
		}
	}
	fail();    
    return 0;
}