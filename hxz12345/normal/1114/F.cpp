#include <bits/stdc++.h>
using namespace std;
/* --------------- fast io --------------- */ // begin
namespace Fread{
const int SIZE= 1 << 16;
	char buf[SIZE],*S,*T;
	inline char getchar(){if(S==T){T=(S=buf)+
	fread(buf,1,SIZE,stdin);if(S==T)return'\n';}return *S++;}
} // namespace Fread
namespace Fwrite {
const int SIZE= 1 << 16;
	char buf[SIZE],*S=buf,*T=buf+SIZE;
	inline void flush(){fwrite(buf,1,S-buf,stdout);S=buf;}
	inline void putchar(char c){*S++=c;if(S==T)flush();}
	struct NTR{~NTR(){flush();}}ztr;
} // namespace Fwrite
#ifdef ONLINE_JUDGE
	#define getchar Fread::getchar
	#define putchar Fwrite::putchar
#endif
namespace Fastio{
struct Reader{
	template<typename T>Reader&operator>>(T&x){
		char c=getchar();short f=1;
		while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}
		x=0;while(c>='0'&&c<='9'){
			x=(x<<1)+(x<<3)+(c^48);
			c=getchar();
		}x*=f;return *this;
	}
	Reader&operator>>(double&x){
		char c=getchar();short f=1,s=0;x=0;double t=0;
		while((c<'0'||c>'9')&&c!='-'&&c!='.'){if(c=='-')f*=-1;c=getchar();}
		while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();
		if(c=='.')c=getchar();else return x*=f,*this;
		while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();
		while(s--)t/=10.0;x=(x+t)*f;return*this;
	}
	Reader&operator>>(long double&x){
		char c=getchar();short f=1,s=0;x=0;long double t=0;
		while((c<'0'||c>'9')&&c!='-'&&c!='.'){if(c=='-')f*=-1;c=getchar();}
		while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();
		if(c=='.')c=getchar();else return x*=f,*this;
		while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();
		while(s--)t/=10.0;x=(x+t)*f;return*this;
	}
	Reader&operator>>(__float128&x){
		char c=getchar();short f=1,s=0;x=0;__float128 t=0;
		while((c<'0'||c>'9')&&c!='-'&&c!='.'){if(c=='-')f*=-1;c=getchar();}
		while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();
		if(c=='.')c=getchar();else return x*=f,*this;
		while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();
		while(s--)t/=10.0;x=(x+t)*f;return*this;
	}
	Reader&operator>>(char&c){
		c=getchar();while(c=='\n'||c==' ')c=getchar();
		return *this;
	}
	Reader&operator>>(char*str){
		int len=0;char c=getchar();
		while(c=='\n'||c==' ')c=getchar();
		while(c!='\n'&&c!=' ')str[len++]=c,c=getchar();
		str[len]='\0';return*this;
	}
	Reader&operator>>(string&str){
		int len=0;char c=getchar();
		while(c=='\n'||c==' ')c=getchar();
		while(c!='\n'&&c!=' ')str.push_back(c),c=getchar();
		return*this;
	}
	Reader(){}
}cin;
const char endl='\n';
struct Writer{
const int Setprecision=6;
typedef int mxdouble;
	template<typename T>Writer&operator<<(T x){
		if(x==0)return putchar('0'),*this;
		if(x<0)putchar('-'),x=-x;
		static int sta[45];int top=0;
		while(x)sta[++top]=x%10,x/=10;
		while(top)putchar(sta[top]+'0'),--top;
		return*this;
	}
	Writer&operator<<(double x){
		if(x<0)putchar('-'),x=-x;
		mxdouble _=x;x-=(double)_;static int sta[45];int top=0;
		while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');
		while(top)putchar(sta[top]+'0'),--top;putchar('.');
		for(int i=0;i<Setprecision;i++)x*=10;
		_=x;while(_)sta[++top]=_%10,_/=10;
		for(int i=0;i<Setprecision-top;i++)putchar('0');
		while(top)putchar(sta[top]+'0'),--top;
		return*this;
	}
	Writer&operator<<(long double x){
		if(x<0)putchar('-'),x=-x;
		mxdouble _=x;x-=(long double)_;static int sta[45];int top=0;
		while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');
		while(top)putchar(sta[top]+'0'),--top;putchar('.');
		for(int i=0;i<Setprecision;i++)x*=10;
		_=x;while(_)sta[++top]=_%10,_/=10;
		for(int i=0;i<Setprecision-top;i++)putchar('0');
		while(top)putchar(sta[top]+'0'),--top;
		return*this;
	}
	Writer&operator<<(__float128 x){
		if(x<0)putchar('-'),x=-x;
		mxdouble _=x;x-=(__float128)_;static int sta[45];int top=0;
		while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');
		while(top)putchar(sta[top]+'0'),--top;putchar('.');
		for(int i=0;i<Setprecision;i++)x*=10;
		_=x;while(_)sta[++top]=_%10,_/=10;
		for(int i=0;i<Setprecision-top;i++)putchar('0');
		while(top)putchar(sta[top]+'0'),--top;
		return*this;
	}
	Writer&operator<<(char c){putchar(c);return*this;}
	Writer& operator<<(char*str){
		int cur=0;while(str[cur])putchar(str[cur++]);
		return *this;
	}
	Writer&operator<<(const char*str){
		int cur=0;while(str[cur])putchar(str[cur++]);
		return*this;
	}
	Writer&operator<<(string str){
		int st=0,ed=str.size();
		while(st<ed)putchar(str[st++]);
		return*this;
	}
	Writer(){}
}cout;
} // namespace Fastio
#define cin Fastio :: cin
#define cout Fastio :: cout
#define endl Fastio :: endl
/* --------------- fast io --------------- */ // end
#define int long long
struct node{
	long long sum,sta,tag;
} tree[4001010],tree1[4001010];
bool vis[10010];
char type[20];
long long j,l,r,x,m,i,n,MOD,Q,b[501010],a[501010],c[501010];
long long ans,now,e[501010];

long long pow(long long x,long long y,long long p)
{
	long long ans=1;
	for (;y;y>>=1,x=x*x % p)
	   if (y&1) ans=ans*x % p;
	return ans;
}
void pushup1(int x)
{
	tree1[x].sum=tree1[x*2].sum*tree1[x*2+1].sum % MOD;
}
void pushup(int x)
{
	tree[x].sta=tree[x*2].sta|tree[x*2+1].sta;
}
void pushdown(int x)
{
	tree[x*2].sta|=tree[x].tag;
	tree[x*2+1].sta|=tree[x].tag;
	tree[x*2].tag|=tree[x].tag;
	tree[x*2+1].tag|=tree[x].tag;
}
void build(int x,int l,int r)
{
	tree1[x].tag=1;
	if (l==r)
	   { 
	   tree1[x].sum=a[l];return ;
	   
	   }
	int mid=(l+r)/2;
	build(x*2,l,mid);build(x*2+1,mid+1,r);pushup1(x);
}
void pushdown1(int x,int l,int r)
{
int mid=(l+r)/2;
tree1[x*2].sum=tree1[x*2].sum*pow(tree1[x].tag,mid-l+1,MOD) % MOD;

tree1[x*2+1].sum=tree1[x*2+1].sum*pow(tree1[x].tag,r-mid,MOD) % MOD;

tree1[x*2].tag=tree1[x*2].tag*tree1[x].tag % MOD;

tree1[x*2+1].tag=tree1[x*2+1].tag*tree1[x].tag % MOD;	tree1[x].tag=1;
}
void modify(int x,int l,int r,int tl,int tr,int val)
{
	if ((l>=tl)&&(r<=tr))
	    {
	    	tree[x].tag|=val;tree[x].sta|=val;return ;
		}
	pushdown(x);
	int mid=(l+r)/2;
	if (mid>=tl) modify(x*2,l,mid,tl,tr,val);
	if (mid<tr) modify(x*2+1,mid+1,r,tl,tr,val);
	pushup(x);
}
long long query(int x,int l,int r,int tl,int tr)
{
	if ((l>=tl)&&(r<=tr)) return tree[x].sta;
	pushdown(x);
	int mid=(l+r)/2;
	long long ans=0;
	if (mid>=tl) ans|=query(x*2,l,mid,tl,tr);
	if (mid<tr) ans|=query(x*2+1,mid+1,r,tl,tr);
	pushup(x);
	return ans;
}
void modify1(int x,int l,int r,int tl,int tr,int val)
{
	if ((l>=tl)&&(r<=tr))
	    {
	    	tree1[x].sum=tree1[x].sum*pow(val,r-l+1,MOD) % MOD;tree1[x].tag=tree1[x].tag*val % MOD;return ;
		}
	pushdown1(x,l,r);
	int mid=(l+r)/2;
	if (mid>=tl) modify1(x*2,l,mid,tl,tr,val);
	if (mid<tr) modify1(x*2+1,mid+1,r,tl,tr,val);
	pushup1(x);
}
long long query1(int x,int l,int r,int tl,int tr)
{
	if ((l>=tl)&&(r<=tr)) return tree1[x].sum;
	pushdown1(x,l,r);
	int mid=(l+r)/2;
	long long ans=1;
	if (mid>=tl) ans=ans*query1(x*2,l,mid,tl,tr) % MOD;
	if (mid<tr) ans=ans*query1(x*2+1,mid+1,r,tl,tr) % MOD;
	pushup1(x);
	return ans;
}
signed main()
{
	cin>>n>>Q;MOD=1e9+7;
	for (i=2;i<=300;i++)
	    if (vis[i]==false)
	        { 
	            b[++m]=(long long)(i-1ll)*pow(i,MOD-2,MOD) % MOD;c[m]=i;
	            for (j=i;j<=300/i;j++)
	                vis[i*j]=true;
			}
    for (i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    for (i=1;i<=n;i++)
        {
        	x=0;
        	for (j=1;j<=m;j++)
        	   if (a[i] % c[j]==0)
        	      x|=(1ll<<(j-1));
        	//cout<<x<<endl;
        	modify(1,1,n,i,i,x);
		}
    for (;Q;Q--)
        {
        	cin>>type;
        	if (type[0]=='T')
        	    {
        	    	cin>>l>>r;
        	    	ans=query1(1,1,n,l,r);
        	    	now=query(1,1,n,l,r);
        	    	for (i=1;i<=m;i++)
        	    	   if (now&(1ll<<(i-1)))
        	    	   ans=1ll*ans*b[i] % MOD;
        	    	cout<<ans<<endl;
				}
			else
			    {
			    	cin>>l>>r>>x;
			    	modify1(1,1,n,l,r,x);
			    	now=0;
			    	for (i=1;i<=m;i++)
			            if (x % c[i]==0) 
			              now|=(1ll<<(i-1));
			        modify(1,1,n,l,r,now);
				}
		}
	return 0;
}