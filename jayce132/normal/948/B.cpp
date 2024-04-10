#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<map>
#include<stack>
#include<vector>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
inline int read()
{
    int sum=0,p=1;char ch=getchar();
    while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
    if(ch=='-')p=-1,ch=getchar();
    while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
    return sum*p;
}

bool zs(int x)
{
	REP(i,2,sqrt(x))
		if(!(x%i))return false;
	if(x>1)return 1;
	else return 0;
}

int ans=1e6+20;

int vis[1000020];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
#endif
	int x=read();
	DREP(i,x-1,2)
	{
		if(x%i)continue;
		if(zs(i))
		{
			REP(p,x-i+1,x) {
				if(vis[p])continue;
				vis[p]=1;
				int flg=0;
				REP(j,2,sqrt(p))
				{
					int xx=p/j;
					if(p%j)continue;
					if(zs(xx))
					{ 
						ans=min(ans,p-xx+1);
						flg=1;
						break;
					}
				}
				if(flg)continue;
				DREP(j,sqrt(p),2)
				{
					int xx=j;
					if(p%j)continue;
					if(zs(xx))
					{ 
						ans=min(ans,p-xx+1);
						break;
					}
				}
			}
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}