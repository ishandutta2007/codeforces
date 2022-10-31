#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,n,m,t,x[666],y[666],vis[666],NMSL[666],mn,vis2[666];
ll f[666],jc[666],res;
map<int,int> mp;
vector<int> v;
int dis(int i,int j){
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
	
void dfs(int x){
	vis[x]=1;
	mp[x]=1;
	v.push_back(x);
	int mn=1e9;
	int i,j,k;
	for(i=1;i<=n;i++){
		if(i==x)continue;
		mn=min(mn,dis(i,x));
	}
	for(i=1;i<=n;i++){
		if(vis[i])continue;
		if(dis(i,x)==mn){
			dfs(i);
		}
	}
}

int main(){
	f[0]=1;
	jc[0]=1;
	for(i=1;i<=500;i++)jc[i]=jc[i-1]*i%M;
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	for(i=1;i<=n;i++){
		if(vis2[i])continue;
		mp.clear();v.clear();
		memset(vis,0,sizeof(vis));
		dfs(i);
		if(mp.size()==1)goto aaa;
		mn=dis(v[0],v[1]);
		
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				if(j==k)continue;
				if(!mp[j]&&!mp[k])continue;
				if(mp[j]^mp[k]){
					if(dis(j,k)<=mn)goto aaa;
				}
				else{
					if(dis(j,k)!=mn)goto aaa;
				}
			}
		}
		m=v.size()-1;
		for(j=n;j>=m;j--){
			f[j]+=f[j-m];f[j]%=M;
		}
		for(auto j:v)vis2[j]=1;
		aaa:;
	}
	
	for(i=0;i<n;i++){
		ll tmp=1;
		for(j=1;j<=n-i;j++){
			tmp=tmp*(n+1-j)%M;
		}
		res+=1ll*f[i]*tmp%M;res%=M;
	}
	
	cout<<res;
}