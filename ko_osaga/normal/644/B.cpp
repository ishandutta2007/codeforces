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

struct t1{
	lint t, d, i;
}a[200005];

int n, b;
lint ret[200005];

struct que{
	t1 q[200005];
	int rear, front;
	void pop(lint s, lint e){
		while(front < rear){
			if(q[front].t == -1){
				q[front].t = s;
			}
			if(q[front].t + q[front].d <= e){
				ret[q[front].i] = q[front].t + q[front].d;
				s = q[front].t + q[front].d;
				front++;
			}
			else break;
		}
	}
	int size(){
		return rear - front;
	}
	void push(t1 t){
		t.t = -1;
		q[rear++] = t;
	}
}que;

int main(){
	memset(ret, -1, sizeof(ret));
	cin >> n >> b;
	for(int i=0; i<n; i++){
		scanf("%lld %lld",&a[i].t, &a[i].d);
		a[i].i = i+1;
	}
	int lst = a[0].t;
	for(int i=0; i<n; i++){
		que.pop(lst, a[i].t);
		if(que.size() <= b){
			que.push(a[i]);
		}
		lst = a[i].t;
	}
	que.pop(lst, 1e18);
	for(int i=1; i<=n; i++){
		printf("%lld ",ret[i]);
	}
}