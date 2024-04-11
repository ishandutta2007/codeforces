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

int n, k, h;
struct lem{
	int v, m, i;
}a[100005];

int tasn[100005], asn[100005];
vector<pi> tmp[100005];
int ddl[100005];

bool trial(llf x){
	priority_queue<pi> pq;
	for(int i=0; i<n; i++){
		ddl[i] = (int)min((x * a[i].v) / h, (llf)k);
	}
	int pt = 0;
	for(int i=1; i<=k; i++){
		while(pt < n && ddl[pt] < i) pt++;
		if(pt == n) return 0;
		tasn[i] = a[pt].i;
		pt++;
	}
	for(int i=1; i<=k; i++){
		asn[i] = tasn[i];
	}
	return 1;
}

int main(){
	cin >> n >> k >> h;
	for(int i=0; i<n; i++){
		scanf("%d",&a[i].m);
	}
	for(int i=0; i<n; i++){
		scanf("%d",&a[i].v);
		a[i].i = i + 1;
	}
	sort(a, a+n, [&](const lem &a, const lem &b){
		return pi(a.m, a.v) < pi(b.m, b.v);
	});
	llf s = 0, e = 1e9;
	for(int i=0; i<100; i++){
		llf m = (s+e)/2;
		if(trial(m)) e = m;
		else s = m;
	}
	for(int i=1; i<=k; i++){
		printf("%d ",asn[i]);
	}
}