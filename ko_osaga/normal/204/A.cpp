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

lint ipow[20];

lint solve(lint x){
	lint ret = 0;
	for(int i=1; i<=9; i++){
		if(i > x) break;
		ret++;
		for(int j=1; j<=18; j++){
			lint u = (x - i) / 10;
			u -= ipow[j-1] * i;
			u = min(ipow[j-1], u + 1);
			ret += max(u, 0ll);
		}
	}
	return ret;
}

int main(){
	ipow[0] = 1;
	for(int i=1; i<=18; i++){
		ipow[i] = ipow[i-1] * 10;
	}
	lint l, r;
	cin >> l >> r;
	cout << solve(r) - solve(l-1);
}