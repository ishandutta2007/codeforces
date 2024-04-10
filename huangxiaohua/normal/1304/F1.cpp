#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t;
int a[55][20500],pre[55][20500],f[55][20500],l,tmp,res;
priority_queue<pair<int,int> >q;
vector<pair<int,int> >v;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			pre[i][j]=pre[i][j-1]+a[i][j];
		}
	}
	for(i=k;i<=m;i++){
		f[1][i]+=pre[1][i]-pre[1][i-k];
		f[1][i]+=pre[2][i]-pre[2][i-k];
		q.push({f[1][i],i});
	}
	int lim;
	for(i=2;i<=n;i++){
		for(j=k;j<=m;j++){
			lim=min(m,j+k);
			for(l=max(k,j-k);l<=lim;l++){
				tmp=0;
				if(l<j){
					tmp=pre[i][j]-pre[i][l];
				}
				else{
					tmp=pre[i][l-k]-pre[i][j-k];
				}
				f[i][j]=max(f[i][j],f[i-1][l]+tmp+pre[i+1][j]-pre[i+1][j-k]);
			}
			v.clear();
			while(!q.empty()){
				auto [x,y]=q.top();q.pop();
				v.push_back({x,y});
				if(abs(y-j)<=k)continue;
				//printf("a%d %d %d %d\n",i,j,x,y);
				f[i][j]=max(f[i][j],x+pre[i][j]-pre[i][j-k]+pre[i+1][j]-pre[i+1][j-k]);
				break;
			}
			for(auto [x,y]:v){
				q.push({x,y});
			}
		}
		while(!q.empty())q.pop();
		for(j=k;j<=m;j++){
			q.push({f[i][j],j});
		}
	}
	for(i=1;i<=n;i++){
		for(j=k;j<=m;j++){
			//printf("%d ",f[i][j]);
			res=max(res,f[i][j]);
		}
		//puts("");
	}
	printf("%d",res);
}