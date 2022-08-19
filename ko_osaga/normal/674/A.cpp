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

int n, a[5005];

struct data{
	int cnt[5005];
	int occ, occidx;
	void init(){
		occ = 0;
		occidx = -1;
		memset(cnt, 0, sizeof(cnt));
	}
	void add(int x){
		cnt[x]++;
		if(cnt[x] > occ){
			occ = cnt[x];
			occidx = x;
		}
		if(cnt[x] == occ && occidx > x){
			occidx = x;
		}
	}
	int query(){
		return occidx;
	}
}data;

int ret[5005];

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++){
		data.init();
		for(int j=i; j<n; j++){
			data.add(a[j]);
			ret[data.query()]++;
			// query
		}
	}
	for(int i=1; i<=n; i++){
		printf("%d ",ret[i]);
	}
}