#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,f[200500],x,y,l,r,md,res;
vector<int> v[200500];

int dfs(int x,int fa){
	int mx=0,mx2=0,mn=2e9,k=0,num=0;
	for(auto i:v[x]){
		if(i==fa){continue;}
		k=dfs(i,x);
		f[x]=max(f[x],f[i]);
		mn=min(mn,k);
		num++;
		if(k>=mx){mx2=mx;mx=k;}
		else{
			if(k>=mx2){mx2=k;}
		}
	}
	if(!num){return 1;}
	if(num==1){f[x]=max(f[x],mx);return mx+1;}
	if(x==1){
		f[x]=max(f[x],max(mx2+1,mx));return 0;
	}
	f[x]=max(f[x],mx+1);
	return mn+1;
}

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			v[i].clear();
			f[i]=0;
		}
		for(i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1,0);
		printf("%d\n",f[1]);
	}
}