#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))
int i,j,k,n,m,t,f[10050000][2],g[10050000][2][2],it,res,sb;

void add(int w,int id,int sb){
	int i,j,k,cur=0,t1;
	for(i=29;i>=0;i--){
		j=((w>>i)&1);
		k=((id>>i)&1);
		g[cur][j][k]=max(g[cur][j][k],sb);
		if(f[cur][j^k]==-1)f[cur][j^k]=++it;
		cur=f[cur][j^k];
		
	}
}

int get(int w,int id,int dep,int cur){
	if(cur==-1)return 0;
	if(dep<0)return 0;
	int j,k,i,x,y,res=0;
	x=((w>>dep)&1);
	y=((id>>dep)&1);
	for(i=0;i<=1;i++)for(j=0;j<=1;j++){
		if(g[cur][i][j]==0)continue;
		if((x^j)>(i^y)){
			res=max(res,g[cur][i][j]);
		}
	}
	res=max(res,get(w,id,dep-1,f[cur][x^y]));
	return res;
}

int main(){
	memset(f,-1,sizeof(f));
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		res=0;
		for(i=0;i<=it;i++){
			memset(f[i],-1,sizeof(f[i]));
			memset(g[i],0,sizeof(g[i]));
		}
		it=0;
		for(i=0;i<n;i++){
			cin>>k;
			sb=get(k,i,29,0)+1;
			res=max(res,sb);
			add(k,i,sb);
		}
		cout<<res<<'\n';
	}
}