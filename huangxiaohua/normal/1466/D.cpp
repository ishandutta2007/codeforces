#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

priority_queue<int> q;

int i,j,k,n,t,a[200500],b[200500],x,y;
ll res;

int main(){
	//ios::sync_with_stdio(0);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		while(!q.empty()){
			q.pop();
		}
		res=0;
		memset(b,0,4*n+50);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			res+=a[i];
		}
		for(i=1;i<=n-1;i++){
			scanf("%d%d",&x,&y);
			b[x]++;b[y]++;
		}
		for(i=1;i<=n;i++){
			while(b[i]-1){
				q.push(a[i]);b[i]--;
			}
		}
		printf("%lld",res);
		for(i=1;i<=n-2;i++){
			res+=q.top();q.pop();
			printf(" %lld",res);
		}puts("");
	}
}