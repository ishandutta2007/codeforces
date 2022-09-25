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
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n, m, a[maxn], b[maxn], fct[maxn];
vector<int> v, e[2 * maxn];

void getv() {
	set<int> st;
	for (int i = 0; i < n; i++) {
		st.insert(a[i]);
		st.insert(b[i]);
	}
	for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
		v.push_back(*it);
	}
}

int getpos(int x) {
	return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	scanf("%d", &m);
	getv();
	
	for (int i = 0; i < n; i++) {
		e[getpos(a[i])].push_back(i);
		e[getpos(b[i])].push_back(i);
	}
	
	for (int i = 0; i < v.size(); i++)
		sort(e[i].begin(), e[i].end());


	int ans = 1;
	for (int i = 0; i < v.size(); i++) {
		int k = e[i].size();
		int cnt = 0;
		for (int j = 0; j < k - 1; j++)
			cnt += e[i][j] == e[i][j + 1];
		for (int j = 1; j <= k; j++) {
			int x = j;
			while (cnt && x % 2 == 0) {
				cnt--;
				x /= 2;
			}
			ans = 1LL * ans * x % m;
		}
	}
	cout << ans << endl;

	return 0;
}