//# pragma GCC optimize ("O2")
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
    int x=c-'0';
    while(gc>='0')x=x*10+c-'0';
    return x;
}

template<typename T>
struct vec
{
T *a;
int n;
void push_back(const T &x)
{
    if((n&-n)==n)//a=(T*)realloc(a,(n*2+1)*sizeof(T));
    {
        T *_a=new T [n*2+1];
        memcpy(_a,a,n*sizeof(T));
        a=_a;
    }
    a[n++]=x;
}
};

int main()
{
   // freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
    ll a,b;
    cin>>a>>b;
    if(b-a<=5) 
    {
    	int ans=1;
    	while(++a<=b) ans*=a%10;
    	cout<<ans%10;
    }
    else puts("0");
}