#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[400500],d[400500],b[400500],sb,cx,cy,cur,cx0,cy0;
ll res;
set<ll> s;
#define nmsl() cur+=(a[x]==b[x]);b[x]+=ty;cur-=(a[x]==b[x]);

void dfs(int x,int y,int z){
	b[y]++;
	if(x>1){
		if(z)res+=d[y+1]-d[y];
		else res+=d[y]-d[y-1];
	}
	if(x>=m){cx=y;cy=z;return;}
	if(!z){
		if(y==n)dfs(x+1,y-1,z^1);
		else dfs(x+1,y+1,z);
	}
	else{
		if(y==1)dfs(x+1,y+1,z^1);
		else dfs(x+1,y-1,z);
	}
}

void chg(int &x,int &y,int ty){
	if(ty==-1){nmsl();}
	if(!y)res+=(d[x+1]-d[x])*ty;
	else res+=(d[x]-d[x-1])*ty;
	if(!y){x++;if(x>n){x=n-1;y^=1;}}
	else{x--;if(x<1){x=2;y^=1;}}
	if(ty==1){nmsl();}
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&d[i]);
	for(i=n;i>=1;i--)d[i]-=d[1];
	d[0]=-d[2];d[n+1]=d[n]+d[n]-d[n-1];
	scanf("%d",&m);
	for(i=1;i<=m;i++){scanf("%d",&k);a[k]++;}
	dfs(1,1,0);
	for(i=1;i<=n;i++){
		cur+=(a[i]!=b[i]);
	}
	cx0=1;cy0=0;
	for(i=1;i<=n*2+5;i++){
		if(!cur)s.insert(res);
		chg(cx0,cy0,-1);
		chg(cx,cy,1);
	}
	printf("%lld",(s.size()==1)?*s.begin():-1);
}