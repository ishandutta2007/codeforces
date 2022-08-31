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
typedef pair<double, int> pi;

int cnt[105], n;

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			int t; cin >> t;
			if(t == 3) cnt[i]++, cnt[j]++;
			if(t == 2) cnt[j]++;
			if(t == 1) cnt[i]++;
		}
	}
	cout << count(cnt+1, cnt+n+1, 0) << endl;
	for(int i=1; i<=n; i++) if(!cnt[i]) printf("%d ",i);
}