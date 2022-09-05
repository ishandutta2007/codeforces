#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T&x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int,int> pii;
typedef pair<s64,s64> pss;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define gc (c=getchar())
int read()
{
	char c;
	while(gc<'-');
	if(c=='-')
	{
		int x=gc-'0';
		while(gc>='0')x=x*10+c-'0';
		return -x;
	}
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
#undef gc

const int N=2e5+5,D=998244353;
s64 mi(s64 x,int y=D-2)
{
	s64 ans=1;
	while(y)
	{
		if(y&1)ans=ans*x%D;
		x=x*x%D;y>>=1;
	}
	return ans;
}
void operator +=(pss &a,const pss &b)
{
	(a.first+=b.first)%=D;(a.second+=b.second)%=D;
}
void mul(s64 &a0,s64 &a1,s64 m[2][2])
{
	s64 b0=(m[0][0]*a0+m[0][1]*a1)%D,b1=(m[1][0]*a0+m[1][1]*a1)%D;
	a0=b0;a1=b1;
}
s64 m[2][2],m1[2][2];
namespace SEG
{
#define cl (k*2)
#define cr (cl+1)
#define mid ((l+r)/2)
const s64 T=N*4;
s64 tag[T][2][2],sum[T][2];
int n;	
void mul(int k,s64 m[2][2])
{
	rep(i,0,1)
	{
		::mul(tag[k][0][i],tag[k][1][i],m); 
	} 
	::mul(sum[k][0],sum[k][1],m);
}
void push_down(int k)
{
	if((tag[k][0][0]-1)%D||tag[k][0][1]||tag[k][1][0]||(tag[k][1][1]-1)%D)
	{
		mul(cl,tag[k]);mul(cr,tag[k]);
		rep(i,0,1)
		rep(j,0,1)tag[k][i][j]=i==j;
	}
}
void push_up(int k)
{
	rep(i,0,1)sum[k][i]=(sum[cl][i]+sum[cr][i])%D;
}
void add(int x,const pss &a)
{
	int k=1,l=1,r=n;
	while(1)
	{
		(sum[k][0]+=a.first)%=D;(sum[k][1]+=a.second)%=D;
		//cerr<<k<<endl;
		if(l==r)break;
		push_down(k);
		if(x<=mid)
		{
			k=cl;r=mid;
		}
		else
		{
			k=cr;l=mid+1;
		}
	}
	
//	cerr<<n<<" "<<x<<" "<<a.first<<" "<<a.second<<" "<<"sum[3]="<<sum[3][0]<<" "<<sum[3][1]<<endl;
}
pss query(int x)
{
	int k=1,l=1,r=n;pss ans=pss(0,0);
	while(l!=r)
	{
		push_down(k);
		if(x<=mid)
		{
			ans+=pss(sum[cr][0],sum[cr][1]);
			k=cl;r=mid;
		}
		else
		{
			k=cr;l=mid+1;
		}
	}
	ans+=pss(sum[k][0],sum[k][1]);
	return ans;
}
int ql,qr;
void modify(int k,int l,int r)
{
	if(ql>r||qr<l)return ;
	if(ql<=l&&qr>=r)
	{
		mul(k,m);
		return ;
	}
	push_down(k);
	modify(cl,l,mid);
	modify(cr,mid+1,r);
	push_up(k);
}
void modify(int l,int r)
{
	ql=l;qr=r;
	modify(1,1,n);
}
};
bool cmp(const pii &a,const pii &b)
{
	return 1LL*a.first*b.second<1LL*a.second*b.first;
}
pii q[N];int t;

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read();
	static int x[N],v[N],p[N];
	rep(i,1,n){x[i]=read();v[i]=read();p[i]=read()*mi(100)%D;}
	t=1;
	q[1]=pii(1,0);
	rep(i,2,n)
	{
		q[++t]=pii(x[i]-x[i-1],v[i]+v[i-1]);
		if(v[i]!=v[i-1])q[++t]=pii(x[i]-x[i-1],abs(v[i]-v[i-1]));
	}
	sort(q+1,q+t+1,cmp);
//	cerr<<(q[1]<q[2])<<" "<<(q[2]<q[1])<<endl;
//	rep(i,1,t)cerr<<q[i].first<<" "<<q[i].second<<endl;
	SEG::n=t;
	SEG::add(t,pss(1-p[1],p[1])); 
	rep(i,2,n)
	{
		int j0=lower_bound(q+1,q+t,pii(x[i]-x[i-1],v[i]+v[i-1]),cmp)-q;
		int j1=lower_bound(q+1,q+t,pii(x[i]-x[i-1],abs(v[i]-v[i-1])),cmp)-q;
		pss s0=SEG::query(j0),s1=SEG::query(j1);
		s64 np=p[i];
		
//		cerr<<j0<<" "<<j1<<" "<<t<<endl;
//		cerr<<(pii(x[i]-x[i-1],v[i]+v[i-1])<q[1])<<endl;
		
		rep(i,0,1)
		rep(j,0,1)m[i][j]=(i==0)?1-np:np;
		SEG::modify(1,j0-1);
		
		rep(i,0,1)
		rep(j,0,1)
		if(j==1&&i==0){m1[i][j]=m[i][j];m[i][j]=0;}
		else m1[i][j]=0;
		mul(s0.first,s0.second,m1);
		//cerr<<m1[0][1]<<" "<<s0.first<<" "<<s0.second<<endl;
		SEG::modify(j0,j1-1);
		SEG::add(j0,s0);
		
		int ni=v[i]>v[i-1]?0:1;
		rep(i,0,1)
		rep(j,0,1)
		if(i==j&&(i==ni)){m1[i][j]=m[i][j];m[i][j]=0;}
		else m1[i][j]=0;
		mul(s1.first,s1.second,m1);
		SEG::modify(j1,t);
		SEG::add(j1,s1);
		
		//rep(i,1,t)SEG::query(i);
	}
	auto S=[&](const pss &a)->s64
	{
		return (a.first+a.second)%D;
	};
	s64 ans=0;
	rep(i,1,t-1)(ans+=(S(SEG::query(i))-S(SEG::query(i+1)))*q[i].first%D*mi(q[i].second))%=D;
	cout<<(ans+D)%D<<endl;	
}