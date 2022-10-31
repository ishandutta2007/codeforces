#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,fa[500500],res,x,y;

int find(int x){
	return (fa[x]==x)?x:fa[x]=find(fa[x]);
}

struct sb{
	int x,y,w;
}s[500500];

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=m;i++){
			cin>>s[i].x>>s[i].y>>s[i].w;
		}
		
		res=2147483647;
		for(i=30;i>=0;i--){
			res^=(1<<i);
			for(j=1;j<=n;j++){
				fa[j]=j;
			}
			k=n;
			
			for(j=1;j<=m;j++){
				if((res|s[j].w)!=res)continue;
				x=s[j].x;y=s[j].y;
				if(find(x)==find(y))continue;
				k--;
				fa[find(x)]=find(y);
			}
			//printf("NMSL%d %d\n",j,k);
			
			if(k==1){
				
			}
			else{
				res|=(1<<i);
			}
		}
		
		cout<<res<<'\n';
	}
}