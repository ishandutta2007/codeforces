#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)

template <typename T> inline void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> inline void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}

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

const int N=1e3+5;
int n,p;
char qa[N],*s=qa+2,mx;

bool dfs(int x,bool have)
{
	if(x>n) return 1;
	char j;
	if(have==0) j=s[x];
	else j='a';
for(;j<mx;++j,have=1)
if(!(j==s[x-1]||(j==s[x-2])))
{
	s[x]=j;
	if(dfs(x+1,have))return 1;
}
     return 0;
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	cin>>n>>p;mx='a'+p;
	scanf("%s",s+1);s[n+1]=0;
	
	++s[n];
	int i=n;
	while(s[i]>=mx) { s[i]='a';--i;++s[i]; }
	if(i==0){puts("NO");return 0;}
	
	if(dfs(1,0)) printf("%s",s+1);
	else puts("NO");
}