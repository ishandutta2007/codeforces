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
const int N = 20 * 1000 + 10;
const int MOD = 1000 * 1000 * 1000 + 7;





int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s;
	cin >> s;
	set<char> a;
	a.insert('A');
	a.insert('H');
	a.insert('I');
	a.insert('M');
	a.insert('O');
	a.insert('T');
	a.insert('U');
	a.insert('V');
	a.insert('W');
	a.insert('X');
	a.insert('Y');
	string r = s;
	reverse(r.begin(), r.end());
	bool res = true;
	res = res && (r == s);
	for (int i = 0; i < (s.size() + 1) / 2; ++i)
		res = res && (a.find(s[i]) != a.end());
	if (res)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;


	
	return 0;
}