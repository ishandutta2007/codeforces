#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
const int MAXN=2e6+10;
const double Pi=acos(-1.0);
struct complex
{
    double x,y;
    complex (double xx=0,double yy=0){x=xx,y=yy;}
}a[MAXN],b[MAXN];
complex operator + (complex a,complex b){ return complex(a.x+b.x , a.y+b.y);}
complex operator - (complex a,complex b){ return complex(a.x-b.x , a.y-b.y);}
complex operator * (complex a,complex b){ return complex(a.x*b.x-a.y*b.y , a.x*b.y+a.y*b.x);}// 
int N,M;
int l,r[MAXN];
int limit=1;
void fast_fast_tle(complex *A,int type)
{
    for(int i=0;i<limit;i++) 
        if(i<r[i]) swap(A[i],A[r[i]]);// 
    for(int mid=1;mid<limit;mid<<=1)//
    {
        complex Wn( cos(Pi/mid) , type*sin(Pi/mid) ); // 
        for(int R=mid<<1,j=0;j<limit;j+=R)
        {
            complex w(1,0);// 
            for(int k=0;k<mid;k++,w=w*Wn)// 
            {
                 complex x=A[j+k],y=w*A[j+mid+k];// 
                A[j+k]=x+y;
                A[j+mid+k]=x-y;
            }
        }
    }
}
int sb,cur,k,tmp;
ll res,ans[1005000],sum;
int main(){
    scanf("%d%d",&N,&sb);
    tmp=N;
    a[200005].x++;
    b[200005].x++;
    for(int i=1;i<=N;i++){
    	scanf("%d",&k);
    	if(k<sb){cur++;}
    	a[cur+200005].x++;
    	b[-cur+200005].x++;
	}
	N=M=400050;
    while(limit<=N+M) limit<<=1,l++;
    for(int i=0;i<limit;i++)
        r[i]= ( r[i>>1]>>1 )| ( (i&1)<<(l-1) ) ;
    fast_fast_tle(a,1);
    fast_fast_tle(b,1);
    for(int i=0;i<=limit;i++) a[i]=a[i]*b[i];
    fast_fast_tle(a,-1);
    for(int i=400010+1;i<=400010+tmp;i++){
    	res=(ll)(a[i].x/limit+0.5);
    	ans[i-400010]=res;
    	sum+=res;
	}
	ans[0]=1ll*tmp*(tmp+1)/2-sum;
	for(int i=0;i<=tmp;i++){
		printf("%lld ",ans[i]);
	}
}