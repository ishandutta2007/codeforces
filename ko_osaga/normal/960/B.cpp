#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int MAXN = 100005;

int n, a[MAXN];

int main(){
	int k1, k2;
	cin >> n >> k1 >> k2;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		a[i] += x;
	}
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		a[i] -= x;
		a[i] = abs(a[i]);
	}
	sort(a, a+n);
	for(int i=0; i<k1+k2; i++){
		int w = max_element(a, a+n) - a;
		if(a[w]) a[w]--;
		else a[w]++;
	}
	lint ans = 0;
	for(int i=0; i<n; i++) ans += 1ll * a[i] * a[i];
	cout << ans << endl;
}