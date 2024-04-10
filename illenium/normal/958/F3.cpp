#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define maxn 400005
#define inf 1e9
#define ins insert
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

const double PI=acos(-1.0);
const int mod=1009;

struct C
{
	double r,i;
	C(){}
	inline C(double a,double b){r=a,i=b;}
	inline C operator + (C x){return C(r+x.r,i+x.i);}
	inline C operator - (C x){return C(r-x.r,i-x.i);}
	inline C operator * (C x){return C(r*x.r-i*x.i,r*x.i+i*x.r);}
}w[maxn],A[maxn],B[maxn];
int R[maxn];

inline void FFT(C a[],int n)
{
	rep(i,0,n-1) if(i<R[i]) swap(a[i],a[R[i]]);
	for(int t=n>>1,d=1;d<n;d<<=1,t>>=1)
		for(int i=0;i<n;i+=(d<<1))
			for(int j=0;j<d;j++)
			{
				C tmp=w[t*j]*a[i+j+d];
				a[i+j+d]=a[i+j]-tmp;
				a[i+j]=a[i+j]+tmp;
			}
}

inline void FFT_times(vector <int> &a,vector <int> &b,vector <int> &c)
{
	int n,d;
	rep(i,0,a.size()-1) A[i]=C(a[i],0);
	rep(i,0,b.size()-1) B[i]=C(b[i],0);
	for(n=1,d=0;n<a.size()+b.size()-1;n<<=1,d++);
	rep(i,0,n-1)
	{
		R[i]=(R[i>>1]>>1)|((i&1)<<(d-1));
		w[i]=C(cos(2*PI*i/n),sin(2*PI*i/n));
	}
	rep(i,a.size(),n-1) A[i]=C(0,0);
	rep(i,b.size(),n-1) B[i]=C(0,0);
	FFT(A,n),FFT(B,n);
	rep(i,0,n-1) A[i]=A[i]*B[i],w[i].i*=-1.0;
	FFT(A,n); c.clear();
	rep(i,0,a.size()+b.size()-2) c.pb((ll)((A[i].r/n+0.5))%mod);
}

vector <int> v[maxn],v1,v2,v3;
struct cmp
{
	bool operator()(int a,int b){return v[a].size()<v[b].size();}	
};

int N,M;
int n,m,k,col[maxn],cnt;
multiset <int,cmp> s;
multiset <int>::iterator it;

int main()
{
	n=read(); m=read(); k=read();
	rep(i,1,n) {int x=read(); col[x]++;}
	rep(i,1,n)
	{
		vector <int> tmp; tmp.clear();
		rep(j,1,col[i]+1) tmp.pb(1);
		if(col[i]) v[++cnt]=tmp;
	}
	rep(i,1,cnt) s.ins(i);
	while(s.size()!=1)
	{
		it=s.begin(); int It=*it; v1=v[It]; s.erase(it);
		it=s.begin(); It=*it; v2=v[It]; s.erase(it);
		FFT_times(v1,v2,v3); v[++cnt]=v3; s.ins(cnt);
	}
	printf("%d\n",v[cnt][k]);
	return 0;
}