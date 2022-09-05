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

const int N=50+5;
char s[N][N];

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	int n=read(),m=read();
	rep(i,1,n)scanf("%s",s[i]+1);
	rep(i,1,n)
	rep(j,1,n)
	{
		int tot_cnt=0,cnt=0;
		rep(k,1,m)
		if(s[i][k]=='#')
		{
			++tot_cnt;
			cnt+=s[j][k]=='#';	
		}
		if(cnt>0&&cnt<tot_cnt)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}