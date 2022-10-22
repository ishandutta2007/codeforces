#include<iostream>  
#include<cstdio>  
#include<cmath>  
#include<cstdlib>  
#include<cstring>  
#include<algorithm>  
#define F(i,j,n) for(int i=j;i<=n;i++)  
#define D(i,j,n) for(int i=j;i>=n;i--)  
#define ll long long  
  
using namespace std; 
const int maxn=1e6; 
int n,m,len,rev[maxn];  
struct cp  
{  
    double x,y;  
    inline cp operator +(cp b){return (cp){x+b.x,y+b.y};}  
    inline cp operator -(cp b){return (cp){x-b.x,y-b.y};}  
    inline cp operator *(cp b){return (cp){x*b.x-y*b.y,x*b.y+y*b.x};}  
}a[maxn],b[maxn],c[maxn];  
const double PI=acos(-1.0);  
inline int read()  
{  
    int x=0,f=1;char ch=getchar();  
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}  
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  
    return x*f;  
}  
inline void fft(cp *x,int n,int flag)  
{  
    F(i,0,n-1) if (rev[i]>i) swap(x[i],x[rev[i]]);  
    for(int m=2;m<=n;m<<=1)  
    {  
        cp wn=(cp){cos(2.0*PI/m*flag),sin(2.0*PI/m*flag)};  
        for(int i=0;i<n;i+=m)  
        {  
            cp w=(cp){1.0,0};  
            int mid=m>>1;  
            F(j,0,mid-1)  
            {  
                cp u=x[i+j],v=x[i+j+mid]*w;  
                x[i+j]=u+v;x[i+j+mid]=u-v;  
                w=w*wn;  
            }  
        }  
    }  
    if(flag==-1) F(i,0,n-1) x[i].x/=n;  
}  
int main()  
{  int x,y,s=0;
	scanf("%d%d",&n,&x);
	a[0].x=1;
	for(int i=1;i<=n;++i){
		scanf("%d",&y);
		if(y<x) ++s;
		a[s].x=a[s].x+1;
	}
	ll ANS=0;
	for(int i=0;i<=n;++i){
		ANS=ANS+(ll)(a[i].x-1)*(ll)a[i].x/2;
	}
	printf("%I64d",ANS);
    ++n;int nn=n;
    F(i,0,n-1) b[n-1-i].x=a[i].x; 
    n=2*n-1;m=1;
    while (m<n) m<<=1,len++;  
    n=m;  
    F(i,0,n-1)  
    {  
        int t=i,ret=0;  
        F(j,1,len){ret<<=1;ret|=(t&1);t>>=1;}  
        rev[i]=ret;  
    }  
    fft(a,n,1);fft(b,n,1);  
    F(i,0,n-1) c[i]=a[i]*b[i];  
    fft(c,n,-1);  
    F(i,1,nn-1) printf(" %I64d",(ll)(c[nn-1+i].x+0.5));
	printf("\n");  
    return 0;  
}