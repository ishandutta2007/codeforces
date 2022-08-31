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

int n, a[105], b[105], ret;

bool ok(int x, int y){
	return x != y && abs(x - y) <= 2;
}
int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			for(int k=0; k<j; k++){
				if(ok(a[i], a[j]) && ok(a[j], a[k]) && ok(a[k], a[i])){
					puts("YES");
					return 0;
				}
			}
		}
	}
	puts("NO");
}