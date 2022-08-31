#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int p[200005], s[200005], a[200005], x, k, n, r;

int main(){
	cin >> n >> k >> x;
	for(int i=1; i<=n; i++) cin >> a[i];
	r = 1;
	for(int i=0; i<k; i++) r *= x;
	for(int i=1; i<=n; i++) p[i] = p[i-1] | a[i];
	for(int i=n; i; i--) s[i] = s[i+1] | a[i];
	lint ret = 0;
	for(int i=1; i<=n; i++){
		ret = max(ret, p[i-1] | s[i+1] | (1ll * r * a[i]));
	}
	cout << ret;
}