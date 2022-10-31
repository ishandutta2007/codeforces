#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res,f[1005000],sz[1005000];
vector<int> v[300500];

void dfs(int x,int fa){
	sz[x]++;
	int l=-1,r=-1;
	for(auto i:v[x]){
		if(i==fa)continue;
		if(l==-1)l=i;
		else r=i;
		dfs(i,x);
		sz[x]+=sz[i];
	}
	if(r!=-1){
		f[x]=max(f[l]+sz[r],f[r]+sz[l])-1;
	}
	else if(l!=-1){
		f[x]=sz[l]-1;
	}
}

int main(void){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
    	cin>>n;
    	res=n;
    	for(i=1;i<=n;i++){
    		v[i].clear();
    		f[i]=sz[i]=0;
		}
    	for(i=1;i<n;i++){
    		cin>>j>>k;
    		v[j].push_back(k);
    		v[k].push_back(j);
		}
		dfs(1,0);
		cout<<f[1]<<'\n';
	}
}