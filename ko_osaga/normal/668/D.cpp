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
 
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
 
using namespace __gnu_pbds;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
 
 
int n;
 
int a[1000005], t[1000005], x[1000005];
vector<int> cmpt, cmpx;
 
ordered_set s[1000005], d[1000005];
 
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%d %d %d",&a[i], &t[i], &x[i]);
		cmpt.push_back(t[i]);
		cmpx.push_back(x[i]);
	}
	sort(cmpt.begin(), cmpt.end());
	sort(cmpx.begin(), cmpx.end());
	cmpx.resize(unique(cmpx.begin(), cmpx.end()) - cmpx.begin());
	for(int i=0; i<n ;i++){
		t[i] = lower_bound(cmpt.begin(), cmpt.end(), t[i]) - cmpt.begin() + 1;
		x[i] = lower_bound(cmpx.begin(), cmpx.end(), x[i]) - cmpx.begin() + 1;
	}
	for(int i=0; i<n; i++){
		if(a[i] == 1){
			s[x[i]].insert(t[i]);
		}
		if(a[i] == 2){
			d[x[i]].insert(t[i]);
		}
		if(a[i] == 3){
			int cnt = s[x[i]].order_of_key(t[i]) - d[x[i]].order_of_key(t[i]);
			printf("%d\n",cnt);
		}
	}
}