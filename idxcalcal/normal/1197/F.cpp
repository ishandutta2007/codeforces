#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
inline char gc(){
	static char buf[rlen],*ib,*ob;
	(ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin));
	return ib==ob?-1:*ib++;
}
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
const int mod=998244353;
typedef long long ll;
inline int add(const int&a,const int&b){return a+b>=mod?a+b-mod:a+b;}
inline int dec(const int&a,const int&b){return a>=b?a-b:a-b+mod;}
inline int mul(const int&a,const int&b){return (ll)a*b%mod;}
inline void Add(int&a,const int&b){a=a+b>=mod?a+b-mod:a+b;}
inline void Dec(int&a,const int&b){a=a>=b?a-b:a-b+mod;}
inline void Mul(int&a,const int&b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,a=mul(a,a))if(p&1)Mul(ret,a);return ret;}
struct Mat{
	int a[64][64],n,m;
	Mat(int k=0,int n0=64,int m0=64){
		n=n0,m=m0;
		for(ri i=0;i<n0;++i)for(ri j=0;j<m0;++j)a[i][j]=i==j?k:0;
	}
	friend inline Mat operator+(const Mat&a,const Mat&b){
		Mat ret(0,a.n,b.m);
		for(ri i=0;i<a.n;++i)for(ri j=0;j<a.m;++j)ret.a[i][j]=add(a.a[i][j],b.a[i][j]);
		return ret;
	}
	friend inline Mat operator*(const Mat&a,const Mat&b){
		Mat ret(0,a.n,b.m);
		for(ri i=0;i<a.n;++i)for(ri k=0;k<a.m;++k)if(a.a[i][k])
		for(ri j=0;j<b.m;++j)Add(ret.a[i][j],mul(a.a[i][k],b.a[k][j]));
		return ret;
	}
	friend inline Mat operator^(Mat a,int p){
		Mat ret=a;
		for(--p;p;p>>=1,a=a*a)if(p&1)ret=ret*a;
		return ret;
	}
}pw[32],ban[4];
typedef pair<int,int> pii;
const int N=1005;
int n,a[N],f[2][4],cur=0,tmp[4],sum[4];
vector<pii>upd[N];
bool Ban[4];
inline void update(int x,Mat&t){for(ri i=31;~i;--i)if((x>>i)&1)t=pw[i]*t;}
int main(){
	n=read();
	for(ri i=1;i<=n;++i)a[i]=read();
	for(ri a,b,c,tt=read();tt;--tt){
		a=read(),b=read(),c=read();
		upd[a].push_back(pii(b,c));
	}
	for(ri tt=1;tt<4;++tt){
		for(ri i=1;i<4;++i)Ban[i]=(bool)read();
		for(ri s1,s2,s3,s4,sta=0;sta<64;++sta){
			s1=sta&3,s2=(sta>>2)&3,s3=(sta>>4)&3,s4=0;
			for(ri i=0;i<4;++i)tmp[i]=0;
			Ban[3]&&(tmp[s1]=1),Ban[2]&&(tmp[s2]=1),Ban[1]&&(tmp[s3]=1);
			while(tmp[s4])++s4;
			ban[tt].a[s2|(s3<<2)|(s4<<4)][sta]=1;
		}
	}
	pw[0]=ban[1]+ban[2]+ban[3];
	for(ri i=1;i<32;++i)pw[i]=pw[i-1]*pw[i-1];
	f[cur=0][0]=1;
	for(ri pre,tt=1;tt<=n;++tt){
		sort(upd[tt].begin(),upd[tt].end());
		Mat t(0,64,1);
		t.a[63][0]=1;
		pre=0;
		for(ri pos,col,i=0;i<upd[tt].size();++i){
			pos=upd[tt][i].fi,col=upd[tt][i].se;
			update(pos-1-pre,t);
			t=ban[col]*t;
			pre=pos;
		}
		update(a[tt]-pre,t);
		for(ri i=0;i<4;++i)sum[i]=0;
		for(ri i=0;i<64;++i)Add(sum[(i>>4)&3],t.a[i][0]);
		cur^=1;
		for(ri i=0;i<4;++i){
			f[cur][i]=0;
			for(ri j=0;j<4;++j)Add(f[cur][i],mul(f[cur^1][j],sum[i^j]));
		}
	}
	cout<<f[cur][0];
	return 0;
}