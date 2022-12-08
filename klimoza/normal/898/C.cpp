#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>
#include <math.h>
#include <random>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 1e9 + 7;
long double eps = 1e-8;

bool cmp(string x, string y) {
	return x.size() < y.size();
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	map<string, vector<string>> f1;
	map<string, vector<bool>> used;
	string st;
	int t;
	string k;
	vector<string> names;
	for (int i = 0; i < n; i++) {
		cin >> st;
		if (f1[st].empty()) names.push_back(st);
		cin >> t;
		for (int j = 0; j < t; j++) {
			cin >> k;
			f1[st].push_back(k);
		}
	}
	cout << names.size() << endl;
	for (auto name : names) {
		//cout << name << endl;
		used[name].assign(f1[name].size(), true);
		sort(f1[name].begin(), f1[name].end(), cmp);
		int sz = f1[name].size();
		int cnt = sz;
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < i; j++) {
				//cout << f1[name][i] << " " << f1[name][j] << " " << f1[name][i].size() - f1[name][j].size() << endl;
				string cur = "";
				for (int r = ((int)f1[name][i].size() - f1[name][j].size()); r < f1[name][i].size(); r++) {
					//cout << r << endl;
					cur += f1[name][i][r];
				}
				if (cur == f1[name][j] && used[name][j]) {
					used[name][j] = false;
					cnt--;
				}
			}
		}
		cout << name << " " << cnt << " ";
		for (int i = 0; i < sz; i++) {
			if (used[name][i]) {
				cout << f1[name][i] << " ";
			}
		}
		cout << endl;
	}
	//system("pause");
	return 0;
}