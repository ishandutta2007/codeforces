#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[1005],it,mx,res=1,l,r,md,fa[1050];
vector<int> v[1050];

void dfs(int x,int f){
	fa[x]=f;a[++it]=x;
	for(auto i:v[x]){
		if(i!=f)dfs(i,x);
	}
}

int ask(int x){
	printf("? %d ",x);
	for(;x;x--)printf("%d ",a[x]);
	cout<<endl;cin>>x;return x;
}

int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&j,&k);
		v[j].push_back(k);
		v[k].push_back(j);
	}
	dfs(1,0);
	mx=ask(n);
	l=2;r=n-1;
	while(l<=r){
		md=(l+r)/2;
		if(mx==ask(md))r=md-1;
		else l=md+1,res=max(res,md);
	}
	printf("! %d %d",a[res+1],fa[a[res+1]]);
}