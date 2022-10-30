#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,mx,mn;
ll res;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);m++;
		priority_queue<int> q;
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			mx=max(mx,k);mn=min(mn,k);
			q.push(k);
		}
		res=0;
		while(m--){
			res+=q.top();q.pop();
		}
		printf("%lld\n",res);
	}
}