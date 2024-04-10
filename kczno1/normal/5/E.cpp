//by kcz 1552920354@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T&x,const T &y)
{
    if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
    if(x<y)x=y;
}
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned short us;
typedef unsigned int ui;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define mp make_pair
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
#undef gc

ll sqr(const ll &x)
{
    return x*x;
}
const int N=1e6+5;
int a[N],a0[N];
pii st[N];int top;
ll solve(int n)
{
    top=1;st[1]=mp(a[1],1);
    ll ans=0;
    rep(i,2,n)
    {
        while(top&&st[top].first<a[i]){ans+=st[top].second;--top;}
        if(st[top].first==a[i])
        {
            ans+=st[top].second+bool(top>1);
            ++st[top].second;
        }
        else 
        {
			++ans;
            st[++top]=mp(a[i],1);
        }
    }
	static bool have[N];
	int mx=0;
	rep(i,2,n)
	{
		if(a[i]>=mx){have[i]=1;mx=a[i];}
	}
	mx=0;
	per(i,n,2)
	if(a[i]>=mx)
	{
		ans+=!have[i];
		mx=a[i];
	}
    return ans;
}
int main()
{
  //  freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
    int n;
    cin>>n;
    rep(i,1,n)a0[i]=read();
	int mxi=1;
	rep(i,2,n)
	if(a0[i]>a0[mxi])mxi=i;
	int top=0;
	rep(i,mxi,n)a[++top]=a0[i];
	rep(i,1,mxi-1)a[++top]=a0[i];
    cout<<solve(n);
}