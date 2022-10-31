#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500],f[200500],mx,rt,f1[200500];
ll res;
vector<int> v[200500];
vector<pair<int,int> >ord[200500];
int vis[200500];

void dfs(int x,int fa){
	f[x]=a[x];
	f1[x]=fa;
	for(auto i:v[x]){
		if(i==fa)continue;
		dfs(i,x);
		f[x]=max(f[x],f[i]);
		ord[x].push_back({f[i],i});
	}
	sort(ord[x].begin(),ord[x].end());
	reverse(ord[x].begin(),ord[x].end());
}

void dfs2(int x,int fa){
	if(v[x].size()==1&&x!=rt){
		int y=0;
		while(1){
			if(x==rt){
				if(vis[x]<2){vis[x]++;y=mx;}
				break;
			}
			else if(vis[x])break;
			y=max(y,f[x]);vis[x]=1;x=f1[x];
		}
		res+=y;return;
	}
	for(auto [i,j]:ord[x])dfs2(j,x);
}

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	for(i=1;i<n;i++){
		cin>>j>>k;
		v[j].push_back(k);
		v[k].push_back(j);
	}
	vis[0]=1;
	for(i=1;i<=n;i++){
		if(a[i]==mx){
			if(v[i].size()==1){
				res+=mx;vis[i]++;
			}
			rt=i;dfs(i,0);dfs2(i,0);break;
		}
	}
	cout<<res;
}