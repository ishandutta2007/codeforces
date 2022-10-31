#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n,m,st,ed,res=2e9,tmp,x,a[10500],yes;
bitset<1005> vis[10005];
queue<int> q,q2;
queue<pair<int,int> >q1;

int main(){
	scanf("%*d%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	scanf("%d%d",&st,&ed);
	q.push(1);
	aaa:;
	while(!q.empty()){
		x=q.front();q.pop();
		if(a[n]-a[x]<=st){yes=1;res=min(res,tmp+a[n]-a[x]);continue;}
		if(yes){continue;}
		q1.push({x,st});
		while(!q1.empty()){
			auto [x,y]=q1.front();q1.pop();
			if(vis[x][y]==1){continue;}
			vis[x][y]=1;
			if(!y){
				if(vis[x][st]==0){
					q2.push(x);
				}
			}
			if(x>1&&a[x]-a[x-1]<=y&&!vis[x-1][y-(a[x]-a[x-1])]){
				q1.push({x-1,y-(a[x]-a[x-1])});
			}
			if(x<n&&a[x+1]-a[x]<=y&&!vis[x+1][y-(a[x+1]-a[x])]){
				q1.push({x+1,y-(a[x+1]-a[x])});
			}
		}
	}
	if(yes){printf("%d",res);return 0;}
	if(!q2.empty()){
		swap(q,q2);tmp+=st+ed;goto aaa;
	}
	puts("-1");
}