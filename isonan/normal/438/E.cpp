// luogu-judger-enable-o2
// luogu-judger-enable-o2
// luogu-judger-enable-o2
// luogu-judger-enable-o2
// luogu-judger-enable-o2
#pragma GCC optimize(2)
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef std::vector<int> poly;
typedef long long ll;
#define pb push_back
poly A,B;
int n,R[2000001],lim,ksm[30],L,w[2000001],t1[2000001],t2[2000001],m,a[1000001],fac[1000001];
poly val[1000001];
const int P=998244353;
inline int read(){
    static int x;x=0;
    static char ch;ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}
inline void write(const int &x){if(x>9)write(x/10);putchar((x%10)+'0');}
inline void print(poly A,int n=-1){if(!~n)n=A.size();for(int i=0;i<n;i++)write(A[i]),putchar(' ');putchar('\n');}
inline int mul(const int &a,const int &b){return (ll)a*b-(ll)a*b/P*P;}
inline int add(int a,const int &b){a+=b;return a>=P?a-P:a;}
inline int sub(int a,const int &b){a-=b;return a<0?a+P:a;}
inline int qsm(int a,long long b=P-2){
    int ans=1;
    while(b){if(b&1)ans=mul(ans,a);a=mul(a,a),b>>=1;}
    return ans;
}
inline int inv(const int &a){return (a<=1)?1:mul(P-P/a,inv(P%a));}
inline int upp(int x){
    while((x&-x)!=x)x+=x&-x;
    return x;
}
inline void getRev(int x){
    lim=upp(x);
    for(int i=1;i<lim;i++)R[i]=(R[i>>1]>>1)|((i&1)?(lim>>1):0);
}
inline void NTT(int *A){
    for(register int i=0;i<lim;++i)if(i<R[i])swap(A[i],A[R[i]]);
    for(register int i=1;i<lim;i<<=1)
        for(register int j=0;j<lim;j+=(i<<1))
            for(register int k=0,t=1;k<i;++k){
                const int Ny=mul(A[i+j+k],w[i+k]);
                A[i+j+k]=sub(A[j+k],Ny);
                A[j+k]=add(A[j+k],Ny);
            }
}
inline void NTT_with_limit(int *A,const int &len){
    for(register int i=0;i<lim;++i)if(i<R[i])swap(A[i],A[R[i]]);
    static int half;half=lim>>1;
    for(register int i=1;i<half;i<<=1){
        for(register int j=0;j<lim;j+=(i<<1))
            for(register int k=0;k<i;++k){
                const int Ny=mul(A[i+j+k],w[i+k]);
                A[i+j+k]=sub(A[j+k],Ny);
                A[j+k]=add(A[j+k],Ny);
            }
    }
    for(register int k=0;k<len;++k){
        const int Ny=mul(A[half+k],w[half+k]);
        A[half+k]=sub(A[k],Ny);
        A[k]=add(A[k],Ny);
    }
}
inline poly Res(poly A,int x){return A.resize(x),A;}
inline poly mul(poly A,poly B,int len=-1){
    if(~len){
        if(A.size()>len)A.resize(len);
        if(B.size()>len)B.resize(len);
    }
    int size=A.size()+B.size()-1;
    if(size<=100){
        poly C(size);
        for(int i=0;i<A.size();++i)
            for(int j=0;j<B.size();++j)
                C[i+j]=add(C[i+j],mul(A[i],B[j]));
        if(~len)C.resize(len);
        return C;
    }
    getRev(size);
    memset(t1,0,lim<<2);
    memset(t2,0,lim<<2);
    for(int i=A.size()-1;~i;--i)t1[i]=A[i];
    for(int i=B.size()-1;~i;--i)t2[i]=B[i];
    NTT(t1);
    NTT(t2);
    for(int i=0;i<lim;i++)t1[i]=mul(t1[i],t2[i]);
    std::reverse(t1+1,t1+lim);
    if(~len)size=len;
    NTT_with_limit(t1,min(size,lim>>1));
//	NTT(t1);
    lim=inv(lim);
    A.resize(0);
    for(int i=0;i<size;i++)A.pb(mul(t1[i],lim));
    return A;
}
inline int mul_inv(const int &a,const int &b){return sub(add(b,b),mul(a,mul(b,b)));}
inline poly mul_inv(poly A,const poly &B,int len=-1){
    int size=A.size()+B.size()-1;
    getRev(size);
    memset(t1,0,lim<<2);
    memset(t2,0,lim<<2);
    for(int i=A.size()-1;~i;--i)t1[i]=A[i];
    for(int i=B.size()-1;~i;--i)t2[i]=B[i];
    NTT(t1);
    NTT(t2);
    for(int i=0;i<lim;i++)t1[i]=sub(add(t2[i],t2[i]),mul(t1[i],mul(t2[i],t2[i])));
    std::reverse(t1+1,t1+lim);
    if(~len)size=len;
    NTT_with_limit(t1,min(size,lim>>1));
//	NTT(t1);
    lim=inv(lim);
    A.resize(0);
    for(int i=0;i<size;i++)A.pb(mul(t1[i],lim));
    return A;
}
inline poly inv(poly A,int n){
    A.resize(n);
    poly B,t;B.pb(inv(A[0]));
    static int last;last=0;
    for(register int len=2;(len>>1)<n;len<<=1){
        for(;last<len;++last)t.pb(last<n?A[last]:0);
        B=mul_inv(t,B,len);
    }
    B.resize(n);
    return B;
}
inline poly operator+(poly A,const poly &B){
    if(A.size()<B.size())A.resize(B.size());
    for(int i=0;i<A.size();++i)A[i]=add(A[i],i<B.size()?B[i]:0);
    return A;
}
inline poly operator-(poly A,const poly &B){
    if(A.size()<B.size())A.resize(B.size());
    for(int i=0;i<A.size();++i)A[i]=sub(A[i],i<B.size()?B[i]:0);
    return A;
}
inline poly operator/(poly A,const int &n){
    for(int i=0;i<A.size();++i)A[i]=mul(A[i],inv(n));
    return A;
}
inline poly operator-(const int &n,poly B){
    for(int i=0;i<B.size();++i)B[i]=P-B[i];
    B[0]=add(B[0],n);
    return B;
}
inline poly operator+(const int &n,poly B){
    B[0]=add(B[0],n);
    return B;
}
inline poly operator*(const int &n,poly A){
    for(int i=0;i<A.size();++i)A[i]=mul(n,A[i]);
    return A;
}
inline poly diff(poly A){
    for(int i=0;i<A.size()-1;++i)A[i]=mul(A[i+1],i+1);
    A[A.size()-1]=0;
    return A;
}
inline poly inte(poly A){
    for(int i=A.size()-1;i;--i)A[i]=mul(A[i-1],inv(i));
    A[0]=0;
    return A;
}
inline poly ln(const poly &A,const int &len){return inte(mul(diff(A),inv(A,len),len));}
inline poly exp(const poly &A,const int &n){
    poly B(1,1);
    for(int i=2;(i>>1)<n;i<<=1)B=mul(B,1-ln(B,i)+A,i);
    B.resize(n);
    return B;
}
struct point{int a,b;};
point mul(point lhs,point rhs,int c){return (point){add(mul(lhs.a,rhs.a),mul(mul(lhs.b,rhs.b),c)),add(mul(lhs.a,rhs.b),mul(lhs.b,rhs.a))};}
int Quadratic_Residue(int x){
    for(;;){
        int t=mul(rand(),rand());
        if(qsm(sub(mul(t,t),x),(P-1)>>1)!=P-1)continue;
        int b=(P+1)>>1,c=sub(mul(t,t),x);
        point tem1=(point){t,1},tem2=(point){1,0};
        while(b){
            if(b&1)tem2=mul(tem1,tem2,c);
            tem1=mul(tem1,tem1,c);
            b>>=1;
        }
        return min(tem2.a,P-tem2.a);
    }
}
inline poly sqrt(const poly &A,const int &n){
    poly B(1,Quadratic_Residue(A[0]));
    for(int i=2;(i>>1)<n;i<<=1)B=(mul(A,inv(B,i),i)+B)/2;
    B.resize(n);
    return B;
}
inline poly Rev(poly A){std::reverse(A.begin(),A.end());return A;}
inline poly div(poly A,poly B,int n=-1,int m=-1){
    if(!~n)n=A.size();
    if(!~m)m=B.size();
    std::reverse(A.begin(),A.end());
    std::reverse(B.begin(),B.end());
    poly t1=mul(A,inv(B,n-m+1),n-m+1);
    std::reverse(t1.begin(),t1.end());
    std::reverse(A.begin(),A.end());
    std::reverse(B.begin(),B.end());
    poly t2=A-mul(B,t1,n);
    t2.resize(m);
    return t2;
}
inline void prepare_getval(int l,int r,int num){
    if(l==r){
        val[num].pb(P-read());
        val[num].pb(1);
        return;
    }
    prepare_getval(l,(l+r)>>1,num<<1);
    prepare_getval(((l+r)>>1)+1,r,num<<1|1);
    val[num]=mul(val[num<<1],val[num<<1|1]);
}
inline void getval(int l,int r,int num,int depth,poly now){
    now=div(now,val[num]);
    if(l==r){
        write(now[0]);
        putchar('\n');
        return;
    }
    getval(l,(l+r)>>1,num<<1,depth+1,now);
    getval(((l+r)>>1)+1,r,num<<1|1,depth+1,now);
}
poly qsm(poly a,int b,int n){
    poly ans(1,1);
    while(b){
        if(b&1)ans=mul(ans,a,n);
        a=mul(a,a,n);
        b>>=1;
    }
    return ans;
}
poly sqrt_inv(poly A,int n){
    poly B(1,inv(Quadratic_Residue(A[0])));
    for(int i=2;(i>>1)<n;i<<=1)B=(B+inv(mul(A,B,i),i))/2;
    return B;
}
int vis[1000001];
int main(){
    srand(19260817);
    n=read();m=read();
    for(int i=1,wn;i<((m+2)<<2);i<<=1){
        wn=qsm(3,(P-1)/(i<<1)),w[i]=1;
        for(int j=1;j<i;j++)w[i+j]=mul(w[i+j-1],wn);
    }
    poly a(100001);
    int mn=0x7f7f7f7f;
    for(int i=1,tem;i<=n;i++){
    	scanf("%d",&tem);
    	a[tem]=1;
    	mn=std::min(mn,tem);
	}
	a.resize(m+mn+1);
	poly b(m+mn+1);
	for(int i=0;i<b.size();i++)b[i]=sub(0,mul(4,a[i]));
	b[0]=1;
	b=sqrt(b,b.size());
	for(int i=0;i<b.size();i++)b[i]=sub(0,b[i]);
	b[0]=add(b[0],1);
	for(int i=0;i<b.size();i++)b[i]=mul(b[i],(P+1)>>1);
	for(int i=0;i+mn<b.size();i++)b[i]=b[i+mn];b.resize(b.size()-mn);
	for(int i=0;i+mn<a.size();i++)a[i]=a[i+mn];a.resize(a.size()-mn);
	b=mul(b,inv(a,a.size()));
	for(int i=1;i<=m;i++)printf("%d\n",b[i]);
}