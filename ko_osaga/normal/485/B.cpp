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
typedef pair<lint, lint> pi;

int n, x[1005], y[1005];

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x[i] >> y[i];
	}
	sort(x, x+n); sort(y, y+n);
	int dx = max(x[n-1] - x[0], y[n-1] - y[0]);
	cout << 1ll * dx * dx;
}