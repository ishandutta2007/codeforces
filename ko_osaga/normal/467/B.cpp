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
const int mod = 1e9 + 9;

int a[1005], n, m, k;

int hamming(int x, int y){
	int ret = 0;
	for(int i=0; i<n; i++){
		if((x >> i) % 2 != (y >> i) % 2){
			ret++;
		}
	}
	return ret;
}


int main(){
	cin >> n >> m >> k;
	for(int i=0; i<=m; i++){
		cin >> a[i];
	}
	int ret = 0;
	for(int i=0; i<m; i++){
		if(hamming(a[i], a[m]) <= k) ret++;
	}
	cout << ret;
}