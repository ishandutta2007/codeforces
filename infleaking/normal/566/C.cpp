#include<bits/stdc++.h>
using namespace std;
typedef double ld;
const int N=4e5+10;
int w[N],ne[N],la[N],len[N],t=1,mrk[N];
int n,v[N],size[N],fa[N],mx[N];
void link(int x,int y,int z){
	w[++t]=y;
	ne[t]=la[x];
	la[x]=t;
	len[t]=z;
}
int rt;
void cnt(int x,int fa){
	mx[x]=0;
	size[x]=1;
	for (int y=la[x];y;y=ne[y]){
		int z=w[y];
		if (z==fa||mrk[y])continue;
		cnt(z,x);
		size[x]+=size[z];
		mx[x]=max(mx[x],size[z]);
	}
}
void getr(int x,int fa,int s){
	mx[x]=max(mx[x],s-size[x]);
	if (2*mx[x]<=s)rt=x;
	for (int y=la[x];y;y=ne[y])
		if (!mrk[y]&&w[y]!=fa)getr(w[y],x,s);
}
ld sum1,sum2,sum3;
void calc(int x,int fa,int dep){
	sum1+=v[x]*pow(dep,1.5);
	sum2+=v[x]*pow(dep+1,1.5);
	for (int y=la[x];y;y=ne[y])
		if (w[y]!=fa)calc(w[y],x,dep+len[y]);
}
void calc2(int x,int fa,int dep){
	sum3+=v[x]*(pow(dep-1,1.5)-pow(dep+1,1.5));
	for (int y=la[x];y;y=ne[y])
		if (w[y]!=fa)calc2(w[y],x,dep+len[y]);
}
int ansx=0;
ld ans=1e30;
void solve(int x){
	sum1=sum2=0;
	cnt(x,0);
	getr(x,0,size[x]);
	x=rt;
	calc(x,0,0);
	ld s3=sum1;int z1=x;
	for (int y=la[x];y;y=ne[y]){
		int z=w[y];
		if (mrk[y])continue;
		sum3=sum2;
		calc2(z,x,len[y]);
		if (s3>sum3)s3=sum3,z1=z;
		mrk[y]=mrk[y^1]=1;
	}
	if (ans>sum1)ansx=x,ans=sum1;
	if (z1==x)return;
	else solve(z1);
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&v[i]);
	for (int i=1;i<n;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		link(x,y,z);
		link(y,x,z);
	}
	solve(1);
	printf("%d %.12lf\n",ansx,ans);
}