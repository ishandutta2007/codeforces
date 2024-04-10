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

int n;
int a[maxn];
ll sum = 0;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> n) {
		for (int i = 0; i < n; i++)
			cin >> a[i];
		
		sum = 0;
		vector<char> ans(n, 0);
		for (int i = n - 1; i >= 0; i--) {
			if (sum > 0) {
				ans[i] = '-';
				sum -= a[i];
			} else {
				ans[i] = '+';
				sum += a[i];
			}
		}
		if (sum < 0)
			for (int i = 0; i < n; i++)
				ans[i] = (ans[i] == '-' ? '+' : '-');
		for (int i = 0; i < n; i++)
			cout << ans[i];
		cout << endl;
	}


	return 0;
}