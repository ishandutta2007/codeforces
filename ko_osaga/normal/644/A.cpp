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

int ret[105][105];

int main(){
	int n, a, b;
	cin >> n >> a >> b;
	int p = 0, q = 0;
	for(int i=2; i<=a+b; i++){
		for(int j=1; j<=a && j<i; j++){
			if(i - j <= b){
				if(i%2 == 0) ret[j][i-j] = ++p;
				else ret[j][i-j] = ++q;
			}
		}
	}
	int cnt = 0;
	if(p > q) cnt = 2 * q + 1;
	if(p == q) cnt = 2 * p;
	if(p < q) cnt = 2 * p + 1;
	if(cnt < n){
		puts("-1");
		return 0;
	}
	if(p >= q){
		for(int i=1; i<=a; i++){
			for(int j=1; j<=b; j++){
				ret[i][j] *= 2;
				if((i + j) % 2 == 0) ret[i][j]--;
			}
		}
	}
	else{
		for(int i=1; i<=a; i++){
			for(int j=1; j<=b; j++){
				ret[i][j] *= 2;
				if((i + j) % 2 == 1) ret[i][j]--;
			}
		}
	}
	for(int i=1; i<=a; i++){
		for(int j=1; j<=b; j++){
			if(ret[i][j] > n) printf("0 ");
			else printf("%d ",ret[i][j]);
		}
		puts("");
	}
}