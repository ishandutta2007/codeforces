#include<bits/stdc++.h>
using namespace std;
const int N=155;
struct mat{int a[N][N];}ept,A,e;
bitset<N> a[N],b[N];
int n;
mat mul(mat A,mat B){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			a[i][j]=A.a[i][j],b[i][j]=B.a[j][i];
	mat c=ept;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		c.a[i][j]=(a[i]&b[j]).any();
	return c;
}
mat power(mat a,int b){
	mat ans=e;
	while (b){
		if (b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}return ans;
}
int ans=2e9;
struct wi{int x,y,d;}w[N];
bool comp(wi x,wi y){
	return x.d<y.d;
}
mat now;
int w1[N],ne[N],la[N],t,m;
void link(int x,int y){
	w1[++t]=y;
	ne[t]=la[x];
	la[x]=t;
}
int vis[N],dis[N],d[N];
void bfs(){
	int l=0,r=1;
	for (int i=1;i<=n;i++){
		vis[i]=0;
		if (now.a[1][i]){
			vis[i]=1;
			d[++r]=i;
			dis[i]=0;
		}
	}
	while (l<r){
		int x=d[++l];
		for (int y=la[x];y;y=ne[y]){
			int z=w1[y];
			if (!vis[z]){
				d[++r]=z;
				vis[z]=1;
				dis[z]=dis[x]+1;
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)e.a[i][i]=1;
//	now=A=e;
	now.a[1][1]=1;
	for (int i=1;i<=m;i++)
		scanf("%d%d%d",&w[i].x,&w[i].y,&w[i].d);
	sort(w+1,w+m+1,comp);
	for (int i=1;i<=m;i++){
		now=mul(now,power(A,w[i].d-w[i-1].d));
		A.a[w[i].x][w[i].y]=1;
		link(w[i].x,w[i].y);
		bfs();
		if (vis[n])ans=min(ans,dis[n]+w[i].d);
	}
	if (ans>=15e8)
		cout<<"Impossible"<<endl;
	else 
		cout<<ans<<endl;
}