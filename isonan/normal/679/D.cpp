#include <bits/stdc++.h>

int dis[401][401],n,m,d[401];
double possi[401][401],mx[401];
bool edg[401][401];
std::vector<int>hav[401];
int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=n+1;
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),dis[u][v]=dis[v][u]=edg[u][v]=edg[v][u]=1,++d[u],++d[v];
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=std::min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	double ans=0.;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++)
			for(int k=1;k<=n;k++)
				possi[j][k]=0.;
		for(int j=0;j<=n;j++)hav[j].clear();
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++)
				if(edg[j][k]){
					if(possi[dis[i][j]][k]==0.)hav[dis[i][j]].push_back(k);
					possi[dis[i][j]][k]+=1.0/(double)d[j];
				}
		}
		double now=0.;
		for(int j=0;j<=n;j++){
			double v=0.;
			for(int k=1;k<=n;k++){
				double sum=0.;
				for(int l=0;l<hav[j].size();l++)
					if(mx[dis[k][hav[j][l]]]<possi[j][hav[j][l]]){
						sum-=mx[dis[k][hav[j][l]]];
						mx[dis[k][hav[j][l]]]=possi[j][hav[j][l]];
						sum+=mx[dis[k][hav[j][l]]];
					}
				for(int l=0;l<hav[j].size();l++)
					mx[dis[k][hav[j][l]]]=0.;
				v=std::max(v,sum);
			}
			if(hav[j].size())now+=std::max(v*(1.0/(double)n),1.0/(double)n);
			else now+=v*1.0/(double)n;
		}
		ans=std::max(ans,now);
	}
	printf("%.10lf\n",ans);
}