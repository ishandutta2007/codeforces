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
#define rep(i,l,r) for(int i=l,i##_r=r;i<=i##_r;++i)
#define per(i,r,l) for(int i=r,i##_l=l;i>=i##_l;--i)
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

const int N=1e6+5;
int mx[N];

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
const int n=1e6;
	rep(i,1,n)mx[i]=1;
	rep(i,2,n)
	if(mx[i]==1)
	for(int j=i+i;j<=n;j+=i)mx[j]=i;
	int x2;
	cin>>x2;
	int ans=x2;
	rep(x1,x2-mx[x2]+1,x2)chmin(ans,x1-mx[x1]+1);
	cout<<ans;
}