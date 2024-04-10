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
#include<hash_map>

 
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

vector<vector<int> > pos;

struct query {
	string s1, s2;
	int id;
};

bool operator<(const query& a, const query& b) {
	return (a.s1 < b.s1) || ((a.s1 == b.s1) && (a.s2 < b.s2)) || ((a.s1 == b.s1) && (a.s2 == b.s2) && (a.id < b.id));
}

vector<vector<int> > precalc(const string& s) {
	vector<vector<int> > res(27 * 27 * 27 * 27);
	for (int i = 0; i < s.size(); ++i) {
		int ind = 0;
		for (int j = 0; (j < 4) && (j + i < s.size()); ++j) {
			ind = ind * 27 + (s[i + j] - 'a') + 1;
			res[ind].push_back(i);
		}
	}
	return res;
}

int getInd(const string& s) {
	int res = 0;
	for (int i = 0; i < s.size(); ++i)
		res = res * 27 + (s[i] - 'a') + 1;
	return res;
}

int get(int x, const vector<int>& a, int sz1, int sz2) {
	if (a[0] >= x)
		return max(sz1, a[0] + sz2 - x);
	int l = 0, r = a.size();
	while(r - l > 1) {
		int m = (r + l) / 2;
		if (a[m] < x)
			l = m;
		else
			r = m;
	}
	int res = max(sz2, x - a[l] + sz1);
	if (l + 1 < a.size())
		res = min(res, max(sz1, sz2 + a[l + 1] - x));
	return res;
}

int get(string s1, string s2) {
	int ind1 = getInd(s1), ind2 = getInd(s2);
	int sz1 = s1.size(), sz2 = s2.size();
	if (pos[ind1].size() > pos[ind2].size())
		swap(ind1, ind2), swap(sz1, sz2);
	if (pos[ind1].empty())
		return -1;
	int res = 1000000;
	for (int i = 0; i < pos[ind1].size(); ++i) {
		res = min(res, get(pos[ind1][i], pos[ind2], sz1, sz2));
	}
	return res;
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("INPUT.TXT", "r", stdin);
	//freopen("OUTPUT.TXT", "w", stdout);
	string s;
	cin >> s;
	int qq;
	cin >> qq;
	pos = precalc(s);
	vector<int> res(qq);
	vector<query> q(qq);
	for (int i = 0; i < qq; ++i) {
		string s1, s2;
		cin >> s1 >> s2;
		if (s1 > s2)
			swap(s1, s2);
		q[i].id = i, q[i].s1 = s1, q[i].s2 = s2;
	}
	sort(q.begin(), q.end());
	for (int i = 0; i < q.size(); ++i) {
		if ((i) && (q[i].s1 == q[i - 1].s1) && (q[i].s2 == q[i - 1].s2)) {
			res[q[i].id] = res[q[i - 1].id];
			continue;
		}
		res[q[i].id] = get(q[i].s1, q[i].s2);
	}
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << "\n";
	return 0;
}