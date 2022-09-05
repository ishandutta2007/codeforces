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

const int N=3e4+5,D=1e9+7;
ll m;
int n,a[N];ll l[N],r[N];
ll q[N];int top;
int s[N][3];
struct M
{
ll a[3][3];
ll* operator [](int x)
{
	return a[x];
}
const ll* operator [](int x)const
{
	return a[x];
}
};
M operator *(const M &a,const M &b)
{
	M ans={};
	rep(i,0,2)
	rep(k,0,2)
	rep(j,0,2)(ans[i][j]+=a[i][k]*b[k][j])%=D;
	return ans;
}
M x0,ans;
void mi(M x,ll y)
{
	while(y)
	{
		if(y&1)ans=ans*x;
		x=x*x;y>>=1;
	}
}
M solve()
{
	sort(q+1,q+top+1);
	top=unique(q+1,q+top+1)-q-1;
	rep(i,1,n)
	{
		++s[lower_bound(q+1,q+top+1,l[i])-q][a[i]];
		--s[lower_bound(q+1,q+top+1,r[i]+1)-q][a[i]];
	}
	rep(i,1,top)
	rep(j,0,2)s[i][j]+=s[i-1][j];

	rep(i,0,2)ans[i][i]=1;
	rep(i,1,top-1)
	{
		M x=x0;
		rep(j,0,2)
		if(s[i][j])
		rep(k,0,2)x[k][j]=0;
		mi(x,q[i+1]-q[i]);
	}
	return ans;
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	rep(i,0,2)
	rep(j,0,2)
	if(abs(i-j)<=1)x0[i][j]=1;
	cin>>n>>m;
	rep(i,1,n)
	{
		cin>>a[i]>>l[i]>>r[i];
		--a[i];
		q[++top]=l[i];q[++top]=r[i]+1;
	}
	q[++top]=1;q[++top]=m+1;
	++n;
	a[n]=0;l[n]=r[n]=1;
	++n;
	a[n]=2;l[n]=r[n]=1;
	q[++top]=2;
	cout<<solve()[1][1];
}