#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
queue<pair<int,int> >q[10];
int n,m,p;
char a[1005];
int d[1005][1005],s[10],ans[1005];
bool check(int x,int y){
	return x&&y&&x<=n&&y<=m&&d[x][y]==-1;
}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=p;++i)scanf("%d",s+i);
	for(int i=1;i<=n;++i){
		scanf("%s",a+1);
		for(int j=1;j<=m;++j){
			if(a[j]=='.')d[i][j]=-1;
			else if(a[j]=='#')d[i][j]=1;
			else q[a[j]-'0'].push(make_pair(i,j)),++ans[a[j]-'0'];
		}
	}
	for(long long turn=1;;++turn){
		bool f=0;
		for(int i=1;i<=p;++i){
			while(!q[i].empty()){
				int x=q[i].front().first,y=q[i].front().second;
				if(d[x][y]>=turn*s[i])break;
				for(int j=0;j<4;++j){
					int x1=x+dx[j],y1=y+dy[j];
					if(check(x1,y1)){
						d[x1][y1]=d[x][y]+1;
						q[i].push(make_pair(x1,y1));
						++ans[i];
					}
				}
				q[i].pop();
			}
			if(!q[i].empty())f=1;
		}
		if(!f)break;
	}
	for(int i=1;i<=p;++i)printf("%d ",ans[i]);
	return 0;
}