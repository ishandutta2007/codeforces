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

int n, a[150005];
bool mark[150005];

int normal_swap(int x){
	int rs = -1e7, re = 1e7;
	if(x % 2 == 1){
		if(x) rs = max(rs, a[x-1]);
		if(x+1 < n) rs = max(rs, a[x+1]);
		rs++;
	}
	if(x % 2 == 0){
		if(x) re = min(re, a[x-1]);
		if(x+1 < n) re = min(re, a[x+1]);
		re--;
	}
	int ret = 0;
	for(int i=0; i<n; i++){
		if(!mark[i] && rs <= a[i] && a[i] <= re){
			if(i%2 == 1){
				if(i && a[x] <= a[i-1]) continue;
				if(i+1 < n && a[x] <= a[i+1]) continue;
				ret++;
			}
			if(i%2 == 0){
				if(i && a[x] >= a[i-1]) continue;
				if(i+1 < n && a[x] >= a[i+1]) continue;
				ret++;
			}
		}
	}
	return ret;
}

bool ok(){
	for(int i=0; i<n-1; i++){
		if(i % 2 == 0 && a[i] >= a[i+1]){
			return 0;
		}
		if(i%2 == 1 && a[i] <= a[i+1]){ 
			return 0;
		}
	}
	return 1;
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	for(int i=0; i<n-1; i++){
		if(i % 2 == 0 && a[i] >= a[i+1]){
			mark[i] = mark[i+1] = 1;
		}
		if(i%2 == 1 && a[i] <= a[i+1]){
			mark[i] = mark[i+1] = 1;
		}
	}
	int t = count(mark, mark + n, true);
	if(t >= 7){
		puts("0");
		return 0;
	}
	int ret = 0;
	vector<int> tmp;
	for(int i=0; i<n; i++){
		if(mark[i]) tmp.push_back(i);
	}
	for(int i=0; i<tmp.size(); i++){
		for(int j=0; j<i; j++){
			swap(a[tmp[i]], a[tmp[j]]);
			if(ok()) ret++;
			swap(a[tmp[i]], a[tmp[j]]);
		}
	}
	if(t == 2){
		ret += normal_swap(tmp[0]);
		ret += normal_swap(tmp[1]);
	}
	if(t == 3){
		ret += normal_swap(tmp[1]);
	}
	cout << ret;
}