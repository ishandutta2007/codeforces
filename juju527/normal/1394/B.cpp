#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int maxn=2e5+5,maxm=2e5+5;
int n,m,k;
int od[maxn];
vector<pair<int,int>> e[maxn],in[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int res=0;
int use[10][10];
bool ban[10][10][10][10];
int c[10];
void dfs(int x){
	if(x==k+1){
		res++;
//		cout<<"#";
//		for(int i=1;i<=k;i++)cout<<c[i]<<" ";
//		cout<<endl;
		return ;
	}
	for(int i=1;i<=x;i++){
		if(use[x][i])continue;
		c[x]=i;
		for(int v=x+1;v<=k;v++)
			for(int w=1;w<=v;w++)
				if(ban[x][i][v][w])use[v][w]++;
		dfs(x+1);
		for(int v=x+1;v<=k;v++)
			for(int w=1;w<=v;w++)
				if(ban[x][i][v][w])use[v][w]--;
	}
	return ;
}
int ind[maxn];
int main(){
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read();v=read();w=read();
		od[u]++;
		e[u].push_back(make_pair(w,v));
		in[v].push_back(make_pair(w,u));
	}
	for(int i=1;i<=n;i++)sort(e[i].begin(),e[i].end());
	for(int x=1;x<=n;x++){
		memset(use,0,sizeof(use));
//		cout<<"!"<<x<<endl;
		for(int i=0;i<in[x].size();i++){
			int y=in[x][i].se;
			int c=lower_bound(e[y].begin(),e[y].end(),make_pair(in[x][i].fi,x))-e[y].begin()+1;
//			cout<<y<<" "<<c<<endl;
			use[od[y]][c]=1;
		}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=i;j++){
				if(!use[i][j])continue;
				for(int u=i+1;u<=k;u++){
					for(int v=1;v<=u;v++){
						if(!use[u][v])continue;
						ban[i][j][u][v]=1;
					}
				}
			}
		}
	}
	memset(use,0,sizeof(use));
	for(int i=1;i<=k;i++){
		for(int j=1;j<=i;j++){
			for(int x=1;x<=n;x++)ind[x]=0;
			bool flag=0;
			for(int x=1;x<=n;x++){
				if(od[x]^i)continue;
				ind[e[x][j-1].se]++;
				if(ind[e[x][j-1].se]>1){flag=1;break;}
			}
			use[i][j]=flag;
		}
	}
	dfs(1);
   	printf("%d\n",res);
	return 0;
}