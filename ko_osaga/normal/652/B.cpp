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

int n, a[1005];

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	int s = 0, e = n-1;
	sort(a, a+n);
	for(int i=0; i<n; i++){
		if(i%2 == 0) printf("%d ",a[s++]);
		else printf("%d ",a[e--]);
	}
}