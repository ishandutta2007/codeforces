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

const int N=2e5+5;
int n,T;
pii a[N];
deque<pii>q1,q2;
ll get(deque<pii> q)
{
	ll ans=0;
	for(auto i:q)ans+=(ll)i.first*i.second;
	return ans;
}
double cal(deque<pii> q,ll s)
{
	double ans=0;
	sort(q.begin(),q.end());
	for(auto i:q)
	{
		ll d=(ll)i.first*i.second;
		if(s>=d)
		{
			ans+=i.second;
			s-=d;
		}
		else 
		{
			ans+=(double)s/i.first;
			break;
		}
	}
	return ans;
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	n=read();T=read();
	rep(i,1,n)a[i].second=read();
	rep(i,1,n)a[i].first=read();
	double ans=0;
	rep(i,1,n)
	if(a[i].first==T)ans+=a[i].second;
	else
	if(a[i].first<T)
	{
		q1.push_back(mp(T-a[i].first,a[i].second));
	}
	else
	{
		q2.push_back(mp(a[i].first-T,a[i].second));
	}
	ll s=min(get(q1),get(q2));
	printf("%.9lf\n",ans+cal(q1,s)+cal(q2,s));
}