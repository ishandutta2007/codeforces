#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

int i,j,n,m,u[2050][2050];
ll w,it,f[2050][2050],res=5e18,res1=5e18,res2=5e18,a[2050][2050];

queue<pair<int,int> >q;

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>w;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	
	for(i=0;i<=m+1;i++){
		a[0][i]=a[n+1][i]=-1;
	}
	for(i=0;i<=n+1;i++){
		a[i][0]=a[i][m+1]=-1;
	}
	
	/*for(i=0;i<=n+1;i++){
		for(j=0;j<=m+1;j++){
			printf("%3d ",a[i][j]);
		}puts("");
	}*/
	
	q.push({1,1});u[1][1]=1;
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;
		
		q.pop();
		
		if(a[x-1][y]!=-1&&!u[x-1][y]){
			f[x-1][y]=f[x][y]+1;u[x-1][y]=1;
			q.push({x-1,y});
		}
		
		if(a[x+1][y]!=-1&&!u[x+1][y]){
			f[x+1][y]=f[x][y]+1;u[x+1][y]=1;
			q.push({x+1,y});
		}
		
		if(a[x][y-1]!=-1&&!u[x][y-1]){
			f[x][y-1]=f[x][y]+1;u[x][y-1]=1;
			q.push({x,y-1});
		}
		
		if(a[x][y+1]!=-1&&!u[x][y+1]){
			f[x][y+1]=f[x][y]+1;u[x][y+1]=1;
			q.push({x,y+1});
		}
	}
	
	/*for(i=0;i<=n+1;i++){
		for(j=0;j<=m+1;j++){
			printf("%3d ",f[i][j]);
		}puts("");
	}*/
	if(f[n][m]){res=f[n][m]*w;}
	
	memset(f,0,sizeof(f));
	memset(u,0,sizeof(u));
	q.push({1,1});u[1][1]=1;
	
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;
		q.pop();
		if(a[x-1][y]!=-1&&!u[x-1][y]){
			f[x-1][y]=f[x][y]+1;u[x-1][y]=1;
			q.push({x-1,y});
		}
		
		if(a[x+1][y]!=-1&&!u[x+1][y]){
			f[x+1][y]=f[x][y]+1;u[x+1][y]=1;
			q.push({x+1,y});
		}
		
		if(a[x][y-1]!=-1&&!u[x][y-1]){
			f[x][y-1]=f[x][y]+1;u[x][y-1]=1;
			q.push({x,y-1});
		}
		
		if(a[x][y+1]!=-1&&!u[x][y+1]){
			f[x][y+1]=f[x][y]+1;u[x][y+1]=1;
			q.push({x,y+1});
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(u[i][j]&&a[i][j]>0){
				res1=min(res1,f[i][j]*w+a[i][j]);
			}
		}
	}
	
	memset(f,0,sizeof(f));
	memset(u,0,sizeof(u));
	q.push({n,m});u[n][m]=1;
	
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;
		q.pop();
		if(a[x-1][y]!=-1&&!u[x-1][y]){
			f[x-1][y]=f[x][y]+1;u[x-1][y]=1;
			q.push({x-1,y});
		}
		
		if(a[x+1][y]!=-1&&!u[x+1][y]){
			f[x+1][y]=f[x][y]+1;u[x+1][y]=1;
			q.push({x+1,y});
		}
		
		if(a[x][y-1]!=-1&&!u[x][y-1]){
			f[x][y-1]=f[x][y]+1;u[x][y-1]=1;
			q.push({x,y-1});
		}
		
		if(a[x][y+1]!=-1&&!u[x][y+1]){
			f[x][y+1]=f[x][y]+1;u[x][y+1]=1;
			q.push({x,y+1});
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(u[i][j]&&a[i][j]>0){
				res2=min(res2,f[i][j]*w+a[i][j]);
			}
		}
	}
	
	if(res1!=5e18&&res2!=5e18){
		res=min(res,res1+res2);
	}
	cout<<(res==5e18?-1:res);
}