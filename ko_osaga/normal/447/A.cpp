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

bool vis[305];

int main(){
	int p, n;
	cin >> p >> n;
	for(int i=1; i<=n; i++){
		int t;
		cin >> t;
		if(vis[t%p]){
			cout << i;
			return 0;
		}
		vis[t%p] = 1;
	}
	cout << -1;
}