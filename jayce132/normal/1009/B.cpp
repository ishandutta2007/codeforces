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

const int maxn=1e5+20;

char str[maxn],p[maxn];
int tot1,tot2;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
#endif
	scanf("%s",str+1);
	int n=strlen(str+1);
	REP(i,1,n)if(str[i]=='1')tot1++;
	else p[++tot2]=str[i];
	int flg=0;
	REP(i,1,tot2)
	{
		if(p[i]=='2' && !flg)
		{
			flg=1;
			REP(j,1,tot1)printf("1");
		}
		printf("%c",p[i]);
	}
	if(!flg)REP(j,1,tot1)printf("1");
	return 0;
}