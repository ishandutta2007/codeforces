#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

#define b(x) (1<<((x)-1))
int i,j,k,n,m,t,a[300500],b[300500],fa[300500],x,y,vis[300500],ans[300500],it,z;
set<int> s;
queue<int> q,q2;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1;i<=n;i++)scanf("%d",&b[i]);
	for(i=0;i<n;i++)s.insert(i);
	q.push(n);vis[n]=1;
	
	while(!q.empty()){
		while(!q.empty()){
			x=q.front();q.pop();
			//cout<<x<<endl;
			while(!s.empty()){
				z=min(n,x+b[x]);
				auto it=s.upper_bound(z);it--;
				y=*it;
				if((z-y)>a[z]){
					break;
				}
				fa[y]=x;
				//printf("nmsl%d %d %d\n",x,y,b[y]);
				if(y==0){goto aaa;}
				s.erase(y);
				q2.push(y);
			}
		}
		swap(q,q2);
	}
	aaa:;
	if(!fa[0]){
		puts("-1");return 0;
	}
	x=0;
	while(1){
		ans[++it]=x;
		x=fa[x];
		if(x==n)break;
	}
	cout<<it<<endl;
	for(i=it;i>=1;i--){
		printf("%d ",ans[i]);
	}
}