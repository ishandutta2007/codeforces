#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,dep[500500],fa[500500][22],lg[500500],a[500500],mn=2e9,rt;
ll res,tmp;
vector<int> v[500500];

void dfs1(int x,int f){
	ll ans=1e18;
	dep[x]=dep[f]+1;
	for(int i=0;i<=21;i++){
		if(!i)fa[x][0]=f;
		else fa[x][i]=fa[fa[x][i-1]][i-1];
		if(!fa[x][i])fa[x][i]=rt;
		tmp=a[fa[x][i]];
		tmp=tmp*(i+1)+a[x];
		ans=min(ans,tmp);
	}
	if(f)res+=ans;
	for(auto i:v[x]){
		if(i==f){continue;}
		dfs1(i,x);
	}
	
}

int main(){
	a[0]=2e9;
	for(i=1;i<=500005;i++){
		lg[i]=lg[i>>1]+1;
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mn=min(mn,a[i]);
	}
	for(i=1;i<n;i++){
		scanf("%d%d",&j,&k);
		v[j].push_back(k);
		v[k].push_back(j);
	}
	for(i=1;i<=n;i++){
		if(a[i]==mn){
			rt=i;dfs1(i,0);break;
		}
	}
	cout<<res;
}