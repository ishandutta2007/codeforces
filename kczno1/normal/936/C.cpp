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
const int N=2000+5,U=6100+5;
char need[N][N];
char qa[2][N],*s=qa[0],*s0=qa[1];
int cnt[256];
int n;
int ans[U],top;
void rev(int x)
{
	if(x>n)return ;
	ans[++top]=n-x+1;
	swap(s0,s);
	int t=0;
	per(i,n,x)s[++t]=s0[i];
	rep(i,1,x-1)s[++t]=s0[i];	
}

int main()
{
	//freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	cin>>n;
	scanf("%s",s+1);
	scanf("%s",need[n]+1);
	rep(i,1,n)++cnt[s[i]];
	rep(i,1,n)--cnt[need[n][i]];
	rep(i,1,250)
	if(cnt[i])
	{
		puts("-1");
		return 0;
	}
	per(i,n-1,1)
	{
		rep(j,1,i)need[i][j]=need[i+1][j+1];
		reverse(need[i]+1,need[i]+i+1);
	}
	per(i,n,1)
	if(s[i]==need[1][1])
	{
		rev(i+1);
		break;
	}
	rep(i,2,n)
	{
		rev(n-(i-1)+1);
		per(j,n,1)
		if(s[j]==need[i][1])
		{
			rev(j);
			rev(n-j+1+i);
			break;
		}
	}
	printf("%d\n",top);
	rep(i,1,top)printf("%d ",ans[i]);
}