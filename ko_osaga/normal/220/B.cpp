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

struct query{
	int s, e, idx;
	bool operator<(const query &q)const{
		return s / 300 == q.s / 300 ? (e < q.e) : (s < q.s);
	}
}qr[100005];

int n, q;
int a[100005];
int cnt[100005];
int ret[100005];
int sum;

void add(int x){
	if(cnt[a[x]] == a[x]) sum--;
	cnt[a[x]]++;
	if(cnt[a[x]] == a[x]) sum++;
}

void del(int x){
	if(cnt[a[x]] == a[x]) sum--;
	cnt[a[x]]--;
	if(cnt[a[x]] == a[x]) sum++;
}

int main(){
	scanf("%d %d",&n,&q);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		a[i] = min(a[i], n+1);
	}
	for(int i=0; i<q; i++){
		scanf("%d %d",&qr[i].s, &qr[i].e);
		qr[i].idx = i;
	}
	sort(qr, qr+q);
	int s = 1, e = 0;
	for(int i=0; i<q; i++){
		while(s < qr[i].s) del(s++);
		while(s > qr[i].s) add(--s);
		while(e < qr[i].e) add(++e);
		while(e > qr[i].e) del(e--);
		ret[qr[i].idx] = sum;
	}
	for(int i=0; i<q; i++){
		printf("%d\n",ret[i]);
	}
}