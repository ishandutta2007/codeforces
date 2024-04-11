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

int main(){
	lint n;
	cin >> n;
	lint p = 81 % n;
	for(int i=0; i<18; i++){
		p *= 2;
		p %= n;
		p *= 5;
		p %= n;
	}
	lint incr = n - p;
	printf("%lld %lld", incr, (lint)1e18 + incr - 1);
}