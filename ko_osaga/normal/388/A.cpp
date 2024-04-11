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

int n, a[105];

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	for(int i=1; i<=n; i++){
		bool bad = 0;
		for(int j=0; j<n; j++){
			if(a[j] < j / i){
				bad = 1;
				break;
			}
		}
		if(!bad){
			printf("%d",i);
			return 0;
		}
	}
}