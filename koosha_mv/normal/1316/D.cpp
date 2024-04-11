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
const int N=1005,dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int n,mp[N][N][2];
char ans[N][N];
char stt(int x,int y){
	if(x==1) return 'U';
	if(x==-1) return 'D';
	if(y==1) return 'L';
	return 'R';
}
void dfs(int x,int y,int j1,int j2,int ans1,int ans2){
	if(ans1!=0 || ans2!=0) ans[x][y]=stt(ans1,ans2);
	f(i,0,4){
		if(mp[x+dx[i]][y+dy[i]][0]==j1 && mp[x+dx[i]][y+dy[i]][1]==j2 && ans[x+dx[i]][y+dy[i]]!='L' && ans[x+dx[i]][y+dy[i]]!='X' && ans[x+dx[i]][y+dy[i]]!='D' && ans[x+dx[i]][y+dy[i]]!='U' && ans[x+dx[i]][y+dy[i]]!='R')
			dfs(x+dx[i],y+dy[i],j1,j2,dx[i],dy[i]);
	}
}
void dfs1(int x,int y){
	f(i,0,4){
		if(mp[x+dx[i]][y+dy[i]][0]==-1){
			ans[x][y]=stt(-dx[i],-dy[i]);
			ans[x+dx[i]][y+dy[i]]=stt(dx[i],dy[i]);
			dfs(x,y,-1,-1,0,0);
			dfs(x+dx[i],y+dy[i],-1,-1,0,0);
			return ;
		}
	}
	cout<<"INVALID";
	exit(0);
}
int main(){
	gett(n);
	f(i,1,n+1){
		f(j,1,n+1)
			Gett(mp[i][j][0],mp[i][j][1]);
	}
	f(i,1,n+1){
		f(j,1,n+1){
			if(ans[i][j]!='L' && ans[i][j]!='X' && ans[i][j]!='D' && ans[i][j]!='U' && ans[i][j]!='R' && (mp[i][j][0]==-1 || (mp[i][j][0]==i && mp[i][j][1]==j))){
				if(mp[i][j][0]==-1)
					dfs1(i,j);
				else{
					ans[i][j]='X';
					dfs(i,j,i,j,0,0);
				}
			}
		}
	}
	f(i,1,n+1){
		f(j,1,n+1)
			if(ans[i][j]!='L' && ans[i][j]!='X' && ans[i][j]!='D' && ans[i][j]!='U' && ans[i][j]!='R') return cout<<"INVALID",0;
	}
	cout<<"VALID"<<endl;
	f(i,1,n+1){
		f(j,1,n+1)
			cout<<ans[i][j];
		cout<<endl;
	}
}