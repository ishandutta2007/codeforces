//by kcz 1552920354@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define mp make_pair
#define gc (c=getchar())
char readc()
{
	char c;
	while(gc<'-');
	return c;
}
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

const int N=1e5+5;
int n;
pii a[N];
int q1[N],q2[N],a1[N],a2[N];

pii na[N];
ll cmp(const pii &a,const pii &b)
{
	return (ll)a.first*b.second-(ll)b.first*a.second;
}
bool na_xiao(int x,int y)
{
	return cmp(na[x],na[y])<0;
}
void get(int *q,int *a,int w)
{
	rep(i,1,n)na[i]=mp(abs(::a[i].first),abs(::a[i].second+w));
	rep(i,1,n)q[i]=i;
	sort(q+1,q+n+1,na_xiao);
	int m=1;
	a[q[1]]=1;
	rep(i,2,n)
	{
		if(cmp(na[q[i]],na[q[i-1]]))++m;
		a[q[i]]=m;
	}
}

int c[N];
void add(int i)
{
	for(;i;i-=i&-i)++c[i];
}
int qiu(int i)
{
	int ans=0;
	for(;i<=n;i+=i&-i)ans+=c[i];
	return ans;
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	n=read();int w=read();
	rep(i,1,n){a[i].first=read();a[i].second=read();}
	get(q1,a1,-w);
	get(q2,a2,w);
	ll ans=0;
	for(int l=1;l<=n;)
	{
		int r=l;
		while(r<n&&a1[q1[r+1]]==a1[q1[l]])++r;
		ans+=(ll)(r-l+1)*(r-l)/2;
		rep(i,l,r)ans+=qiu(a2[q1[i]]);
		rep(i,l,r)add(a2[q1[i]]);
		l=r+1;
	}
	cout<<ans<<endl;
}