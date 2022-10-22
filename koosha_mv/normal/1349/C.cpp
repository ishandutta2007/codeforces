#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1002,dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

int n,m,t,dist[2][N][N],ans[N][N];
char a[N][N];
queue<pair<int,int> > q[2];
ll x,y,p;

void nt(char x){
	if(x=='1') cout<<0<<endl;
	else cout<<1<<endl;
}
bool ok(int x,int y){
	if(a[x][y]=='1' || a[x][y]=='0') return 1;
	return 0;
}
void bfs(int s){
	while(q[s].size()){
		pair<int,int> u=q[s].front();
		q[s].pop();
		f(i,0,4)
			if(ok(u.F+dx[i],u.S+dy[i]) && dist[s][u.F+dx[i]][u.S+dy[i]]==-1)
				dist[s][u.F+dx[i]][u.S+dy[i]]=dist[s][u.F][u.S]+1,q[s].push(mp(u.F+dx[i],u.S+dy[i]));
	}
}
int main(){
	cin>>n>>m>>t;
	f(i,1,n+1)
		f(j,1,m+1)
			cin>>a[i][j];
	f(i,0,N) f(j,0,N) dist[0][i][j]=dist[1][i][j]=-1;
	f(i,1,n+1)
		f(j,1,m+1){
			if(a[i][j]=='1'){
				f(l,0,4)
					if(a[i+dx[l]][j+dy[l]]=='1'){
						dist[1][i][j]=0;
						q[1].push(mp(i,j));
						break;
					}
			}
			else{
				f(l,0,4)
					if(a[i+dx[l]][j+dy[l]]=='0'){
						dist[0][i][j]=0;
						q[0].push(mp(i,j));
						break;
					}
			}
		}
	bfs(0);
	bfs(1);
	f(i,1,n+1) f(j,1,m+1){
		ans[i][j]=min(dist[0][i][j],dist[1][i][j]);
		if(dist[0][i][j]==-1) ans[i][j]=dist[1][i][j];
		if(dist[1][i][j]==-1) ans[i][j]=dist[0][i][j];
	}
	f(i,0,t){
		cin>>x>>y>>p;
		if(p<=ans[x][y] || (p-ans[x][y])%2==0 || ans[x][y]==-1) cout<<a[x][y]<<endl;
		else nt(a[x][y]);
	}
}