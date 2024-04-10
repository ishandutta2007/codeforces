#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ff(i,a,b)for(int i=a,_e=b;i<_e;++i)
#define db double
using namespace std;
const int N=20005,M=105,O=(1<<15)+5;
const db inf=6e7;
int n,m,t,x;
int a[M],b[M],c[M],p[M][N],su[M][N];
db f[55][N],f2[105][N];
int h[O],Q;
bool can[M];
db _c[O],_s[O];
db g[55][O],G[O];
void init(int n){
	const db pi=acos(-1);
	for(Q=1;Q<=n;Q<<=1);
	for(int i=1;i*2<Q;i<<=1)ff(j,0,i)_c[i+j]=cos(pi*j/(i*2)),_s[i+j]=sin(pi*j/(i*2));
}
void pre(int n){
	for(Q=1;Q<=n;Q<<=1);
	ff(i,1,Q)h[i]=(h[i>>1]>>1)|(i&1?Q>>1:0);
}
#define dxt(x,y)(x+=y,y=x-y*2)
void dht(db *a,int sig){
	if(Q==1)return;
	ff(i,1,Q)if(h[i]>i)swap(a[i],a[h[i]]);
	for(int i=0;i<Q;i+=2)dxt(a[i],a[i+1]);
	int w1,w2,w3,w4;db T1,T2;
	for(int i=1,i2;(i2=i*2)<Q;i<<=1)for(int j=0;j<Q;j+=i*4){
		dxt(a[j],a[j+i2]);dxt(a[j+i],a[j+i*3]);
		ff(k,1,i){
			w1=j+k;w2=j+i2-k;w3=w1+i2;w4=w2+i2;
			T1=_c[i+k]*a[w3]+_s[i+k]*a[w4];
			T2=_s[i+k]*a[w3]-_c[i+k]*a[w4];
			a[w3]=a[w1]-T1;a[w1]+=T1;
			a[w4]=a[w2]-T2;a[w2]+=T2;
		}
	}
	if(sig){
		db y=1./Q;
		ff(i,0,Q)a[i]*=y;
	}
}
void dot(db *a,db *b){
	static db T1,T2,d[O];
	d[0]=a[0]*b[0];
	ff(i,1,Q){
		T1=a[i];T2=a[Q-i];
		d[i]=(b[i]*(T1+T2)+b[Q-i]*(T1-T2))*0.5;
	}
	ff(i,0,Q)a[i]=d[i];
}
void calc(int l,int r){
	if(l==r){
		fo(i,1,m)
			f[a[i]][l]=min(f[a[i]][l],f2[i][l]+f[b[i]][0]*su[i][l]/100000+c[i]);
		return;
	}
	int mid=l+r>>1;
	calc(l,mid);
	pre((r-l)+(mid-l));
	fo(i,1,n){
		ff(j,0,Q)g[i][j]=0;
		fo(j,l,mid)g[i][j-l]=f[i][j];
		dht(g[i],0);
	}
	fo(i,1,m){
		ff(j,0,Q)G[j]=0;
		fo(j,1,r-l)G[j]=p[i][j]/(db)100000;
		dht(G,0);
		dot(G,g[b[i]]);
		dht(G,1);
		fo(j,mid+1,r)f2[i][j]+=G[j-l];
	}
	calc(mid+1,r);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>t>>x;
	init(t+(t+2>>1));
	fo(i,1,m){
		cin>>a[i]>>b[i]>>c[i];
		fo(j,1,t)cin>>p[i][j];
		fd(j,1,t)su[i][j]=su[i][j+1]+p[i][j];
	}
	fo(i,1,n-1)fo(j,0,t+1)f[i][j]=inf;
	f[n][0]=x;f[0][0]=inf;
	for(;;){
		int w=0;
		fo(i,1,n)if(!can[i]&&f[i][0]<f[w][0])w=i;
		if(!w)break;
		can[w]=1;
		fo(i,1,m)if(b[i]==w)f[a[i]][0]=min(f[a[i]][0],f[w][0]+c[i]);
	}
	calc(1,t+1);
	printf("%.10lf",f[1][t+1]);
}