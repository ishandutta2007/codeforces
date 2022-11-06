#include<bits/stdc++.h>
using namespace std;
typedef double ld;
const int N=3.5e4;
const ld pi=acos(-1);
struct cx{ld x,y;};
cx operator+(cx a,cx b){return (cx){a.x+b.x,a.y+b.y};}
cx operator-(cx a,cx b){return (cx){a.x-b.x,a.y-b.y};}
cx operator*(cx a,cx b){return (cx){a.x*b.x-a.y*b.y,a.y*b.x+a.x*b.y};}
cx operator/(cx a,ld b){return (cx){a.x/b,a.y/b};}
cx make(ld x){return (cx){x,0};}
cx w[N],a[N],b[N],c[N];
ld f[55][N],s[105][N];
int lgM=15,M=1<<lgM,n,m,T,px[N],py[N],val[N],dis[N],r[N];
ld p[105][N],X,q[105][N];
struct graph{
	int w[N],ne[N],la[N],len[N],t;
	void link(int x,int y,int z){
		w[++t]=y;
		ne[t]=la[x];
		la[x]=t;
		len[t]=z;
	}
	set<pair<int,int> > h;
	void dij(int *s){
		for (int i=1;i<n;i++)s[i]=1e9;
		for (int i=1;i<=n;i++)h.insert(make_pair(s[i],i));
		for (int i=1;i<n;i++){
			int x=h.begin()->second;
			h.erase(h.begin());
			for (int y=la[x];y;y=ne[y]){
				int z=w[y];
				if (s[z]>s[x]+len[y]){
					h.erase(make_pair(s[z],z));
					s[z]=s[x]+len[y];
					h.insert(make_pair(s[z],z));
				}
			}
		}
	}
}G;
void dft(cx *a,int M){
	for (int i=1;i<M;i++){
		r[i]=(r[i>>1]>>1)+(M>>1)*(i&1);
		if (i<r[i])swap(a[i],a[r[i]]);
	}
	for (int n=1,ax=lgM-1;n<M;n<<=1,ax--){
		for (int i=n;i<M;i=(i+1)|n){
			cx A=a[i]*w[(i&(n-1))<<ax];
			a[i]=a[i^n]-A;
			a[i^n]=a[i^n]+A;
		}
	}
}
void idft(cx *a,int M){
	for (int i=1,j=M-1;i<j;i++,j--)swap(a[i],a[j]);
	dft(a,M);
	for (int i=0;i<M;i++)a[i]=a[i]/M;
}
void solve(int l,int r){
	if (l==r){
		for (int i=1;i<=m;i++)
			f[px[i]][l]=min(f[px[i]][l],s[i][l]+val[i]);
		return;
	}
	int M=l+r>>1;
	solve(l,M);
	int n1=r-l+1,n2=M-l+1,Mx=1;
	for (;Mx<=n1+n2;Mx<<=1);
	for (int i=1;i<=m;i++){
		for (int i=0;i<Mx;i++)a[i]=b[i]=make(0);
		for (int j=0;j<n1;j++)a[j]=make(p[i][j]);
		for (int j=0;j<n2;j++)b[j]=make(f[py[i]][j+l]);
		dft(a,Mx);dft(b,Mx);
		for (int i=0;i<Mx;i++)a[i]=a[i]*b[i];
		idft(a,Mx);
		for (int j=M+1;j<=r;j++)s[i][j]+=a[j-l].x;
	}
	solve(M+1,r);
}
int main(){
	cin>>n>>m>>T>>X;
	for (int i=0;i<M;i++)w[i]=(cx){cos(2*pi*i/M),sin(2*pi*i/M)};
	for (int i=1;i<=m;i++){
		int x;
		scanf("%d%d%d",&px[i],&py[i],&val[i]);
		G.link(py[i],px[i],val[i]);
		for (int j=1;j<=T;j++)scanf("%d",&x),p[i][j]=x*1e-5;
		for (int j=T;j>=1;j--)q[i][j]=q[i][j+1]+p[i][j];
		q[i][0]=1;
	}
	G.dij(dis);
	for (int i=1;i<n;i++){
		f[i][0]=dis[i]+X;
		for (int j=1;j<=T+1;j++)f[i][j]=1e20;
	}f[n][0]=X;
	for (int i=1;i<=m;i++){
		for (int j=0;j<=T+1;j++)s[i][j]=f[py[i]][0]*q[i][j];
	}
	solve(1,T+1);
	printf("%.12lf\n",f[1][T+1]);
}