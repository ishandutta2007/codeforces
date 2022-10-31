#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 nmsl1
#define x2 nmsl2
#define y1 nmsl3
#define y2 nmsl4
int i,j,k,n,m,t,a[1050][1050],f1[81],f2[81],i1,i2,g[41][41],it,res,x1,x2,y1,y2;
queue<pair<int,int> >q[41],q2;
bool vis[1050][1050];

#define chk(x,y) if(!vis[x][y]&&a[x][y]!=i&&a[x][y]){vis[x][y]=1;q2.push({x,y});}


int main(){
	scanf("%d%d%d",&n,&m,&k);
	memset(g,1,sizeof(g));
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			q[a[i][j]].push({i,j});
		}
	}
	for(i=1;i<=k;i++){
		i1=0;
		memset(vis,0,sizeof(vis));
		aaa:;
		while(!q[i].empty()){
			auto [x,y]=q[i].front();q[i].pop();
			it=a[x][y];
			g[i][it]=min(g[i][it],i1);
			
			chk(x+1,y);
			chk(x-1,y);
			chk(x,y+1);
			chk(x,y-1);
		}
		if(!q2.empty()){
			swap(q[i],q2);i1++;
			goto aaa;
		}
	}
	for(i1=1;i1<=k;i1++){
		for(i=1;i<=k;i++){
			for(j=1;j<=k;j++){
				g[i][j]=min(g[i][j],g[i][i1]+g[i1][j]+1);
			}
		}
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1==x2&&y1==y2){
			puts("0");continue;
		}
		
		res=abs(x1-x2)+abs(y1-y2);
		memset(f1,1,sizeof(f1));
		memset(f2,1,sizeof(f2));
		for(i=x1-k;i<=x1+k;i++){
			for(j=y1-k;j<=y1+k;j++){
				if(i<=0||i>n||j<=0||j>m){continue;}
				f1[a[i][j]]=min(f1[a[i][j]],abs(i-x1)+abs(j-y1));
			}
		}
		
		for(i=x2-k;i<=x2+k;i++){
			for(j=y2-k;j<=y2+k;j++){
				if(i<=0||i>n||j<=0||j>m){continue;}
				f2[a[i][j]]=min(f2[a[i][j]],abs(i-x2)+abs(j-y2));
			}
		}
		
		for(i=1;i<=k;i++){
			for(j=1;j<=k;j++){
				res=min(res,f1[i]+f2[j]+1+g[i][j]+(i!=j));
			}
		}
		printf("%d\n",res);
	}
}