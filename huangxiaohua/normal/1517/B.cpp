#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[105][105],sb[105][105],ans[105][105];
vector<vector<int> > v;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		memset(sb,0,sizeof(sb));
		memset(ans,0,sizeof(ans));
		v.clear();
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
				v.push_back({a[i][j],i,j});
			}
		}
		sort(v.begin(),v.end());
		for(i=0;i<m;i++){
			//printf("a%d %d %d\n",v[i][1],v[i][2],i+1);
			sb[v[i][1]][v[i][2]]=i+1;
		}
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				for(k=1;k<=m;k++){
					if(sb[j][k]==i){ans[j][i]=a[j][k];goto aaa;}
				}
				for(k=1;k<=m;k++){
					if(!sb[j][k]){sb[j][k]=i;}
					if(sb[j][k]==i){ans[j][i]=a[j][k];goto aaa;}
				}
				aaa:;
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				printf("%d ",ans[i][j]);
			}puts("");
		}
	}
}