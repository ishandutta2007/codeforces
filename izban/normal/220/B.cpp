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
#include <deque>

using namespace std;

#define ll long long


const int maxn = 100100;

int n, m, a[maxn];
vector<int> v;
int d[500][maxn];
//vector<int> pos[maxn];
map<int, int> cnt;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}

	set<int> st;
	for (int i = 0; i < n; i++) {
		if (a[i] <= cnt[a[i]])
			st.insert(a[i]);
	}
	for (set<int> :: iterator it = st.begin(); it != st.end(); it++)
		v.push_back(*it);

	for (int i = 0; i < v.size(); i++) {
		d[i][0] = a[0] == v[i];
		for (int j = 1; j < n; j++)
			d[i][j] = d[i][j - 1] + (a[j] == v[i]);
	}

	/*for (int i = 0; i < n; i++) {
		vector<int> :: iterator it = lower_bound(v.begin(), v.end(), a[i]);
		if (it != v.end() && *it == a[i])
			pos[it - v.begin()].push_back(i);
	}*/

	for (int i = 0; i < m; i++) {
		int l, r, ans = 0;
		scanf("%d%d", &l, &r);
		l--; r--;
		for (int j = 0; j < v.size(); j++) {
			/*vector<int> :: iterator it1 = lower_bound(pos[j].begin(), pos[j].end(), r), it2 =  lower_bound(pos[j].begin(), pos[j].end(), l);
			if (it1 == pos[j].begin() && (a[*it1] != v[j] || *it1 > r)) continue;
			if (it1 == pos[j].end() || a[*it1] != v[j] || *it1 > r) it1--;
			if (it2 == pos[j].begin() && (a[*it2] != v[j] || *it2 > r)) continue;
			if (it2 == pos[j].end() || a[*it2] != v[j] || *it2 > r) it2--;
			if (*it1 < l || *it2 > r) continue;
			int k = it1 - it2 + 1;*/
			int k = d[j][r] - (l ? d[j][l - 1] : 0);
			if (k == v[j])
				ans++;
		}
		printf("%d\n", ans);
	}

	return 0;
}