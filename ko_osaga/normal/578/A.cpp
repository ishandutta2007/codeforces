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

lint a, b;

int main(){
	cin >> a >> b;
	if(a < b) cout << -1;
	else{
		lint g = 2 * ((a-b) / (b*2));
		lint h = 2 * ((a+b) / (b*2));
		double ret = 1.0 * (a + b) / h;
		if(g) ret = min(ret, 1.0 * (a - b) / g);
		printf("%.12f",ret);
	}
}