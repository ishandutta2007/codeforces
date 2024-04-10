#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <vector>

#define f first
#define s second
#define mp make_pair
#define ll long long

using namespace std;

int n , m , a[2234] , x[2234] , y[2345] , ans;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++) {
		cin >> x[i] >> y[i];     
		ans += min(a[x[i]] , a[y[i]]);
	}
	cout << ans;





}