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
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n, m, k;
int a[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> n >> m >> k) {
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		reverse(a, a + n);

		int sum = k, i = 0;
		while (sum < m && i < n) {
			sum += a[i] - 1;
			i++;
		}
		if (sum >= m)
			cout << i;
		else
			cout << -1;
		cout << endl;
	}
	return 0;
}