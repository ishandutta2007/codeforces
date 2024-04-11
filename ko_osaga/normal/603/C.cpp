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

int n, k;
int p[5] = {0, 1, 0, 1, 2};

int g(int x){
	if(k%2 == 0){
		if(x <= 2) return x;
		return 1 - x%2;
	}
	if(x <= 4) return p[x];
	if(x % 2 == 1) return 0;
	else{
		if(g(x/2) == 1) return 2;
		return 1;
	}
}


int main(){
	int r = 0;
	scanf("%d %d",&n,&k);
	for(int i=0; i<n; i++){
		int t;
		scanf("%d",&t);
		r ^= g(t);
	}
	puts(r ? "Kevin" : "Nicky");
}