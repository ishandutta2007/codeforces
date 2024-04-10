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
char s[N];
set<int>s0,s1;
vector<int>ans[N];int top;

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1);
	rep(i,1,n)
	if(s[i]=='0')s0.insert(i);
	else s1.insert(i);
	while(!s0.empty())
	{
		++top;
		int x=*s0.begin();
		s0.erase(x);
		ans[top].pb(x);
		while(s1.lower_bound(x)!=s1.end())
		{
			x=*s1.lower_bound(x);
			ans[top].pb(x);
			s1.erase(x);
			if(s0.lower_bound(x)==s0.end())
			{
				puts("-1");
				return 0;
			}
			x=*s0.lower_bound(x);
			s0.erase(x);
			ans[top].pb(x);
		}
	}
	if(!s1.empty())puts("-1");
	else
	{
		printf("%d\n",top);
		rep(i,1,top)
		{
			printf("%d ",(int)ans[i].size());
			for(auto x:ans[i])printf("%d ",x);
			puts("");
		}
	}
}