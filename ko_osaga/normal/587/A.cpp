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

int n, a[1000555];

int main(){
	scanf("%d",&n);
	int t;
	for(int i=1; i<=n; i++){
		scanf("%d",&t);
		a[t]++;
	}
	int ret = 0;
	for(int i=0; i<=1000500; i++){
		a[i+1] += a[i] / 2;
		a[i] %= 2;
		ret+=a[i];
	}
	printf("%d",ret);
}