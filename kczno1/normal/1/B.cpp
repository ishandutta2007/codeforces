//by kcz 1552920354@qq.com
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
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)

char s[100];
int n;
void AB()
{
	int i=0,y=0;
	while(!isdigit(s[i]))
	{
		y=y*26+s[i]-'A'+1;
		++i;
	}
	int x;
	sscanf(s+i,"%d",&x);
	printf("R%dC%d\n",x,y);
}
char *trans(int x)
{
	static char ans[100];
	int top=0;
	for(;x;x/=26){--x;ans[top++]='A'+x%26;}
	reverse(ans,ans+top);
	ans[top]=0;
	return ans;
}
void RC(int i)
{
	int x,y;
	sscanf(s+1,"%d",&x);
	sscanf(s+i+1,"%d",&y);
	printf("%s%d\n",trans(y),x);
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	int tt;
	cin>>tt;
	while(tt--)
	{
		scanf("%s",s);
		n=strlen(s);
		if(!isdigit(s[1]))AB();
		else
		{
			int i=1;
			while(isdigit(s[i]))++i;
			if(s[i]=='C') RC(i);
			else AB();
		}
	}
}