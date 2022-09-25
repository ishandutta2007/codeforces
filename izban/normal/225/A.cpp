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


const int maxn = 1 << 17;

int n, top, a[maxn], b[maxn], down[maxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	cin >> n >> top;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];

	down[0] = 7-top;
	for (int i = 1; i < n; i++) {
		vector<int> vis(7, 0), v;
		vis[a[i]] = vis[7-a[i]] = vis[b[i]] = vis[7-b[i]] = 1;
		for (int j = 1; j < 7; j++)
			if (!vis[j])
				v.push_back(j);
		if (v[0] == down[i-1])
			down[i] = v[1];
		else if (v[1] == down[i-1])
			down[i] = v[0];
		else {
			cout << "NO";
			return 0;
		}
	}
	
	cout << "YES";

	return 0;
}