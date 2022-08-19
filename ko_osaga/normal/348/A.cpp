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

int n, a[100005];

int trial(int x){
	lint tmp = 0;
	for(int i=0; i<n; i++){
		if(a[i] > x) return 0;
		tmp += x - a[i];
		if(tmp > x) tmp = x;
	}
	return tmp >= x;
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	lint s = 0, e = 2e9;
	while(s != e){
		lint m = (s + e) / 2;
		if(trial(m)) e = m;
		else s = m+1;
	}
	cout << s;
}