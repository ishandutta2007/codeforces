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
const int INF = 1000 * 1000 + 10;

int f(const vector<int>& a, const vector<int>& b) {
	int i1, j1;
	i1 = j1 = 0;
	int last = -1;
	int res = 0;
	while((i1 < a.size()) || (j1 < b.size())) {
		if ((i1 < a.size()) && (j1 < b.size())) {
			if (a[i1] < b[j1]) {
				if (last != 0)
					++res;
				last = 0;
				++i1;
			}
			else {
				if (last != 1)
					++res;
				last = 1;
				++j1;
			}
			continue;
		}
		if (i1 == a.size()) {
			if (last != 1)
				++res;
			last = 1;
			++j1;
			continue;
		}
		if (j1 == b.size()) {
			if (last != 0)
				++res;
			last = 0;
			++i1;
		}
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> data(n);
	vector<int> count;
	map<int, int> m;
	vector<int> ind;
	for (int i = 0; i < n; ++i) {
		cin >> data[i];
		if (m.find(data[i]) == m.end()) {
			int x = m.size();
			ind.push_back(data[i]);
			count.push_back(1);
			m[data[i]] = x;
		}
		else
			++count[m[data[i]]];
	}
	int res = 0;
	for (int i = 0; i < count.size(); ++i) {
		res = max(res, count[i]);
	}
	if (n < 3) {
		cout << n << endl;
		return 0;
	}
	if (res == 1) {
		cout << 2 << endl;
		return 0;
	}
	vector<vector<int> > pos(ind.size());
	//for (int i = 0; i < pos.size(); ++i) 
		//pos[i].resize(count[i]);
	for (int i = 0; i < n; ++i)
		pos[m[data[i]]].push_back(i);
	
	for (int i = 0; i < pos.size(); ++i) {
		if (pos[i].size() * 2 + 1 <= res)
			continue;
		for (int j = i + 1; j < pos.size(); ++j) {
			if (pos[j].size() * 2 + 1 <= res)
				continue;
			if (pos[i].size() + pos[j].size() <= res)
				continue;
			int cur = f(pos[i], pos[j]);
			res = max(cur, res);
		}
	}
	cout << res << endl;
	return 0;
}