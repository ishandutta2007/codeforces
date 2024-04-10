#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(2)

int i,j,k,n,m,t,k1,k0,st,ed,x,y;
double sb[2][25][25],res[25],p1,p2,p[25],tmp;
vector<int> v[25];
int main(){
	scanf("%d%d%d%d",&n,&m,&st,&ed);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(i=1;i<=n;i++){
		scanf("%lf",&p[i]);
	}
	sb[1][st][ed]=1;
	int c=clock();
	while(clock()-c<=900){
		t++;
		k0=t&1;k1=1-k0;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(i==j){res[i]+=sb[k0][i][j];continue;}
				
				sb[k1][i][j]+=sb[k0][i][j]*p[i]*p[j];
				
				tmp=sb[k0][i][j]*(1-p[i])*(1-p[j])/v[i].size()/v[j].size();
				for(auto ii:v[i]){
					for(auto jj:v[j]){
						sb[k1][ii][jj]+=tmp;
					}
				}
				
				tmp=sb[k0][i][j]*(1-p[i])*p[j]/v[i].size();
				for(auto ii:v[i]){
					sb[k1][ii][j]+=tmp;
				}
				
				tmp=sb[k0][i][j]*p[i]*(1-p[j])/v[j].size();
				for(auto jj:v[j]){
					sb[k1][i][jj]+=tmp;
				}
			}
		}
		memset(sb[k0],0,sizeof(sb[k0]));
	}
	for(i=1;i<=n;i++){
		printf("%.20lf ",res[i]);
	}
}