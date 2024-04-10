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
const int mod = 1000 * 1000 * 1000 + 9;
const long double eps = 1e-10;


int count(string& s) {
	int res = 0;
	for (int i = 0; i < s.size(); ++i) 
		res = (res * 10 + (s[i] - '0')) % 7;
	return res;
}

int main() {
	//ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '1') {
			swap(s[i], s[0]);
			continue;
		}
		if (s[i] == '8') {
			swap(s[i], s[1]);
			continue;
		}
		if (s[i] == '6') {
			swap(s[i], s[2]);
			continue;
		}
		if (s[i] == '9') {
			swap(s[i], s[3]);
			continue;
		}
	}
	sort(s.begin(), s.begin() + 4);
	while(true) {
		int x = count(s);
		if (x % 7 == 0) {
			cout << s << endl;
			return 0;
		}
		next_permutation(s.begin(), s.begin() + 4);
	}
    return 0;
}