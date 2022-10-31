#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x,y,vis[2050][2050],dx,dy,f[2050][2050],res,rx,ry,dep,d[2050][2050],sb,lx,ly,xx,yy;

char s[2050][2050];
pair<int,int> mp[666];
stack<pair<int,int> >st;

int main(){
	mp['L']={0,-1};mp['R']={0,1};
	mp['U']={-1,0};mp['D']={1,0};
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		res=rx=ry=0;
		for(i=0;i<=n+1;i++)vis[i][0]=vis[i][m+1]=-1;
		for(i=0;i<=m+1;i++)vis[0][i]=vis[n+1][i]=-1;
		for(i=1;i<=n;i++)cin>>s[i]+1;
		
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(!vis[i][j]){
					dep=0;
					x=i;y=j;
					while(1){
						dep++;
						if(vis[x][y]){
							sb=0;
							lx=x;ly=y;
							if(vis[x][y]!=-1)sb=1;
							vis[x][y]=-1;
							while(!st.empty()){
								auto [i,j]=st.top();st.pop();
								if(sb){
									f[i][j]=dep-d[x][y];
								}
								else{
									f[i][j]=f[lx][ly]+1;
								}
								if(vis[i][j]==-1)sb=0;
								vis[i][j]=-1;
								lx=i;ly=j;
							}
							break;
						}
						vis[x][y]=1;
						d[x][y]=dep;
						st.push({x,y});
						xx=x;yy=y;
						x+=mp[s[xx][yy]].first;
						y+=mp[s[xx][yy]].second;
					}
				}
			}
		}
		
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(f[i][j]>res){
					res=f[i][j];rx=i;ry=j;
				}
			}
		}
		
		for(i=0;i<=n+1;i++){
			for(j=0;j<=m+1;j++){
				f[i][j]=vis[i][j]=0;
			}
		}
		cout<<rx<<' '<<ry<<' '<<res<<'\n';
	}
}