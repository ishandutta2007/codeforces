#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
int a[1<<19];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	ll ans=0;
	priority_queue<ll>pq;
	for(int i=n;a[i]!=-1;i--){
		pq.push(-a[i]);
		if(!(i&(i-1))){
			ans+=pq.top();
			pq.pop();
		}
	}
	printf("%lld",-ans);
}