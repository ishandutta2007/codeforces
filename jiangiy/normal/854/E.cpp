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
#define I inline
#define mset(a,b) memset(a,b,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))

#define fo0(i,n) for(int i=0,i##end=n;i<i##end;i++)
#define fo1(i,n) for(int i=1,i##end=n;i<=i##end;i++)
#define fo(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define fd0(i,n) for(int i=(n)-1;~i;i--)
#define fd1(i,n) for(int i=n;i;i--)
#define fd(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define foe(i,x)for(__typeof(x.end())i=x.begin();i!=x.end();++i)

struct Cg{I char operator()(){return getchar();}};
struct Cp{I void operator()(char x){putchar(x);}};
#define OP operator
#define RT return *this;
#define RX x=0;char t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;\
if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define RL if(t=='.'){lf u=0.1;for(t=P();t>='0'&&t<='9';t=P(),u*=0.1)x+=u*(t-'0');}if(f)x=-x
#define RU x=0;char t=P();while(t<'0'||t>'9')t=P();x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define TR *this,x;return x;
I bool IS(char x){return x==10||x==13||x==' ';}template<typename T>struct Fr{T P;I Fr&OP,(int &x)
{RX;if(f)x=-x;RT}I OP int(){int x;TR}I Fr&OP,(ll &x){RX;if(f)x=-x;RT}I OP ll(){ll x;TR}I Fr&OP,(char &x)
{for(x=P();IS(x);x=P());RT}I OP char(){char x;TR}I Fr&OP,(char *x){char t=P();for(;IS(t);t=P());if(~t){for(;!IS
(t)&&~t;t=P())*x++=t;}*x++=0;RT}I Fr&OP,(lf &x){RX;RL;RT}I OP lf(){lf x;TR}I Fr&OP,(llf &x){RX;RL;RT}I OP llf()
{llf x;TR}I Fr&OP,(uint &x){RU;RT}I OP uint(){uint x;TR}I Fr&OP,(ull &x){RU;RT}I OP ull(){ull x;TR}};Fr<Cg>in;
#define WI(S) if(x){if(x<0)P('-'),x=-x;char s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
#define WL if(y){lf t=0.5;for(int i=y;i--;)t*=0.1;if(x>=0)x+=t;else x-=t,P('-');*this,(ll)(abs(x));P('.');if(x<0)\
x=-x;while(y--){x*=10;x-=floor(x*0.1)*10;P(((int)x)%10+'0');}}else if(x>=0)*this,(ll)(x+0.5);else *this,(ll)(x-0.5);
#define WU(S) if(x){char s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
template<typename T>struct Fw{T P;I Fw&OP,(int x){WI(10);RT}I Fw&OP()(int x){WI(10);RT}I Fw&OP,(uint x){WU(10);RT}
I Fw&OP()(uint x){WU(10);RT}I Fw&OP,(ll x){WI(19);RT}I Fw&OP()(ll x){WI(19);RT}I Fw&OP,(ull x){WU(20);RT}I Fw&OP()
(ull x){WU(20);RT}I Fw&OP,(char x){P(x);RT}I Fw&OP()(char x){P(x);RT}I Fw&OP,(const char *x){while(*x)P(*x++);RT}
I Fw&OP()(const char *x){while(*x)P(*x++);RT}I Fw&OP()(lf x,int y){WL;RT}I Fw&OP()(llf x,int y){WL;RT}};Fw<Cp>out;

const int N=200007;

struct query
{
	int p,l,r,i,v;
	inline bool operator<(const query&t)const
	{
		return p<t.p;
	}
}q[N*4];

int n,m,s[N],f[N],ta[N*4];
ll ans[N];

inline int qry(int x)
{
	int r=0;
	for(;x;x^=x&-x)
		r+=f[x];
	return r;
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",s+i);
	int qc=0;
	for(int i=1;i<=m;i++)
	{
		int a,b,x,y;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		ans[i]=(ll)n*(n-1)-(ll)(a-1)*(a-2)-(ll)(x-1)*(x-2)-(ll)(n-b)*(n-b-1)-(ll)(n-y)*(n-y-1);
		//printf("%lld\n",ans[i]);
		if(a!=1&&x!=1)q[qc++]=(query){a-1,1,x-1,i,1};
		if(a!=1&&y!=n)q[qc++]=(query){a-1,y+1,n,i+m,1};
		if(b!=n&&x!=1)q[qc++]=(query){b,1,x-1,i+m*2,-1},ta[i+m*2]=x-1;
		if(b!=n&&y!=n)q[qc++]=(query){b,y+1,n,i+m*3,-1},ta[i+m*3]=n-y;
	}
	std::sort(q,q+qc);
	int lst=0;
	for(int i=0;i<qc;i++)
	{
		while(lst<q[i].p)
		{
			for(int j=s[++lst];j<=n;j+=j&-j)
				f[j]++;
		}
		ta[q[i].i]+=q[i].v*(qry(q[i].r)-qry(q[i].l-1));
		//printf("%d %d %d\n",q[i].i,q[i].v,(qry(q[i].r)-qry(q[i].l-1)));
	}
	//for(int i=1;i<=m;i++)
	//	printf("%d\n",ans[i]);
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<4;j++)ans[i]+=(ll)ta[i+j*m]*(ta[i+j*m]-1);
		//for(int j=0;j<4;j++)printf("%d ",ta[i+j*m]);putchar(10);
		printf("%I64d\n",ans[i]/2);
	}
}