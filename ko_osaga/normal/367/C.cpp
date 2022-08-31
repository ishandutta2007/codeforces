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
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int gap(int x){
	if(x % 2 == 1) return x * (x - 1) / 2;
	return x * (x - 1) / 2 + x / 2 - 1;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> v;
	for(int i=0; i<m; i++){
		int x;
		scanf("%*d %d",&x); // what the fuck were they thinking?
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	lint ret = 0;
	for(int i=0; i<m && gap(i+1)<n && i<n; i++){
		ret += v[i];
	}
	cout << ret;
}