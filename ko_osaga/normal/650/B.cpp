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

//  [s, e]  
//   -> 
// (e - s + min(p-s, e-p)) * a
// + b * mismatch(s, e)   
// + e - s + 1
int n, a, b, t;
char str[1000005];
int ps[1000005];

bool ok(int s, int e){
	return 1ll * (e - s + min(n-s, e-n)) * a + 1ll * b * (ps[e] - ps[s-1]) + (e - s + 1) <= t;
}

int main(){
	scanf("%d %d %d %d",&n,&a,&b,&t);
	scanf("%s",str);
	for(int i=0; i<n; i++){
		str[i+n] = str[i];
	}
	for(int i=0; i<2*n; i++){
		ps[i] = (str[i] == 'w') + (i ? ps[i-1] : 0);
	}
	int ret = 0;
	for(int i=n; i<2*n; i++){
		int s = i-n+1, e = n;
		while(s != e){
			int m = (s+e)/2;
			if(ok(m, i)) e = m;
			else s = m+1;
		}
		if(ok(s, i)) ret = max(ret, i - s + 1);
	}
	cout << ret;
}