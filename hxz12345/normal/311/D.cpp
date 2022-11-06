#include<bits/stdc++.h>
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
		c=getchar();while(c=='\n'||c==' '||c=='\r')c=getchar();
		return *this;
	}
	Reader&operator>>(char*str){
		int len=0;char c=getchar();
		while(c=='\n'||c==' '||c=='\r')c=getchar();
		while(c!='\n'&&c!=' '&&c!='\r')str[len++]=c,c=getchar();
		str[len]='\0';return*this;
	}
	Reader&operator>>(string&str){
		str.clear();char c=getchar();
		while(c=='\n'||c==' '||c=='\r')c=getchar();
		while(c!='\n'&&c!=' '&&c!='\r')str.push_back(c),c=getchar();
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
struct SegmentTree{
	long long tag,sum[50];
} tree[401010];
long long MOD,i,Testing,e[1001010],a[1001010],n,opt,l,r;
void pushdown(int x,int l,int r)
{
	int i;
	for (i=0;i<=47;i++) e[i]=tree[x*2].sum[(i+tree[x].tag) % 48];
	for (i=0;i<=47;i++) tree[x*2].sum[i]=e[i];
	for (i=0;i<=47;i++) e[i]=tree[x*2+1].sum[(i+tree[x].tag) % 48];
	for (i=0;i<=47;i++) tree[x*2+1].sum[i]=e[i];
	tree[x*2].tag+=tree[x].tag;tree[x*2+1].tag+=tree[x].tag;tree[x].tag=0;}
void pushup(int x)
{
	int i;
	for (i=0;i<=47;i++) tree[x].sum[i]=(tree[x*2].sum[i]+tree[x*2+1].sum[i]) % MOD;
}
void build(int x,int l,int r)
{
	tree[x].tag=0;
	if (l==r)
	   {
	   	tree[x].sum[0]=a[l];
	   	long long now=a[l];
	   	int i;
	   	for (i=1;i<=47;i++) tree[x].sum[i]=tree[x].sum[i-1]*tree[x].sum[i-1] % MOD*tree[x].sum[i-1] % MOD;
	   	return ;
	   }
	int mid=(l+r)/2;
	build(x*2,l,mid);build(x*2+1,mid+1,r);
	pushup(x);
}
void modify(int x,int l,int r,int tl,int tr)
{
	if ((l>=tl)&&(r<=tr))
	    { 
	    long long tem=tree[x].sum[0];
	    int i;
	        for (i=0;i<=46;i++) tree[x].sum[i]=tree[x].sum[i+1];
			tree[x].sum[47]=tem; 
	        tree[x].tag++;
	        return;
		}
	int mid=(l+r)/2;
	pushdown(x,l,r);
	if (mid>=tl) modify(x*2,l,mid,tl,tr);
	if (mid<tr) modify(x*2+1,mid+1,r,tl,tr);
	pushup(x);
}
long long query(int x,int l,int r,int tl,int tr)
{
	if ((l>=tl)&&(r<=tr)) return tree[x].sum[0];
	int mid=(l+r)/2;
	pushdown(x,l,r);
	long long ans=0;
	if (mid>=tl) ans+=query(x*2,l,mid,tl,tr);
	ans%=MOD;
	if (mid<tr) ans+=query(x*2+1,mid+1,r,tl,tr);
	ans%=MOD;
	pushup(x);
	return ans;
}
int main()
{
//	freopen("testdata.in","r",stdin);
	MOD=95542721;
cin>>n;
for (i=1;i<=n;i++) cin>>a[i];
build(1,1,n);
cin>>Testing;
for (;Testing;Testing--)
    {
    	cin>>opt>>l>>r;
    	if (opt==1) printf("%lld\n",query(1,1,n,l,r));
    	if (opt==2) modify(1,1,n,l,r);
	}
 return 0;
}