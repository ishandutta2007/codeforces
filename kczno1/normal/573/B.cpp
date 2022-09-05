#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)

template <typename T> inline void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> inline void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}

#define gc (c=getchar())
int read()
{
	char c;
	while(gc<'-');
	if(c=='-')
	{
		int x=gc-'0';
	    while(gc>='0')x=x*10+c-'0';
	    return -x;
	}
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}

template<typename T>
struct vec
{
T *a;
int n;
void clear()
{
    if (n>0) delete[] a;
    n=0;
}
void pb(const T &x)
{
    if((n&-n)==n)a=(T*)realloc(a,(n*2+1)*sizeof(T));
    /*{
        T *_a=new T [n*2];
        memcpy(_a,a,n*sizeof(T));
        a=_a;
    }*/
    a[n++]=x;
}
};
#define fore(arr) for(int *it=arr.a,*end=it+arr.n;it!=end;++it)

const int N=1e6+5;
int n,h[N],f[N];

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	cin>>n;
	rep(i,1,n) h[i]=read();
	rep(i,1,n) chmin(h[i],h[i-1]+1);
	per(i,n,1) chmin(h[i],h[i+1]+1);
	
	int ans=0;
	rep(i,1,n) chmax(ans, h[i] );
	cout<<ans;
}