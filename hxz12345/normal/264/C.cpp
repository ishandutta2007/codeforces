#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
using namespace std;
/* --------------- fast io --------------- */ // begin
namespace Fread {
const int SIZE = 1 << 16;
char buf[SIZE], *S, *T;
inline char getchar() {
	if (S == T) {
		T = (S = buf) + fread(buf, 1, SIZE, stdin);
		if (S == T) return '\n';
	}
	return *S++;
}
} // namespace Fread
namespace Fwrite {
const int SIZE = 1 << 16;
char buf[SIZE], *S = buf, *T = buf + SIZE;
inline void flush() {
	fwrite(buf, 1, S - buf, stdout);
	S = buf;
}
inline void putchar(char c) {
	*S++ = c;
	if (S == T) flush();
}
struct NTR {
	~ NTR() { flush(); }
} ztr;
} // namespace Fwrite
#ifdef ONLINE_JUDGE
	#define getchar Fread :: getchar
	#define putchar Fwrite :: putchar
#endif
namespace Fastio {
struct Reader {
	template<typename T>
	Reader& operator >> (T& x) {
		char c = getchar();
		T f = 1;
		while (c < '0' || c > '9') {
			if (c == '-') f = -1;
			c = getchar();
		}
		x = 0;
		while (c >= '0' && c <= '9') {
			x = x * 10 + (c - '0');
			c = getchar();
		}
		x *= f;
		return *this;
	}
	Reader& operator >> (char& c) {
		c = getchar();
		while (c == '\n' || c == ' ') c = getchar();
		return *this;
	}
	Reader& operator >> (char* str) {
		int len = 0;
		char c = getchar();
		while (c == '\n' || c == ' ') c = getchar();
		while (c != '\n' && c != ' ') {
			str[len++] = c;
			c = getchar();
		}
		str[len] = '\0';
		return *this;
	}
	Reader(){}
} cin;
const char endl = '\n';
struct Writer {
	template<typename T>
	Writer& operator << (T x) {
		if (x == 0) { putchar('0'); return *this; }
		if (x < 0) { putchar('-'); x = -x; }
		static int sta[45];
		int top = 0;
		while (x) { sta[++top] = x % 10; x /= 10; }
		while (top) { putchar(sta[top] + '0'); --top; }
		return *this;
	}
	Writer& operator << (char c) {
		putchar(c);
		return *this;
	}
	Writer& operator << (char* str) {
		int cur = 0;
		while (str[cur]) putchar(str[cur++]);
		return *this;
	}
	Writer& operator << (const char* str) {
		int cur = 0;
		while (str[cur]) putchar(str[cur++]);
		return *this;
	}
	Writer(){}
} cout;
} // namespace Fastio
#define cin Fastio :: cin
#define cout Fastio :: cout
#define endl Fastio :: endl
/* --------------- fast io --------------- */ // end

long long P1,P,now,lsh[101010],len,col[101010],suf[101010],pre[101010],a[101010],b[101010],f[101010],lft,rit,i,n,Q,ans;
inline void modify_pre(int x,long long y)
{
	for (;x<=len;x+=(x&-x)) pre[x]=max(pre[x],y);
}
inline long long query_pre(int x)
{
	long long anss=-1e18;
	for (;x;x-=(x&-x)) 
	     {
		 anss=max(anss,pre[x]);
	    }
	return anss;
}
inline void modify_suf(int x,long long y)
{
	for (;x;x-=(x&-x)) suf[x]=max(suf[x],y);
}
inline long long query_suf(int x)
{long long anss=-1e18;
	for (;x<=len;x+=(x&-x)) anss=max(anss,suf[x]);
	return anss;
}
int main() {
    cin>>n>>Q;
    for (i=1;i<=n;i++) cin>>b[i];
    for (i=1;i<=n;i++) cin>>a[i],lsh[i]=a[i];
    sort(lsh+1,lsh+n+1);len=unique(lsh+1,lsh+n+1)-lsh-1;
    for (i=1;i<=n;i++) a[i]=lower_bound(lsh+1,lsh+1+len,a[i])-lsh;
    for (;Q;Q--)
        {
        	cin>>lft>>rit;
        	for (i=1;i<=len;i++) col[i]=-1e18,suf[i]=-1e18,pre[i]=-1e18;
        	f[1]=rit*b[1];modify_pre(a[1]+1,f[1]);modify_suf(a[1]-1,f[1]);col[a[1]]=f[1];ans=max((long long)0,f[1]);
        	P=f[1];P1=-1e18;
     //   cout<<"------"<<query_pre(1)<<" "<<pre[1]<<"-------"<<endl;
		//	cout<<"right"<<endl;
        	for (i=2;i<=n;i++)
        	    { 
        	    f[i]=rit*b[i];
        	    //col[a[i]+1]++,1~a[i]
        	    if (col[a[i]]!=-1e18) f[i]=max(f[i],col[a[i]]+lft*b[i]);
        	    if (len>n/2)
        	        {
        	        	if (col[a[i]]==P) now=P1;
        	        	else now=P;
        	           if (now!=-1e18)f[i]=max(f[i],now+rit*b[i]);
        	        	if (f[i]>P)
        	        	    {
        	        	    	P1=P;P=f[i];
							}
						else if (f[i]>P1) P1=f[i];
					}
				else
				   {
        	    now=max(query_pre(a[i]),query_suf(a[i]));
        	    if (now!=-1e18)f[i]=max(f[i],now+rit*b[i]);
        	    modify_pre(a[i]+1,f[i]);modify_suf(a[i]-1,f[i]);
        	      }
        	   // cout<<"right"<<endl;
        	    col[a[i]]=max(col[a[i]],f[i]);
        	    ans=max(ans,f[i]);
        	    //cout<<f[i]<<endl;
				}
			cout<<ans<<endl;
		}
	return 0;
}