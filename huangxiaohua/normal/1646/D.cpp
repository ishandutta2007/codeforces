#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,g[200500][2],f[200500][2],r1,r2,op[200500],nmsl[200500];
vector<int> v[200500];
void dfs(int x,int fa){
	for(auto i:v[x]){
		if(i==fa)continue;
		dfs(i,x);
		f[x][1]+=f[i][0];
		f[x][0]+=max(f[i][0],f[i][1]);
		
		g[x][1]+=g[i][0];
		if(f[i][0]>f[i][1]){
			g[x][0]+=g[i][0];
		}
		else if(f[i][0]<f[i][1]){
			g[x][0]+=g[i][1];
		}
		else g[x][0]+=min(g[i][0],g[i][1]);
	}
	f[x][1]++;
	g[x][1]+=v[x].size();
	g[x][0]++;
}

void dfs2(int x,int fa){
	if(!op[fa]){
		if(f[x][0]>f[x][1]){
			op[x]=0;
		}
		else if(f[x][0]<f[x][1]){
			op[x]=1;
		}
		else{
			op[x]=(g[x][0]>g[x][1]);
		}
	}
	if(!op[x])nmsl[x]=1;
	else nmsl[x]=v[x].size();
	r1+=op[x];r2+=nmsl[x];
	for(auto i:v[x]){
		if(i==fa)continue;
		dfs2(i,x);
	}
}

void NMSL(){
	cout<<"2 2\n1 1";exit(0);
}

int main() {
	ios::sync_with_stdio(0);
	cin>>n;
	if(n==2){NMSL();}
	for(i=1;i<n;i++){
		cin>>j>>k;
		v[j].push_back(k);
		v[k].push_back(j);
	}
	dfs(1,0);
	dfs2(1,0);
	cout<<r1<<' '<<r2<<endl;
	for(i=1;i<=n;i++)cout<<nmsl[i]<<' ';
}