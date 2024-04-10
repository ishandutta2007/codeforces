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
char s[N];
bool have[256];

int main()
{
	//freopen("1.in","r",stdin);//freopen("1.out","r",stdin);
	int n,k;
	cin>>n>>k;
	scanf("%s",s+1);
	char mn=s[1],mx=s[1];
	rep(i,1,n)
	{
		have[s[i]]=1;
		chmin(mn,s[i]);
		chmax(mx,s[i]);
	}
	if(k>n)
	{
		rep(i,n+1,k)s[i]=mn;
		printf("%s\n",s+1);
		return 0;
	}
	int i=k;
	while(s[i]==mx)--i;
	int j=s[i]+1;
	while(!have[j])++j;
	s[i]=j;
	while(++i<=k)s[i]=mn;
	s[k+1]=0;
	printf("%s\n",s+1);
}