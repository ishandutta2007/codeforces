#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>


using namespace std;

#define ll long long

const int maxn = 1001;
const double eps = 1e-8;


int n;
bool ans = false;
pair<int,int> a[maxn];
pair<int,int> p[maxn][maxn];

pair<int, int> getp(int x, int y) {
	if (p[x][y] == make_pair(x, y))
		return p[x][y];
	else
		return p[x][y] = getp(p[x][y].first, p[x][y].second);
}

void merge(pair<int,int> a, pair<int, int> b) {
	pair<int, int> o1 = getp(a.first, a.second);
	pair<int, int> o2 = getp(b.first, b.second);

	p[o1.first][o1.second] = o2;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		p[a[i].first][a[i].second] = a[i];
	}

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			if (a[i].first == a[j].first || a[i].second == a[j].second)
				merge(a[i], a[j]);


	set<pair<int, int> > s;
	for (int i = 0; i < n; i++)
		s.insert(getp(a[i].first, a[i].second));
	cout << (int)s.size() - 1;


	return 0;
}