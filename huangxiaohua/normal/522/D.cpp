#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,f[500500],g[500500],res[500500],a[500500],b[500500],mp[1000500];
struct SB{
	int id,l,r;
	bool operator<(const SB x)const{return l>x.l;}
}q[500500];
void add(int x,int y){for(;x<=n;x+=(-x&x))f[x]=min(f[x],y);}
int get(int x,int y=n+1){for(;x;x-=(-x&x)){y=min(y,f[x]);}return y;}

namespace IO{//by cyffff
	char ibuf[(1<<20)+1],*iS,*iT;
	#if ONLINE_JUDGE
	#define gh() (iS==iT?iT=(iS=ibuf)+fread(ibuf,1,(1<<20)+1,stdin),(iS==iT?EOF:*iS++):*iS++)
 	#else
	#define gh() getchar()
	#endif
	inline long long read(){
		char ch=gh();
		long long x=0;
		char t=0;
		while(ch<'0'||ch>'9')   t|=ch=='-',ch=gh();
		while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=gh();
		return t?-x:x;
	}
}
using IO::read;

char pbuf[1 << 20], *pp = pbuf;

inline void push(const char &c) {
  if (pp - pbuf == 1 << 20) fwrite(pbuf, 1, 1 << 20, stdout), pp = pbuf;
  *pp++ = c;
}

inline void write(int x) {
	if(x<0){
		push('-');push('1');push('\n');return;
	}
	static int sta[35];
	int top = 0;
	do {
		sta[top++] = x % 10, x /= 10;
	} while (x);
	while (top) push(sta[--top] + '0');
	push('\n');
}

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	n=read();t=read();
	for(i=1;i<=n;i++){a[i]=b[i]=read();f[i]=n+1;}
	sort(b+1,b+n+1);
	int it=unique(b+1,b+n+1)-b;
	for(i=1;i<=n;i++)a[i]=lower_bound(b+1,b+it,a[i])-b;
	for(i=n;i>=1;i--){
		if(mp[a[i]])g[i]=mp[a[i]];
		mp[a[i]]=i;
	}
	for(i=1;i<=t;i++){j=read();k=read();q[i]={i,j,k};}
	sort(q+1,q+t+1);
	it=n;
	for(i=1;i<=t;i++){
		while(it>=q[i].l){
			if(g[it])add(g[it],g[it]-it);
			it--;
		}
		res[q[i].id]=get(q[i].r);
	}
	for(i=1;i<=t;i++)write((res[i]==n+1)?-1:res[i]);
	fwrite(pbuf, 1, pp-pbuf, stdout);
}