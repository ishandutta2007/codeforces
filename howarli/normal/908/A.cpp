#include <cstdio>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define min(q,w) ((q)>(w)?(w):(q))
#define max(q,w) ((q)<(w)?(w):(q))
using namespace std;
const int N=1500,INF=2147483640;
int read(int &n)
{
	char ch=' ';int q=0,w=1;
	for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}
int m,n,ans;
int main()
{
	int q,w;
	char ch=getchar();
	for(;(ch<='z'&&ch>='a')||(ch<='9'&&ch>='0');ch=getchar())
	{
		if(ch=='1'||ch=='3'||ch=='5'||ch=='7'||ch=='9'||ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')++ans;
	}
	printf("%d\n",ans);
	return 0;
}