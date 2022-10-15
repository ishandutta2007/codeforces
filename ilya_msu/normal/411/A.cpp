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
const int N = 20 * 1000 + 10;
const int MOD = 1000 * 1000 * 1000 + 7;





int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s;
	cin >> s;
	int a, b, c;
	a = b = c = 0;
	for (int i = 0; i < s.size(); ++i) {
		if ((s[i] >= 'a') && (s[i] <= 'z'))
			++a;
		if ((s[i] >= 'A') && (s[i] <= 'Z'))
			++b;
		if ((s[i] >= '0') && (s[i] <= '9'))
			++c;
	}
	if ((a) && (b) && (c) && (s.size() >= 5))
		cout << "Correct" << endl;
	else
		cout << "Too weak" << endl;
	
	
	return 0;
}