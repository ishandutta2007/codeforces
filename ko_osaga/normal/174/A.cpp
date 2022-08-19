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

int n, b, a[105];

int main(){
	cin >> n >> b;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		b += a[i];
	}
	double r = 1.0 * b / n;
	for(int i=1; i<=n; i++){
		if(r < a[i]){
			puts("-1");
			return 0;
		}
	}
	for(int i=1; i<=n; i++){
		printf("%.10f\n",r - a[i]);
	}
}