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

vector<pi> v;

int n, x[2005], y[2005];

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x[i] >> y[i];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			v.emplace_back(x[i] + x[j], y[i] + y[j]);
		}
	}
	sort(v.begin(), v.end());
	lint ret = 0;
	for(int i=0; i<v.size(); ){
		int e = i;
		while(e < v.size() && v[e] == v[i]) e++;
		ret += (e - i) * (e - i - 1) / 2;
		i =e ;
	}
	cout << ret;
}