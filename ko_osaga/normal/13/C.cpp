#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int n, a[5005];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	lint ret = 0;
	priority_queue<int> pq;
	for(int j=0; j<n; j++){
		if(!pq.empty() && pq.top() > a[j]){
			ret += pq.top() - a[j];
			pq.pop();
			pq.push(a[j]);
		}
		pq.push(a[j]);
	}
	printf("%lld\n", ret);
}