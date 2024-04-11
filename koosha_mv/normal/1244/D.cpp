#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
long long mn=1e18,am=-1,mark[100099],ver[100099],s[100099],g[100099][2],c[3][100099],deg[100099];
int dp(int v,int mod){
	mark[v]=1;
	ver[v]=mod;
	f(i,0,s[v]){
		if(mark[g[v][i]]==0)
			dp(g[v][i],(mod+1)%3);
	}
	return 0;
}
int fr(int x,int y){
	if(y<3)
		return (x+y)%3;
	if(y==3){
		if(x==1) return 2;
		if(x==2) return 1;
	}
	if(y==4){
		if(x==0) return 2;
		if(x==2) return 0;
	}
	if(y==5){
		if(x==1) return 0;
		if(x==0) return 1;
	}
	return x;
}
int main(){
	long long dg1,n,x,y,sum=0;
	cin>>n;
	f(i,1,n+1) cin>>c[0][i];
	f(i,1,n+1) cin>>c[1][i];
	f(i,1,n+1) cin>>c[2][i];
	f(i,1,n){
		cin>>x>>y;
		deg[x]++,deg[y]++;
		if(deg[x]>2 || deg[y]>2){cout<<-1;return 0;}
		g[x][s[x]]=y,s[x]++;
		g[y][s[y]]=x,s[y]++;
	}
	f(i,1,n+1){
		if(deg[i]==1){dg1=i;break;}
	}
	dp(dg1,0);
	f(j,0,6){
		sum=0;
		f(i,1,n+1){
			sum+=c[fr(ver[i],j)][i];
		}
		if(sum<mn){
			mn=sum;
			am=j;
		}
	}
	cout<<mn<<endl;
	f(i,1,n+1) cout<<fr(ver[i],am)+1<<" ";
}