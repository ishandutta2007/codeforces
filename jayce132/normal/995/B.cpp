#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)

inline int read()
{
    int s=0,f=1;char ch=getchar();
    while(!('0'<=ch && ch<='9') && ch!='-')ch=getchar();
    if(ch=='-')ch=getchar(),f=-1;
    while('0'<=ch && ch<='9')s=s*10+ch-'0',ch=getchar();
    return ~f?s:-s;
}

const int maxn=220;

int fi[maxn],se[maxn];

int main()
{
    int n=read(),a[maxn];
    REP(i,1,2*n)
    {
	a[i]=read();
	if(!fi[a[i]])fi[a[i]]=i;
	else se[a[i]]=i;
    }
    int ans=0;
    REP(i,1,n)REP(j,i+1,n)
    {
	if(fi[i]<=fi[j] && se[j]<=se[i])ans+=2;
	else if(fi[i]<=fi[j] && fi[j]<=se[i] && se[i]<=se[j])ans++;
	else if(fi[j]<fi[i] && se[i]<se[j])ans+=2;
	else if(fi[j]<fi[i] && fi[i]<se[j] && se[j]<se[i])ans++;
    }
    printf("%d\n",ans);
    return 0;
}