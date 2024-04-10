#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll f[100500][20][2][2],a[100500][5];

int get(int a,int b,int c,int d){
	int i,j,k;
	k=max({a,b,c,d});
	if(a==k)i=b;
	else i=k+k-a;
	if(c==k)j=d;
	else j=k+k-c;
	return abs(i-j);
}

ll fuck(int x,int y,int x1,int y1){
	ll f0=1e18,f1=1e18,g1,g0;
	if(x1==0)f0=0;
	else f1=0;
	int i,j,k,t;
	for(i=19,j=(1<<19);i>=0;i--,j/=2){
		if(x+j>y)continue;
		g0=min(f0+f[x][i][0][0],f1+f[x][i][1][0]);
		g1=min(f0+f[x][i][0][1],f1+f[x][i][1][1]);
		f0=g0;f1=g1;
		x+=j;
	}
	if(y1)return f1;
	return f0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<n;i++)for(j=1;j<=4;j++)cin>>a[i][j];
	for(i=1;i<n-1;i++){
		f[i][0][0][0]=1+get(a[i][1]+1,a[i][2],a[i+1][1],a[i+1][2]);
		f[i][0][0][1]=1+get(a[i][1]+1,a[i][2],a[i+1][3],a[i+1][4]);
		f[i][0][1][0]=1+get(a[i][3],a[i][4]+1,a[i+1][1],a[i+1][2]);
		f[i][0][1][1]=1+get(a[i][3],a[i][4]+1,a[i+1][3],a[i+1][4]);
	}
	for(t=1;t<=18;t++){
		int sb=(1<<t)/2;
		for(i=1;i<=n-1;i++){
			if(i+sb>=n)break;
			f[i][t][0][0]=min( f[i][t-1][0][0]+f[i+sb][t-1][0][0],f[i][t-1][0][1]+f[i+sb][t-1][1][0] );
			f[i][t][0][1]=min( f[i][t-1][0][0]+f[i+sb][t-1][0][1],f[i][t-1][0][1]+f[i+sb][t-1][1][1] );
			f[i][t][1][0]=min( f[i][t-1][1][0]+f[i+sb][t-1][0][0],f[i][t-1][1][1]+f[i+sb][t-1][1][0] );
			f[i][t][1][1]=min( f[i][t-1][1][0]+f[i+sb][t-1][0][1],f[i][t-1][1][1]+f[i+sb][t-1][1][1] );
		}
	}
	cin>>t;
	while(t--){
		int x1,y1,x2,y2,p1,p2;
		cin>>x1>>y1>>x2>>y2;
		p1=max(x1,y1);p2=max(x2,y2);
		if(p1>p2){swap(x1,x2);swap(y1,y2);swap(p1,p2);}
		if(p1==p2){cout<<get(x1,y1,x2,y2)<<'\n';continue;}
		ll res=1e18;
		res=min(res,get(x1,y1,a[p1][1],a[p1][2])+fuck(p1,p2-1,0,0)+get(x2,y2,p2,a[p2-1][2]));
		res=min(res,get(x1,y1,a[p1][3],a[p1][4])+fuck(p1,p2-1,1,0)+get(x2,y2,p2,a[p2-1][2]));
		res=min(res,get(x1,y1,a[p1][1],a[p1][2])+fuck(p1,p2-1,0,1)+get(x2,y2,a[p2-1][3],p2));
		res=min(res,get(x1,y1,a[p1][3],a[p1][4])+fuck(p1,p2-1,1,1)+get(x2,y2,a[p2-1][3],p2));
		cout<<res+1<<'\n';
	}
}