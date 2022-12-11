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

int main()
{
	int n=read(),a[100020]={0};
	REP(i,1,n)
	{
		char ch;
		cin>>ch;
		if(ch=='U')a[i]=1;else a[i]=0;
	}
	int ans=0,x=0,y=0;
	REP(i,1,n-1)
	{
		if(a[i])x++;else y++;
		if(x==y)
		{
			if(a[i]==a[i+1])ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}