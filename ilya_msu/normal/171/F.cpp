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
const long double eps = 1e-5;
const int INF = 1000 * 1000;
//const int N = 300;
map<char, char> m;

string trans(string s) {
	for (int i = 0; i < s.size(); ++i) {
		if (m.find(s[i]) != m.end())
			s[i] = m[s[i]];
	}
	return s;
}

int rev(int x) {
	int y = 0;
	while (x) {
		y = 10 * y + (x % 10);
		x /= 10;
	}
	return y;
}

bool isPrime(int x) {
	for (int i = 2; i * i <= x; ++i) {
		if ((i != x) && (x % i == 0))
			return false;
	}
	return true;
}


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);
	/*m[''] = '';
	m[''] = '';
	m[''] = '';
	m[''] = '';
	m[''] = '';
	m[''] = '';
	m[''] = '';
	m[''] = '';
	m[''] = '';
	m[''] = '';
	m[''] = '';
	m[''] = '';
	m[''] = '';
	m[''] = '';
	m[''] = '';
	m[''] = '';
	m[''] = '';
	m[''] = '';
	m[''] = '';
	m[''] = '';
	m[''] = '';
	m[''] = '';
	m[''] = '';
	m[''] = '';
	m[''] = '';
	m[''] = '';
*/
	int n;
	cin >> n;
	vector<int> pr;
	int x = 13;
	while (pr.size() < n) {
		if (isPrime(x) && (x != rev(x)) && (isPrime(rev(x))))
			pr.push_back(x);
		x += 2;
	}
	cout << pr[n - 1] << endl;
	return 0;
}