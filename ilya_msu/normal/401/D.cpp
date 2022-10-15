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

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-7;
const int INF = 1000 * 1000 * 1000 + 1;
const ll N = 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;

vector<int> digits(10, 0);

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll n, m;
	cin >> n >> m;
	while(n) {
		int c = n % 10;
		++digits[c];
		n /= 10;
	}
	ll up = 1;
	vector<int> add;
	for (int i = 0; i < 10; ++i) {
		add.push_back(up);
		up *= digits[i] + 1;
	}
	add.push_back(up);
	vector<vector<ll> > d(up, vector<ll>(m, 0));
	d[0][0] = 1;
	for (int i = 0; i < up; ++i) {
		//debug(i);
		for (int j = 0; j < m; ++j) {
			//debug(j);
			int x = i;
			vector<int> vx(10, 0);
			int ind = 0;
			while(x) {
				vx[ind] = x % (digits[ind] + 1);
				x /= digits[ind] + 1;
				++ind;

			}

			for (int c = 0; c < 10; ++c) {
				if (vx[c] == digits[c])
					continue;
				int next = i + add[c];
				if ((i == 0) && (c == 0))
					continue;
				d[next][(10 * j + c) % m] += d[i][j];
			}
		}
		
	}
	cout << d[up - 1][0] << endl;
	
    return 0;
}