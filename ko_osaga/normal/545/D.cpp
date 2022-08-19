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
typedef pair<double, int> pi;

int n, a[100005];

int main(){
	cin >> n;
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	sort(a, a+n);
	lint s = 0;
	int ret = 0;
	for(int i=0; i<n; i++){
		if(s <= a[i]) s += a[i], ret++;
	}
	cout << ret;
}