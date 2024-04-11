#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, a[200005];
char str[200005]; 

int main(){
	cin >> n >> str;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	int ret = 2e9 + 1900;
	for(int i=0; i<n; i++){
		if(str[i] == 'R' && str[i+1] == 'L'){
			ret = min(ret, a[i+1] - a[i]);
		}
	}
	if(ret > 2e9){
		puts("-1");
	}
	else{
		printf("%d\n", ret / 2);
	}
}