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

lint n, w, h;

lint rx = 1e9, ry = 1e9;

void update(lint x, lint y){
	x = max(x, w);
	y = max(y, h);
	if(rx * ry > x * y){
		rx = x, ry = y;
	}
}

int main(){
	cin >> n >> w >> h;
	for(lint i=1; i*i<=n*6; i++){
		update(i, (n*6 + i - 1) / i);
		lint q = (n*6 + i - 1) / i;
		update(q, (n*6 + q - 1) / q);
	}
	printf("%lld\n%lld %lld",rx*ry,rx,ry);
}