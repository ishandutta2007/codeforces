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
const int N = 100 * 1000 + 10;

struct op {
	int t, x, l, c;
};

int main() {
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int m;
	vector<int> pr;
	cin >> m;
	vector<op> oper(m);
	vector<ll> b;
	b.push_back(0);
	ll pos = 0;
	for (int i = 0; i < m; ++i) {
		cin >> oper[i].t;
		if (oper[i].t == 1) {
			cin >> oper[i].x;
			++pos;
			b.push_back(pos);
			//pr.push_back(x);
		}
		else {
			cin >> oper[i].l >> oper[i].c;
			pos += oper[i].l * oper[i].c;
			b.push_back(pos);
		}
		if (pr.size() < N) {
			if (oper[i].t == 1)
				pr.push_back(oper[i].x);
			else {
				int count = 0;
				while((pr.size() < N) && (count < oper[i].c)) {
					++count;
					for (int j = 0; j < oper[i].l; ++j)
						pr.push_back(pr[j]);
				}
			}
		}
	}
	int n;
	cin >> n;
	int ind = 0;
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		--x;
		if (x < pr.size()) {
			cout << pr[x] << " ";
			continue;
		}
		while(x >= b[ind + 1])
			++ind;
		if (oper[ind].t == 1) {
			cout << oper[ind].x << " ";
			continue;
		}
		cout << pr[(x - b[ind]) % oper[ind].l] << " ";
	}
	cout << "\n";
	return 0;
}