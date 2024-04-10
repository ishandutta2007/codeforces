#include<bits/stdc++.h>

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double llf;
typedef std::pair<int,int> pii;

#define xx first
#define yy second

template<typename T> inline T max(T a,T b){return a>b?a:b;}
template<typename T> inline T min(T a,T b){return a<b?a:b;}
template<typename T> inline T abs(T a){return a>0?a:-a;}
template<typename T> inline bool repr(T &a,T b){return a<b?a=b,1:0;}
template<typename T> inline bool repl(T &a,T b){return a>b?a=b,1:0;}
template<typename T> inline T gcd(T a,T b){T t;if(a<b){while(a){t=a;a=b%a;b=t;}return b;}else{while(b){t=b;b=a%b;a=t;}return a;}}
template<typename T> inline T sqr(T x){return x*x;}
#define mp(a,b) std::make_pair(a,b)
#define pb push_back
#define I __attribute__((always_inline))inline
#define mset(a,b) memset(a,b,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))

#define fo0(i,n) for(int i=0,i##end=n;i<i##end;i++)
#define fo1(i,n) for(int i=1,i##end=n;i<=i##end;i++)
#define fo(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define fd0(i,n) for(int i=(n)-1;~i;i--)
#define fd1(i,n) for(int i=n;i;i--)
#define fd(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define foe(i,x)for(__typeof((x).end())i=(x).begin();i!=(x).end();++i)
#define fre(i,x)for(__typeof((x).rend())i=(x).rbegin();i!=(x).rend();++i)

struct Cg{I char operator()(){return getchar();}};
struct Cp{I void operator()(char x){putchar(x);}};
#define OP operator
#define RT return *this;
#define UC unsigned char
#define RX x=0;UC t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;\
if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define RL if(t=='.'){lf u=0.1;for(t=P();t>='0'&&t<='9';t=P(),u*=0.1)x+=u*(t-'0');}if(f)x=-x
#define RU x=0;UC t=P();while(t<'0'||t>'9')t=P();x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define TR *this,x;return x;
I bool IS(char x){return x==10||x==13||x==' ';}template<typename T>struct Fr{T P;I Fr&OP,(int&x)
{RX;if(f)x=-x;RT}I OP int(){int x;TR}I Fr&OP,(ll &x){RX;if(f)x=-x;RT}I OP ll(){ll x;TR}I Fr&OP,(char&x)
{for(x=P();IS(x);x=P());RT}I OP char(){char x;TR}I Fr&OP,(char*x){char t=P();for(;IS(t);t=P());if(~t){for(;!IS
(t)&&~t;t=P())*x++=t;}*x++=0;RT}I Fr&OP,(lf&x){RX;RL;RT}I OP lf(){lf x;TR}I Fr&OP,(llf&x){RX;RL;RT}I OP llf()
{llf x;TR}I Fr&OP,(uint&x){RU;RT}I OP uint(){uint x;TR}I Fr&OP,(ull&x){RU;RT}I OP ull(){ull x;TR}};Fr<Cg>in;
#define WI(S) if(x){if(x<0)P('-'),x=-x;UC s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
#define WL if(y){lf t=0.5;for(int i=y;i--;)t*=0.1;if(x>=0)x+=t;else x-=t,P('-');*this,(ll)(abs(x));P('.');if(x<0)\
x=-x;while(y--){x*=10;x-=floor(x*0.1)*10;P(((int)x)%10+'0');}}else if(x>=0)*this,(ll)(x+0.5);else *this,(ll)(x-0.5);
#define WU(S) if(x){UC s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
template<typename T>struct Fw{T P;I Fw&OP,(int x){WI(10);RT}I Fw&OP()(int x){WI(10);RT}I Fw&OP,(uint x){WU(10);RT}
I Fw&OP()(uint x){WU(10);RT}I Fw&OP,(ll x){WI(19);RT}I Fw&OP()(ll x){WI(19);RT}I Fw&OP,(ull x){WU(20);RT}I Fw&OP()
(ull x){WU(20);RT}I Fw&OP,(char x){P(x);RT}I Fw&OP()(char x){P(x);RT}I Fw&OP,(const char*x){while(*x)P(*x++);RT}
I Fw&OP()(const char*x){while(*x)P(*x++);RT}I Fw&OP()(lf x,int y){WL;RT}I Fw&OP()(llf x,int y){WL;RT}};Fw<Cp>out;

const int N=200007;

struct node
{
	ll sum;
	int cnt;
}f[533333];

inline void pu(int x)
{
	f[x].sum=f[x<<1].sum+f[x<<1|1].sum;
	f[x].cnt=f[x<<1].cnt+f[x<<1|1].cnt;
}

inline void mod(int x,int l,int r,int p,int v)
{
	if(l==r)f[x].sum=v,f[x].cnt=1;
	else
	{
		int t=(l+r)>>1;
		if(p<=t)mod(x<<1,l,t,p,v);
		else mod(x<<1|1,t+1,r,p,v);
		pu(x);
	}
}

inline ll qry(int x,int l,int r,int k)
{
	if(f[x].cnt==k)return f[x].sum;
	if(!k)return 0;
	int t=(l+r)>>1;
	if(f[x<<1|1].cnt>=k)return qry(x<<1|1,t+1,r,k);
	return qry(x<<1,l,t,k-f[x<<1|1].cnt)+f[x<<1|1].sum;
}

inline void modl(int x,int l,int r)
{
	if(l==r)f[x].sum=0,f[x].cnt=0;
	else
	{
		int t=(l+r)>>1;
		if(f[x<<1|1].cnt)modl(x<<1|1,t+1,r);
		else modl(x<<1,l,t);
		pu(x);
	}
}

inline void build(int x,int l,int r)
{
	f[x].sum=0,f[x].cnt=0;
	if(l^r)
	{
		int t=(l+r)>>1;
		build(x<<1,l,t);
		build(x<<1|1,t+1,r);
	}
}

int n,m,s[N];
ll t;
pii v[N];

inline ll cost()
{
	int a=f[1].cnt%m;
	if(!a&&f[1].cnt)a=m;
	ll x=qry(1,1,n,a),y=f[1].sum-x;
	return y*2+x;
}

inline void solve()
{
	in,n,m,t;
	fo1(i,n)in,s[i];
	fo1(i,n)v[i]=mp(s[i],i);
	std::sort(v+1,v+n+1);
	build(1,1,n);
	int ans=0,pos=1;
	fo1(i,n)
	{
		mod(1,1,n,v[i].yy,v[i].xx);
		if(i!=n&&v[i+1].xx==v[i].xx)continue;
		while(cost()>t)modl(1,1,n);
		if(repr(ans,f[1].cnt))pos=v[i].xx;
	}
	out,ans,' ',pos,'\n';
}

int main()
{
	//freopen("in.txt","r",stdin);
	for(int T=in;T--;solve());
}