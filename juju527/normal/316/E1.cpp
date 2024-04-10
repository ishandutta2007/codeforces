#include<bits/stdc++.h>
#define Re register
using namespace std;
namespace io{
    #define DEBUG 1
    #define isdigit(x) (x >= '0' && x <= '9')
    const int MAXSIZE = 1 << 20;
    inline char gc() {
        #if DEBUG
        return getchar();
        #endif
        static char buf[MAXSIZE], *p1 = buf + MAXSIZE, *p2 = buf + MAXSIZE;
        if(p1 == p2) {
            p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
        }
        return p1 == p2 ? -1 : *p1++;
    }
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    template<class T> inline void read(T &x) {
        register double tmp = 1;
        register bool sign = 0;
        x = 0;
        register char ch = gc();
        for(; !isdigit(ch); ch = gc()) {
            if(ch == '-') {
                sign = 1;
            }
        }
        for(; isdigit(ch); ch = gc()) {
            x = (x << 1) + (x << 3) + (ch ^ 48);
        }
        if(ch == '.') {
            for(ch = gc(); isdigit(ch); ch = gc()) {
                tmp /= 10.0, x += tmp * (ch - 48);
            }
        }
        if(sign){
            x = -x;
        }
    }
    inline void read(char *s) {
        register char ch = gc();
        for(; blank(ch); ch = gc());
        for(; !blank(ch); ch = gc()) {
            *s++ = ch;
        }
        *s = 0;
    }
    inline void read(char &c) {
        for(c = gc(); blank(c); c = gc());
    }
    inline void push(const char &c) {
        char pbuf[MAXSIZE], *pp = pbuf;
        if (pp - pbuf == MAXSIZE) {
            fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
        }
        *pp++ = c;
    }
    template<class T> inline void write(T x) {
        static T sta[35];
        T top = 0;
        do {
            sta[top++] = x % 10;
            x /= 10;
        }while(x);
        #if DEBUG
        while(top) {
            putchar(sta[--top] + '0');
        }
        return;
        #endif
        while(top) {
            push(sta[--top] + '0');
        }
    }
    template<class T> inline void write(T x,char lastChar) {
        write(x);
        putchar(lastChar);
    }
}
using namespace io;
const int maxn=2e5+500,mod=1e9;
int B;
int a[maxn],f[maxn];
int p[maxn],q[maxn];
int b[maxn];
int id[maxn];
int laz[505];
int L[505],R[505];
int sum1[505],sum2[505];
int sump[505],sumq[505];
inline int add(int x){
	if(x>=mod)x-=mod;
	return x;
}
inline int sub(int x){
	if(x<0)x+=mod;
	return x;
}
inline void pushdown(int c){
	for(Re int i=L[c];i<=R[c];i++)a[i]=add(a[i]+laz[c]);
	laz[c]=0;
	return ;
}
inline int query(int l,int r){
	int bl=b[l],br=b[r];
	if(bl==br){
		int ans=0;
		for(Re int i=l;i<=r;i++)ans=add(ans+1ll*f[i-l]*add(a[i]+laz[bl])%mod);
		return ans;
	}
	int ans=0,pos;
	for(Re int i=l;i<=R[bl];i++)ans=add(ans+1ll*f[i-l]*add(a[i]+laz[bl])%mod);
	pos=bl*B-l+1;
	for(Re int i=bl+1;i<=br-1;i++){
		ans=add(ans+add(1ll*sum1[i]*f[pos]%mod+1ll*sum2[i]*f[pos+1]%mod));
		pos+=B;
	}
	for(Re int i=L[br];i<=r;i++)ans=add(ans+1ll*f[i-l]*add(a[i]+laz[br])%mod);
	return ans;
}
inline void modify(int l,int r,int d){
	int bl=b[l],br=b[r];
	if(bl==br){
		for(Re int i=l;i<=r;i++){
			a[i]=add(a[i]+d);
			sum1[bl]=add(sum1[bl]+1ll*p[id[i]]*d%mod);
			sum2[bl]=add(sum2[bl]+1ll*q[id[i]]*d%mod);
		}
		return ;
	}
	for(Re int i=l;i<=R[bl];i++){
		a[i]=add(a[i]+d);
		sum1[bl]=add(sum1[bl]+1ll*p[id[i]]*d%mod);
		sum2[bl]=add(sum2[bl]+1ll*q[id[i]]*d%mod);
	}
	for(Re int i=bl+1;i<=br-1;i++){
		laz[i]=add(laz[i]+d);
		sum1[i]=add(sum1[i]+1ll*sump[i]*d%mod);
		sum2[i]=add(sum2[i]+1ll*sumq[i]*d%mod);
	}
	for(Re int i=L[br];i<=r;i++){
		a[i]=add(a[i]+d);
		sum1[br]=add(sum1[br]+1ll*p[id[i]]*d%mod);
		sum2[br]=add(sum2[br]+1ll*q[id[i]]*d%mod);
	}
	return ;
}
int main(){
	int n,m;
	read(n);read(m);
	B=sqrt(n);
	for(int i=1;i<=n;i++)read(a[i]);
	f[0]=f[1]=1;
	for(int i=2;i<=n+1;i++)f[i]=add(f[i-1]+f[i-2]);
	p[0]=1;q[1]=1;
	for(int i=2;i<=n+1;i++)p[i]=add(p[i-1]+p[i-2]),q[i]=add(q[i-1]+q[i-2]);
	for(int i=1;i<=n;i++)b[i]=(i-1)/B+1;
	for(int i=1;i<=b[n];i++){
		L[i]=(i-1)*B+1;R[i]=min(i*B,n);
		for(int j=L[i];j<=R[i];j++){
			id[j]=j-(i-1)*B-1;
			sum1[i]=add(sum1[i]+1ll*p[id[j]]*a[j]%mod);
			sump[i]=add(sump[i]+p[id[j]]);
			sum2[i]=add(sum2[i]+1ll*q[id[j]]*a[j]%mod);
			sumq[i]=add(sumq[i]+q[id[j]]);
		}
	}
	for(Re int i=1;i<=m;i++){
		int opt,l,r,d;
		read(opt);read(l);read(r);
		if(opt==1){
			pushdown(b[l]);
			int bb=b[l];
			sum1[bb]=add(sum1[bb]+1ll*p[id[l]]*add(r-a[l])%mod);
			sum2[bb]=add(sum2[bb]+1ll*q[id[l]]*add(r-a[l])%mod);
			a[l]=r;
		}
		else if(opt==2)write(query(l,r),'\n');
		else{read(d);modify(l,r,d);}
	}
	return 0;
}