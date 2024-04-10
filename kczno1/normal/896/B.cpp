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

const int N=1000+5;const ll inf=1e18+1;
int n,m,c,head,tail,a[N];

int place(int x)
{
	if(x<=c/2)
    	{
    		if(x>=a[head])
			{
				return ++head;
			}
    		else 
    		{
    			int i=1;
    			while(a[i]<=x)++i;
    			a[i]=x;
    			return i;
    		}
    	}
    else
    {
    	if(x<=a[tail])
			{
				return --tail;
			}
    		else 
    		{
    			int i=n;
    			while(x<=a[i])--i;
    			a[i]=x;
    			return i;
    		}
    }
}

int main()
{
    //freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
    cin>>n>>m>>c;
    head=0;tail=n+1;a[tail]=c;
    while(m--)
    {
    	int x;
    	cin>>x;
    	int ans=place(x);
    	a[ans]=x;
    	cout<<ans<<endl;
    	if(head+1==tail)return 0;
    	fflush(stdout);
    }
}