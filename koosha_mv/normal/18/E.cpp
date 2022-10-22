#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=505,Z=26,dx[4]={-1,-1,1,1},dy[4]={-1,1,-1,1};

int n,m,t,ans=N*N,u,v,cnt[N][Z][2];
pair<int,pair<int,int> > cost[N][Z][Z][4],dp[N][Z][Z];
string s[N];

int calc(int row,int x,int y){ return m-cnt[row][x][0]-cnt[row][y][1]; }

void read(){
	f(i,0,N) f(j,0,Z) f(k,0,Z) f(l,0,4) cost[i][j][k][l].F=-1;
	cin>>n>>m;
	f(i,1,n+1){
		cin>>s[i];
		f(j,0,m)
			cnt[i][s[i][j]-'a'][j%2]++;
	}
	
}
pair<int,pair<int,int> > costt(int an,int x,int y,int s){
	if(an==0) return mp(0,mp(0,0));
	if(x<0 || y<0 || x>=Z || y>=Z) return mp(N*N,mp(0,0));
	if(cost[an][x][y][s].F>=0) return cost[an][x][y][s];
	cost[an][x][y][s]=mp(dp[an][x][y].F,mp(x,y));
	if(cost[an][x][y][s]>costt(an,x+dx[s],y,s)) cost[an][x][y][s]=costt(an,x+dx[s],y,s);
	if(cost[an][x][y][s]>costt(an,x,y+dy[s],s)) cost[an][x][y][s]=costt(an,x,y+dy[s],s);
	return cost[an][x][y][s];
}

int main(){
	read();
	f(i,1,n+1)
		f(j,0,Z)
			f(k,0,Z){
				dp[i][j][k]=mp(N*N,mp(0,0));
				if(j!=k){
					f(l,0,4)
						if(costt(i-1,j+dx[l],k+dy[l],l)<dp[i][j][k])
							dp[i][j][k]=costt(i-1,j+dx[l],k+dy[l],l);	
						dp[i][j][k].F+=calc(i,j,k);
					}
			}
	f(i,0,Z)
		f(j,0,Z)
			if(dp[n][i][j].F<ans){
				ans=dp[n][i][j].F;
				u=i,v=j;
			}
			
	f_(i,n,1){
		f(j,0,m){
			if(j%2==0) s[i][j]=char(u+'a');
			else s[i][j]=char(v+'a');
		}
		pair<int,pair<int,int> > io=dp[i][u][v];
		u=io.S.F,v=io.S.S;
			
	}
	cout<<ans<<endl;
	f(i,1,n+1){
		f(j,0,m)
			cout<<s[i][j];
		cout<<endl;
	}
}