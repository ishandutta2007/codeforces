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

int p[200005], n;

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		int t; scanf("%d",&t);
		p[t] = i;
	}
	lint ret = 0;
	for(int i=1; i<n; i++){
		ret += abs(p[i+1] - p[i]);
	}
	cout << ret;
}