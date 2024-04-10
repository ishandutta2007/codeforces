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

int n;

pair<int,int>a[1020];

inline bool cmp (const pair<int,int> a,const pair<int,int> b){
	return a.first==b.first?a.second<b.second:a.first>b.first;
}

inline void init()
{
	n=read();
	REP(i,1,n)
	{
		a[i]=make_pair(read()+read()+read()+read(),i);
	}
	sort(a+1,a+n+1,cmp);
	REP(i,1,n)if(a[i].second==1)printf("%d\n",i),exit(0);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
#endif
	init();
	return 0;
}