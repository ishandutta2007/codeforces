#include <bits/stdc++.h>

typedef std::vector<int> poly;
typedef long long ll;
#define pb push_back
poly A,B;
int n,R[2000001],lim,ksm[30],L,w[2000001],t1[2000001],t2[2000001],_mul[1000001],invmul[1000001];
poly val[1000001];
const int P=1000000007;
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
    for(register int i=0;i<lim;++i)if(i<R[i])std::swap(A[i],A[R[i]]);
    for(register int i=1;i<lim;i<<=1)
        for(register int j=0;j<lim;j+=(i<<1))
            for(register int k=0,t=1;k<i;++k){
                const int Ny=mul(A[i+j+k],w[i+k]);
                A[i+j+k]=sub(A[j+k],Ny);
                A[j+k]=add(A[j+k],Ny);
            }
}
inline void NTT_with_limit(int *A,const int &len){
    for(register int i=0;i<lim;++i)if(i<R[i])std::swap(A[i],A[R[i]]);
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
    NTT_with_limit(t1,std::min(size,lim>>1));
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
    NTT_with_limit(t1,std::min(size,lim>>1));
//	NTT(t1);
    lim=inv(lim);
    A.resize(0);
    for(int i=0;i<size;i++)A.pb(mul(t1[i],lim));
    return A;
}
inline poly inv(poly A,int n=-1){
	if(!~n)n=A.size();
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
inline poly Rev(poly A){std::reverse(A.begin(),A.end());return A;}
poly operator^(poly a,int n){
	if(a.size()==1){
		return a;
	}
	bool r=0;
	if(!a[0]){
		for(int i=0;i<a.size()-1;i++)a[i]=a[i+1];a.pop_back();
		r=1;
	}
	int v=inv(a[0]);
	for(int i=0;i<a.size();i++)a[i]=mul(a[i],v);
	a=ln(a,a.size());
	for(int i=0;i<a.size();i++)a[i]=mul(a[i],n);
	a=exp(a,a.size());
	if(r){
		a.resize(a.size()+n);
		for(int i=a.size()-1;~i;--i)a[i]=(i-n>=0)?a[i-n]:0;
	}
	v=inv(v);
	for(int i=0;i<a.size();i++)a[i]=mul(a[i],v);
    return a;
}
int vis[1000001],m,k,a[200001];
poly T1,T2;
poly calc(){
	poly f;
	f.push_back(0);
	for(int len=1;len<=m;len<<=1){
		f.resize(len);
		f.resize(len<<1);
		f=f-mul(((f^(k+1))-mul(f,T1)+T2),inv((k+1)*(f^k)-T1));
	}
	f.resize(m+1);
	return f;
}
std::priority_queue<std::pair<int,int> >heap;
poly f[200001];
int b[200001],top;
int t;
int C(int n,int m){
	if(n<m||m<0)return 0;
	return mul(mul(_mul[n],invmul[m]),invmul[n-m]);
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
	    srand(19260817);
	    m=read(),k=read();
		_mul[0]=_mul[1]=invmul[0]=invmul[1]=1;
		for(int i=2;i<=m;i++)_mul[i]=mul(_mul[i-1],i);
		for(int i=2;i<=m;i++)invmul[i]=mul(P-P/i,invmul[P%i]);
		for(int i=2;i<=m;i++)invmul[i]=mul(invmul[i-1],invmul[i]);
		int len=m;
		int ans=0,v=1;
		for(int i=1;i<=m;++i){
			if(len<0)break;
			v=mul(v,i);
			v=mul(v,qsm(m-i+1,P-2));
			ans=add(ans,mul(C(len,i),v));
			len-=k-1;
		}
		printf("%d\n",add(ans,1));
	}
}