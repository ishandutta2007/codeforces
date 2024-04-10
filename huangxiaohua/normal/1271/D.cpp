#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,m,d[5050],b[5050],c[5050],fa[5050],x,y,res;
vector<pair<int,int> >v;

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&d[i],&b[i],&c[i]);
		d[i-1]=k-d[i];k+=b[i];
		fa[i]=i;
	}d[n]=k;
	for(i=n-1;i>=0;i--){
		d[i]=min(d[i],d[i+1]);
	}
	if(d[0]<0){puts("-1");return 0;}
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		fa[y]=max(fa[y],x);
	}
	for(i=1;i<=n;i++){
		v.push_back({-c[i],fa[i]});
	}
	sort(v.begin(),v.end());
	for(auto it:v){
		i=it.first;j=it.second;
		if(!d[j]){continue;}
		res+=-i;
		for(;j<=n;j++){d[j]--;}
		for(j=n-1;j>=1;j--){
			d[j]=min(d[j],d[j+1]);
		}
	}
	printf("%d",res);
}