#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int main(){
	lint l1, r1, l2, r2, k;
	cin >> l1 >> r1 >> l2 >> r2 >> k;
	lint l = max(l1, l2), r = min(r1, r2);
	if(l <= k && k <= r) r--;
	cout << max(r - l + 1, 0ll);
}