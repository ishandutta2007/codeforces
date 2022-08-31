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

int n;
string a, b;
lint cnt[128];


int main(){
	cin >> n >> a >> b;
	double tot = 0, ret = 0;
	for(int i=1; i<=n; i++) tot += (1.0 * i) *i;
	for(int i=n-1; i>=0; i--){
		cnt[b[i]] += n-i;
		ret += 1.0 * cnt[a[i]] * (i+1);
	}
	memset(cnt, 0, sizeof(cnt));
	for(int i=0; i<n; i++){
		ret += 1.0 * (n-i) * cnt[a[i]];
		cnt[b[i]] += i+1;
	}
	printf("%.10f",1.0 * ret / tot);
}