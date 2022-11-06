/*
the most important thing:
think twice,code once
*/
#include<bits/stdc++.h>
using namespace std;
/* --------------- fast io --------------- */ // begin
namespace _ {
	const int _________= 1 << 16;
	char buf[_________],*S,*T;
	inline char getchar() {
		if(S==T) {
			T=(S=buf)+
			  fread(buf,1,_________,stdin);
			if(S==T)return'\n';
		}
		return *S++;
	}
} // namespace _
namespace __ {
	const int _________= 1 << 16;
	char buf[_________],*S=buf,*T=buf+_________;
	inline void flush() {
		fwrite(buf,1,S-buf,stdout);
		S=buf;
	}
	inline void putchar(char c) {
		*S++=c;
		if(S==T)flush();
	}
	struct NTR {
		~NTR() {
			flush();
		}
	} ztr;
} // namespace __
#ifdef ONLINE_JUDGE
#define getchar _::getchar
#define putchar __::putchar
#endif
namespace ___ {
	struct __________ {
		template<typename T>__________&operator>>(T&x) {
			char c=getchar();
			short f=1;
			while(c<'0'||c>'9') {
				if(c=='-')f*=-1;
				c=getchar();
			}
			x=0;
			while(c>='0'&&c<='9') {
				x=(x<<1)+(x<<3)+(c^48);
				c=getchar();
			}
			x*=f;
			return *this;
		}
		__________&operator>>(double&x) {
			char c=getchar();
			short f=1,s=0;
			x=0;
			double t=0;
			while((c<'0'||c>'9')&&c!='-'&&c!='.') {
				if(c=='-')f*=-1;
				c=getchar();
			}
			while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();
			if(c=='.')c=getchar();
			else return x*=f,*this;
			while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();
			while(s--)t/=10.0;
			x=(x+t)*f;
			return*this;
		}
		__________&operator>>(long double&x) {
			char c=getchar();
			short f=1,s=0;
			x=0;
			long double t=0;
			while((c<'0'||c>'9')&&c!='-'&&c!='.') {
				if(c=='-')f*=-1;
				c=getchar();
			}
			while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();
			if(c=='.')c=getchar();
			else return x*=f,*this;
			while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();
			while(s--)t/=10.0;
			x=(x+t)*f;
			return*this;
		}
		__________&operator>>(__float128&x) {
			char c=getchar();
			short f=1,s=0;
			x=0;
			__float128 t=0;
			while((c<'0'||c>'9')&&c!='-'&&c!='.') {
				if(c=='-')f*=-1;
				c=getchar();
			}
			while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();
			if(c=='.')c=getchar();
			else return x*=f,*this;
			while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();
			while(s--)t/=10.0;
			x=(x+t)*f;
			return*this;
		}
		__________&operator>>(char&c) {
			c=getchar();
			while(c=='\n'||c==' '||c=='\r')c=getchar();
			return *this;
		}
		__________&operator>>(char*str) {
			int len=0;
			char c=getchar();
			while(c=='\n'||c==' '||c=='\r')c=getchar();
			while(c!='\n'&&c!=' '&&c!='\r')str[len++]=c,c=getchar();
			str[len]='\0';
			return*this;
		}
		__________&operator>>(string&str) {
			str.clear();
			char c=getchar();
			while(c=='\n'||c==' '||c=='\r')c=getchar();
			while(c!='\n'&&c!=' '&&c!='\r')str.push_back(c),c=getchar();
			return*this;
		}
		__________() {}
	} cin;
	const char endl='\n';
	struct ___________ {
		const int ____=6;
		typedef int ________;
		template<typename T>___________&operator<<(T x) {
			if(x==0)return putchar('0'),*this;
			if(x<0)putchar('-'),x=-x;
			static int _____[45];
			int _______=0;
			while(x)_____[++_______]=x%10,x/=10;
			while(_______)putchar(_____[_______]+'0'),--_______;
			return*this;
		}
		___________&operator<<(double x) {
			if(x<0)putchar('-'),x=-x;
			________ _=x;
			x-=(double)_;
			static int _____[45];
			int _______=0;
			while(_)_____[++_______]=_%10,_/=10;
			if(!_______)putchar('0');
			while(_______)putchar(_____[_______]+'0'),--_______;
			putchar('.');
			for(int i=0; i<____; i++)x*=10;
			_=x;
			while(_)_____[++_______]=_%10,_/=10;
			for(int i=0; i<____-_______; i++)putchar('0');
			while(_______)putchar(_____[_______]+'0'),--_______;
			return*this;
		}
		___________&operator<<(long double x) {
			if(x<0)putchar('-'),x=-x;
			________ _=x;
			x-=(long double)_;
			static int _____[45];
			int _______=0;
			while(_)_____[++_______]=_%10,_/=10;
			if(!_______)putchar('0');
			while(_______)putchar(_____[_______]+'0'),--_______;
			putchar('.');
			for(int i=0; i<____; i++)x*=10;
			_=x;
			while(_)_____[++_______]=_%10,_/=10;
			for(int i=0; i<____-_______; i++)putchar('0');
			while(_______)putchar(_____[_______]+'0'),--_______;
			return*this;
		}
		___________&operator<<(__float128 x) {
			if(x<0)putchar('-'),x=-x;
			________ _=x;
			x-=(__float128)_;
			static int _____[45];
			int _______=0;
			while(_)_____[++_______]=_%10,_/=10;
			if(!_______)putchar('0');
			while(_______)putchar(_____[_______]+'0'),--_______;
			putchar('.');
			for(int i=0; i<____; i++)x*=10;
			_=x;
			while(_)_____[++_______]=_%10,_/=10;
			for(int i=0; i<____-_______; i++)putchar('0');
			while(_______)putchar(_____[_______]+'0'),--_______;
			return*this;
		}
		___________&operator<<(char c) {
			putchar(c);
			return*this;
		}
		___________& operator<<(char*str) {
			int cur=0;
			while(str[cur])putchar(str[cur++]);
			return *this;
		}
		___________&operator<<(const char*str) {
			int cur=0;
			while(str[cur])putchar(str[cur++]);
			return*this;
		}
		___________&operator<<(string str) {
			int st=0,ed=str.size();
			while(st<ed)putchar(str[st++]);
			return*this;
		}
		___________() {}
	} cout;
} // namespace ___
#define cin ___ :: cin
#define cout ___ :: cout
#define endl ___ :: endl
/* --------------- fast io --------------- */ // end
struct node{
	int top,dep,siz,hson,col;
} E[1001010];
int x,y,opt,cnt,n,Testing,i,dfn[1001010],id,H[1001010],a[1000101],sum,b[1001010],d[1001010];
bool exist[1001010];
long long tag[4001010],tree[4001010],G;
void add(int x,int y){cnt++;a[cnt]=y;b[cnt]=d[x];d[x]=cnt;}
void build1(int x,int fa){
	int mx=0;E[x].hson=0;E[x].siz=1;
	for (int i=d[x];i;i=b[i])
	    if (a[i]!=fa){
	    	E[a[i]].dep=E[x].dep+1;build1(a[i],x);E[x].siz+=E[a[i]].siz;
	    	if (E[a[i]].siz>mx) mx=E[a[i]].siz,E[x].hson=a[i];
		}
    if (E[x].hson!=0) exist[E[x].hson]=true;
}
void build2(int x,int fa){
	dfn[x]=++id;
	if (exist[x]==false) E[x].top=x;
	if (E[x].hson) E[E[x].hson].top=E[x].top,build2(E[x].hson,x);
	for (int i=d[x];i;i=b[i])
	    if ((a[i]!=fa)&&(a[i]!=E[x].hson)) build2(a[i],x);
}
void build(int x,int l,int r){
	if (l==r){
		tree[x]=1ll<<(E[H[l]].col-1);return ;
	}
	int mid=(l+r)/2;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	tree[x]=tree[x<<1]|tree[x<<1|1];
}
void pushdown(int x){
	if (tag[x]){
	tree[x<<1|1]=tag[x];tree[x<<1]=tag[x];
	tag[x<<1|1]=tag[x];tag[x<<1]=tag[x];
    }
    tag[x]=0;
}
void modify(int x,int l,int r,int tl,int tr,int val){
	if ((l>=tl)&&(r<=tr)){
		tree[x]=1ll<<(val-1);tag[x]=1ll<<(val-1);return ;
}
pushdown(x);
int mid=(l+r)/2;
if (mid>=tl) modify(x<<1,l,mid,tl,tr,val);
if (mid<tr) modify(x<<1|1,mid+1,r,tl,tr,val);
tree[x]=tree[x<<1]|tree[x<<1|1];
}
long long query(int x,int l,int r,int tl,int tr){
	if ((l>=tl)&&(r<=tr)) return tree[x];
	pushdown(x);
int mid=(l+r)/2;long long ans=0;
if (mid>=tl) ans|=query(x<<1,l,mid,tl,tr);
if (mid<tr) ans|=query(x<<1|1,mid+1,r,tl,tr);
tree[x]=tree[x<<1]|tree[x<<1|1];
return ans;
}
int main() {
//	freopen("testdata.in","r",stdin);
cin>>n>>Testing;
for (i=1;i<=n;i++) cin>>E[i].col;
for (i=1;i<n;i++)
   { 
    cin>>x>>y;add(x,y);add(y,x);
   }
build1(1,0);build2(1,0);
for (i=1;i<=n;i++) H[dfn[i]]=i;build(1,1,n);
for (;Testing;Testing--){
	cin>>opt;
	if (opt==1) {
		cin>>x>>y;modify(1,1,n,dfn[x],dfn[x]+E[x].siz-1,y);
	}
	else {
		cin>>x;
		G=query(1,1,n,dfn[x],dfn[x]+E[x].siz-1);
		sum=0;
		for (;G;G>>=1) if (G&1)sum++;
		printf("%d\n",sum);
	}
}
return 0;
}