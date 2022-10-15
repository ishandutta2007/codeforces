#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:64000000")
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
 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-8;
const ll INF = 777777777777 + 1;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s, res;
	cin >> s;
	res = s.substr(0, s.size() - 1);
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '0') {
			res = s.substr(0, i) + s.substr(i + 1, s.size() - i - 1);
			break;
		}
	}
	cout << res << endl;

	return 0;
}