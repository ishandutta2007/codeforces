#include<bits/stdc++.h>
using namespace std;
#define py puts("Yes");
#define pn puts("No");
#define N 605
int a[N][N],b[N][N];
struct ee{
	short x,y;int v;
	bool operator < (ee aa)const{
		return v<aa.v;
	}
}tmp;
priority_queue<ee>pq;
int n,m,i,x,y,q,k,j,ans,v,eee,c[N][N]; 
int main(){
//	freopen("a.txt","r",stdin);		
	cin>>n>>m;memset(c,0xc3f,sizeof(c));
	for(i=1;i<=m;++i)cin>>x>>y>>v,b[x][y]=b[y][x]=c[x][y]=c[y][x]=v;
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	for(k=1;k<=n;++k)
	c[j][k]=min(c[j][k],c[j][i]+c[i][k]);
	cin>>q;
	for(i=1;i<=q;++i)cin>>x>>y>>v,a[x][y]=a[y][x]=v,tmp.x=x,tmp.y=y,tmp.v=a[x][y],pq.push(tmp);
	while(pq.size()){
		tmp=pq.top();pq.pop();x=tmp.x;y=tmp.y;v=tmp.v;++eee;
		if(a[x][y]==v){
			for(i=1;i<=n;++i){ 
				if(i==x||i==y)continue;
				if(b[x][i]&&a[i][y]<v-c[x][i]){
					a[i][y]=a[y][i]=v-c[x][i];
					tmp.x=i;tmp.y=y;tmp.v=a[i][y];
					pq.push(tmp);
				}
				if(b[y][i]&&a[x][i]<v-c[y][i]){
					a[x][i]=a[i][x]=v-c[y][i];
					tmp.x=x;tmp.y=i;tmp.v=a[i][x];
					pq.push(tmp);
				}
			}	 
		}
	}//acout<<eee<<"\n";
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			if(b[i][j]&&a[i][j]>=b[i][j])++ans;
		}
	}cout<<ans/2;
}