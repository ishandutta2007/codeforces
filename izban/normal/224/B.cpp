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

int n, k, a[maxn];
map<int, int> mp;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		mp[a[i]]++;
		if (mp.size() == k) {
			int ans = 0;
			while (--mp[a[ans++]]) ;
			cout << ans << " " << i+1 << "\n";
			return 0;
		}
	}

	cout << "-1 -1\n";

	return 0;
}