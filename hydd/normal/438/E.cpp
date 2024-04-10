#include<cstdio>
#include<vector>
using namespace std;
typedef vector<int> poly;
typedef long long ll;
const int Mod=998244353;
const int inv2=(Mod+1)/2;
const int G=3;
int n,m,a[310000],v[310000],rev[310000];
poly f,g,ans,ans2;
char Getchar(){
    static char now[1<<20],*S,*T;
    if (T==S){
        T=(S=now)+fread(now,1,1<<20,stdin);
        if (T==S) return EOF;
    }
    return *S++;
}
int read(){
    int x=0,f=1;
    char ch=Getchar();
    while (ch<'0'||ch>'9'){
        if (ch=='-') f=-1;
        ch=Getchar();
    }
    while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=Getchar();
    return x*f;
}
inline int add(int x,int y){return x+y>=Mod?x+y-Mod:x+y;}
inline int dec(int x,int y){return x-y<0?x-y+Mod:x-y;}
inline int mul(int x,int y){return 1ll*x*y%Mod;}
ll qpow(ll x,ll a){
	ll res=1;
	while (a){
		if (a&1) res=res*x%Mod;
		x=x*x%Mod; a>>=1;
	}
	return res;
}
inline ll getinv(const int &x){ return qpow(x,Mod-2);}

void NTT(poly &a,int len,int inv){
	a.resize(len);
    for (int i=0;i<len;i++)
        if (i<rev[i]) swap(a[i],a[rev[i]]);
    for (int mid=1;mid<len;mid<<=1){
        int tmp=qpow(G,(Mod-1)/(mid<<1));
        if (inv==-1) tmp=getinv(tmp);
        for (int i=0;i<len;i+=(mid<<1)){
            ll omega=1;
            for (ll j=0;j<mid;j++,omega=mul(omega,tmp)){
                int x=a[i+j],y=mul(omega,a[i+j+mid]);
                a[i+j]=add(x,y),a[i+j+mid]=dec(x,y);
            }
        }
    }
    if (inv==-1){
    	ll inv=getinv(len);
	    for (int i=0;i<len;i++) a[i]=mul(a[i],inv);
	}
}
void mult(poly a,poly b,poly &c,const int &n){
    int bit=0; while ((1<<bit)<n) bit++;
	int len=1<<bit;
    for (int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	NTT(a,len,1); NTT(b,len,1);
	c.resize(len);
	for (int i=0;i<len;i++) c[i]=mul(a[i],b[i]);
	NTT(c,len,-1);
}
void polyinv(const int &len,const int &bit,poly &a,poly &b){
	int n=1<<bit;
    for (int i=0;i<n;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
    poly c=a; c.resize(len); b.resize(len);
    NTT(c,n,1); NTT(b,n,1);
    for (int i=0;i<n;i++) b[i]=1ll*(Mod+2-1ll*c[i]*b[i]%Mod)%Mod*b[i]%Mod;
    NTT(b,n,-1); b.resize(len);
}
inline int getbit(const int &x){
    int bit=1;
    while ((1<<bit)<x) bit++;
    return bit;
}
void getinv(const int &n,poly &a,poly &b){
    if (n==1){
        b.resize(1);
        b[0]=getinv(a[0]);
        return;
    }
    getinv((n+1)>>1,a,b);
    int bit=getbit(n<<1);
    polyinv(n,bit,a,b);
}
void Dao(poly &A,poly &B,int len){
	for (int i=1;i<len;i++) B[i-1]=1ll*i*A[i]%Mod;
	B[len-1]=0;
}
void Jifen(poly &A,poly &B,int len){
	for (int i=1;i<len;i++) B[i]=1ll*A[i-1]*getinv(i)%Mod;
	B[0]=0;
}
poly A,B,C;
void getln(poly &f,poly &g,int n){
	f.resize(n); g.resize(n);
	A.resize(n); B.resize(n);
	Dao(f,A,n); getinv(n,f,B);
	mult(A,B,C,n+n);
	Jifen(C,g,n);
}
poly t;
void getexp(const int &n,poly &a,poly &b){
    if (n==1){
        b.resize(1); b[0]=1;
        return;
    }
    getexp(n>>1,a,b);
	getln(b,t,n);
    for (int i=0;i<n;i++) t[i]=dec(a[i],t[i]);
    t[0]=add(1,t[0]);
    mult(t,b,b,n+n); t.clear(); b.resize(n);
}
int main(){
	n=read(); m=read()+1;
	for (int i=1;i<=n;i++) v[read()]++;
	f.resize(m+1);
	f[0]=1; for (int i=1;i<m;i++) f[i]=(4ll*(Mod-v[i]))%Mod;
	for (n=1;n<=m;n<<=1);
	f.resize(n); getln(f,g,n);
    for (int i=0;i<n;i++) g[i]=1ll*g[i]*inv2%Mod;
    g.resize(n); getexp(n,g,ans);
	ans[0]=(ans[0]+1)%Mod;
    getinv(n,ans,ans2);
	for (int i=1;i<m;i++) printf("%d\n",add(ans2[i],ans2[i]));
	return 0;
}//