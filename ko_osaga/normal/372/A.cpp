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

int n, a[500005];

bool trial(int x){
	for(int i=0; i<x; i++){
		if(a[i] * 2 > a[n-x+i]) return 0;
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	sort(a, a+n);
	int s = 0, e = n/2;
	while(s != e){
		int m = (s+e+1)/2;
		if(trial(m)) s = m;
		else e = m-1;
	}
	cout << n-s;
}