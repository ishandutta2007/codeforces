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
int n,k,a[N];
char b[N];

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","r",stdin);
	n=read();
	rep(i,1,n)a[i]=read();
	scanf("%s",b+1);
	int r=1e9,l=-1e9;
	rep(i,5,n)
	if(b[i]!=b[i-1])
	{
		if(b[i]=='0')chmin(r,min(min(min(min(a[i],a[i-1]),a[i-2]),a[i-3]),a[i-4])-1);
		else chmax(l,max(max(max(max(a[i],a[i-1]),a[i-2]),a[i-3]),a[i-4])+1);
	}
	cout<<l<<" "<<r;
}