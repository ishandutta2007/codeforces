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

int n, d, h;

int main(){
	cin >> n >> d >> h;
	if(2 * h < d){
		cout << -1;
		return 0;
	}
	if(d == 1 && n > 2){
		puts("-1");
		return 0;
	}
	for(int i=1; i<=h; i++){
		printf("%d %d\n", i, i+1);
	}
	int p = h+1;
	int needy = d - h;
	if(needy > 0){
		printf("1 %d\n",h+2);
		p++;
		for(int j=1; j<needy; j++){
			printf("%d %d\n",p, p+1);
			p++;
		}
	}
	for(int i=p+1; i<=n; i++){
		printf("%d %d\n",h,i);
	}
}