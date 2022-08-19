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
vector<int> tsk[1000005];

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		int t, c;
		cin >> t >> c;
		tsk[t].push_back(c);
	}
	int maxque = 0, cur = 0, lst = 0;
	for(int i=1; i<=1000002; i++){
		if(cur){
			lst = i;
			cur--;
		}
		if(tsk[i].size()){
			cur += tsk[i][0];
			maxque = max(maxque, cur);
		}
	}
	if(cur){
		lst = max(lst, 1000002 + cur);
	}
	cout << lst << " " << maxque;
}