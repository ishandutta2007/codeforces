#include<cstdio>
#include<iostream> 
#include<algorithm>
#include<cmath>
using namespace std;
/* --------------- fast io --------------- */ // begin
namespace Fread {
const int SIZE = 1 << 26;
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
const int SIZE = 1 << 26;
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
			x = (x * 10 + (c - '0'));
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
struct node{
	int l,r,id;
} b[1001010];
int pos[1010100],c[1001010],m,f[1001010],B,ans,n,i,len,a[1010100],lsh[1010100],L,R,curL,curR,Answer[1011000];
bool cmp(node a,node b)
{
	if ((pos[a.l]^pos[b.l])) return a.l<b.l;
	else if (pos[a.l]&1) return a.r<b.r;
	return a.r>b.r;
}
void ins(int x)
{
	f[a[x]]++;
	if (f[a[x]]!=1) ans^=c[x];
}
void del(int x)
{
	f[a[x]]--;
	if (f[a[x]]!=0) ans^=c[x]; 
}
int main()
{
	cin>>n;
	for (i=1;i<=n;i++) cin>>a[i],lsh[i]=a[i];
	sort(lsh+1,lsh+n+1);
	len=unique(lsh+1,lsh+n+1)-lsh-1;
	for (i=1;i<=n;i++) c[i]=a[i],a[i]=lower_bound(lsh+1,lsh+len+1,a[i])-lsh;
	cin>>m;B=n/pow(m,0.455);
	for (i=1;i<=m;i++) cin>>b[i].l>>b[i].r,b[i].id=i;
	for (i=1;i<=n;i++) pos[i]=(i-1)/B+1;
	sort(b+1,b+m+1,cmp);
	curL=1;curR=0;
	for (i=1;i<=m;i++)
	    { 
	      L=b[i].l;R=b[i].r;
	      while (curR<R) ins(++curR);
	      while (curL>L) ins(--curL);
	      while (curR>R) del(curR--);
	      while (curL<L) del(curL++);
	      Answer[b[i].id]=ans;
		}
	for (i=1;i<=m;i++) cout<<Answer[i]<<endl;
    return 0;
}