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

int n, k, a[100005];
map<int, int> mp;
bool chk[100005];
int main(){
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	if(k == 1){
		cout << n;
		return 0;
	}
	sort(a, a+n);
	for(int i=0; i<n; i++) mp[a[i]] = i;
	int ret = 0;
	for(int i=n-1; i>=0; i--){
		if(mp.find(a[i]) == mp.end()) continue;
		ret++;
		if(a[i] % k == 0 && mp.find(a[i] / k) != mp.end()){
			mp.erase(mp.find(a[i] / k));
		}
	}
	cout << ret;
}