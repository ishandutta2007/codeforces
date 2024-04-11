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

int n, k;

set<int> s;
vector<int> ret;

int main(){
	cin >> n >> k;
	if(n == 4 || k <= n){
		cout << -1;
		return 0;
	}
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	s.insert(a);
	s.insert(b);
	s.insert(c);
	s.insert(d);
	for(int i=1; i<=n; i++){
		if(s.find(i) == s.end()){
			ret.push_back(i);
		}
	}
	printf("%d %d ", a, c);
	for(int i=0; i<n-4; i++){
		printf("%d ",ret[i]);
	}
	printf("%d %d\n", d, b);
	puts("");
	printf("%d %d ", c, a);
	for(int i=0; i<n-4; i++){
		printf("%d ",ret[i]);
	}
	printf("%d %d\n", b, d);
}