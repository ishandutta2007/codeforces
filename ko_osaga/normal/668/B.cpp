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

int a[1000005], n, q;
int c[2];

int main(){
	cin >> n >> q;
	for(int i=1; i<=n; i++) a[i] = i;
	int rot = 0;
	bool fuck = 0;
	for(int i=1; i<=q; i++){
		int x;
		scanf("%d",&x);
		if(x == 2){
			c[fuck]++;
			c[fuck^1]--;
			fuck ^= 1;
		}
		else{
			int u;
			scanf("%d",&u);
			rot += n + u;
			rot %= n;
			if((n+u)&1) fuck ^= 1;
		}
	}
	for(int i=0; i<n; i++){
		int p = i + rot + c[i&1];
		p %= n;
		p += n;
		p %= n;
		a[p] = i+1;
	}
	for(int i=0; i<n; i++) printf("%d ",a[i]);
}