#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=1e5+5;
const int inf=1e9+maxn;

int N,M,W,arr[maxn],v[maxn];

inline bool judge(int k)
{
    int ti=M,n=0;
    memset(v,0,sizeof(v));
    for(int i=1;i<=N;i++)
	{
		n+=v[i];
	    int tmp=max(k-arr[i]-n,0); ti-=tmp;
	    if(ti<0) return false;
	    if(i+1<=N) v[i+1]+=tmp;
	    if(i+W<=N) v[i+W]-=tmp;
	}
    return true;
}

inline int bsearch(int l, int r)
{
    for(int i=0;i<80;i++)
	{
	    int mid=(r+l)/2;
	    if(judge(mid)) l=mid;
	    else r=mid;
	}
    return l;
}

int main()
{
	scanf("%d%d%d",&N,&M,&W);
	for(int i=1;i<=N;i++) scanf("%d",&arr[i]);
	printf("%d\n", bsearch(1,inf));
	return 0;
}