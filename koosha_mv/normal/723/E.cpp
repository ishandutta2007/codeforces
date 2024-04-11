#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=209;
int t,n,m,deg[N],ans,edge[N][N],a[N*N][2],u,x,y,b[N][2];
vector<int> g[N];
void dfs(int x){
	f(i,0,g[x].size()){
		if(edge[g[x][i]][x]==1){
			deg[x]--,deg[g[x][i]]--;
			edge[g[x][i]][x]=edge[x][g[x][i]]=2+(x<g[x][i]);
			dfs(g[x][i]);
			return ;
		}
	}
}
int main(){
	cin>>t;
	f(q,0,t){
		ans=0;
		cin>>n>>m;
		f(i,1,n+1) deg[i]=0;
		f(i,0,n+1) g[i].clear();
		f(i,1,n+1) f(j,1,n+1) edge[i][j]=0;
		f(i,0,m){
			Gett(a[i][0],a[i][1]);
			x=a[i][0],y=a[i][1];
			edge[x][y]=1;
			edge[y][x]=1;
			g[x].pb(y);
			g[y].pb(x);
			deg[x]++,deg[y]++;
		}
		while(1){
			u=-1;
			f(i,1,n+1){
				if(deg[i]%2) u=i;
			}
			if(u==-1){
				f(i,1,n+1)
					if(deg[i]%2==0 && deg[i]>0)
						u=i;
			}
			if(u==-1) break;
			dfs(u);
		}
		f(i,1,n+1)
			ans+=(g[i].size()%2==0);
		cout<<ans<<endl;
		f(i,0,m){
			if(edge[a[i][0]][a[i][1]]==2){
				cout<<max(a[i][0],a[i][1])<<" "<<min(a[i][0],a[i][1])<<endl;
			//	b[max(a[i][0],a[i][1])][0]++;b[min(a[i][0],a[i][1])][1]++;
			}
			else{
				cout<<min(a[i][0],a[i][1])<<" "<<max(a[i][0],a[i][1])<<endl;
			//	b[max(a[i][0],a[i][1])][1]++;b[min(a[i][0],a[i][1])][0]++;
			}
		}
		cout<<endl;
	}
}