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
const int mod = 1051131;
const ll N = 300100;



int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("INPUT.TXT", "r", stdin);
	//freopen("OUTPUT.TXT", "w", stdout);
	string s1, s2;
	cin >> s1 >> s2;
	vector<int> c1(256, 0), c2(256, 0);
	for (int i = 0; i < s1.size(); ++i)
		++c1[s1[i]];
	for (int i = 0; i < s2.size(); ++i)
		++c2[s2[i]];
	for (int i = 0; i < 256; ++i) {
		if (c1[i] < c2[i]) {
			cout << "need tree\n";
			return 0;
		}
	}
	if (s1.size() == s2.size()) {
		cout << "array\n";
		return 0;
	}
	int r = 0;
	for (int i = 0; i < s2.size(); ++i) {
		while(r < s1.size()) {
			if (s1[r] == s2[i])
				break;
			++r;
		}
		if (r == s1.size()) {
			cout << "both\n";
			return 0;
		}
		++r;

	}
	cout << "automaton\n";
	return 0;
}