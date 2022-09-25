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
const int mnth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int n, m[maxn], d[maxn], p[maxn], t[maxn];
int sum[13];
map<int, int> mp;


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    for (int i = 1; i < 13; i++)
		sum[i] = sum[i - 1] + mnth[i - 1];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m[i] >> d[i] >> p[i] >> t[i];
		for (int j = sum[m[i]] + d[i]; j > sum[m[i]] + d[i] - t[i]; j--)
			mp[j] += p[i];
	}

	int ans = 0;
	for (map<int, int> :: iterator it = mp.begin(); it != mp.end(); it++)
		ans = max(ans, it->second);
	cout << ans;
	return 0;
}