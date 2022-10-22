#include<bits/stdc++.h>
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
const int maxn=2e5+5,maxm=2e5+5,mod=1e9;
int a[maxn],f[maxn];
int p[maxn],q[maxn],sp[maxn],sq[maxn];
inline int add(int x){
	if(x>=mod)x-=mod;
	return x;
}
inline int sub(int x){
	if(x<0)x+=mod;
	return x;
}
int sum[maxn<<2];
int sum1[maxn<<2],sum2[maxn<<2];
int laz[maxn<<2];
void build(int k,int l,int r){
	for(int i=l;i<=r;i++){
		sum1[k]=add(sum1[k]+1ll*p[i-l]*a[i]%mod);
		sum2[k]=add(sum2[k]+1ll*q[i-l]*a[i]%mod);
	}
	if(l==r){sum[k]=a[l];return ;}
	int mid=l+((r-l)>>1);
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	sum[k]=add(sum[k<<1]+sum[k<<1|1]);
	return ;
}
void add_laz(int k,int l,int r,int v){
	laz[k]=add(laz[k]+v);
	sum1[k]=add(sum1[k]+1ll*sp[r-l]*v%mod);
	sum2[k]=add(sum2[k]+1ll*sq[r-l]*v%mod);
	sum[k]=add(sum[k]+1ll*v*(r-l+1)%mod);
	return ;
}
void pushdown(int k,int l,int r){
	if(!laz[k])return ;
	int mid=l+((r-l)>>1);
	add_laz(k<<1,l,mid,laz[k]);
	add_laz(k<<1|1,mid+1,r,laz[k]);
	laz[k]=0;
	return ;
}
int val=0;
void modify1(int k,int l,int r,int x,int v){
	if(l>x||r<x)return ;
	if(l==r){
		val=sum[k];
		sum1[k]=1ll*p[0]*v%mod;
		sum2[k]=1ll*q[0]*v%mod;
		sum[k]=v;
		return ;
	}
	int mid=l+((r-l)>>1);
	pushdown(k,l,r);
	modify1(k<<1,l,mid,x,v);
	modify1(k<<1|1,mid+1,r,x,v);
	sum1[k]=add(sum1[k]+1ll*p[x-l]*sub(v-val)%mod);
	sum2[k]=add(sum2[k]+1ll*q[x-l]*sub(v-val)%mod);
	sum[k]=add(sum[k<<1]+sum[k<<1|1]);
	return ;
}
void modify2(int k,int l,int r,int x,int y,int d){
	if(l>y||r<x)return ;
	if(l>=x&&r<=y){
		add_laz(k,l,r,d);
		return ;
	}
	int mid=l+((r-l)>>1);
	pushdown(k,l,r);
	modify2(k<<1,l,mid,x,y,d);
	modify2(k<<1|1,mid+1,r,x,y,d);
	int lt=max(l,x),rt=min(r,y);
	sum1[k]=add(sum1[k]+1ll*sub(sp[rt-l]-(lt-l-1>=0?sp[lt-l-1]:0))*d%mod);
	sum2[k]=add(sum2[k]+1ll*sub(sq[rt-l]-(lt-l-1>=0?sq[lt-l-1]:0))*d%mod);
	sum[k]=add(sum[k<<1]+sum[k<<1|1]);
	return ;
}
int query(int k,int l,int r,int x,int y){
	if(l>y||r<x)return 0;
	if(l>=x&&r<=y)return add(1ll*f[l-x]*sum1[k]%mod+1ll*f[l-x+1]*sum2[k]%mod);
	int mid=l+((r-l)>>1);
	pushdown(k,l,r);
	return add(query(k<<1,l,mid,x,y)+query(k<<1|1,mid+1,r,x,y));
}
int main(){
	int n,m;
	read(n);read(m);
	for(int i=1;i<=n;i++)read(a[i]);
	f[0]=f[1]=1;
	for(int i=2;i<=n;i++)f[i]=add(f[i-1]+f[i-2]);
	p[0]=1;q[1]=1;
	for(int i=2;i<=n;i++)p[i]=add(p[i-1]+p[i-2]),q[i]=add(q[i-1]+q[i-2]);
	sp[0]=p[0];
	for(int i=1;i<=n;i++)sp[i]=add(sp[i-1]+p[i]),sq[i]=add(sq[i-1]+q[i]);
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int opt,l,r,d;
		read(opt);read(l);read(r);
		if(opt==1)modify1(1,1,n,l,r);
		else if(opt==2)printf("%d\n",query(1,1,n,l,r));
		else{read(d);modify2(1,1,n,l,r,d);}
	}
	return 0;
}