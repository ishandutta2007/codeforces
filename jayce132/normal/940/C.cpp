#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
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

int n,k,mp[26],man[maxn],len,id[maxn];
char str[maxn];
void init()
{
	n=read();k=read();
	cin>>str;
	REP(i,0,len=(strlen(str)-1))
	{
		mp[str[i]-'a']=1;
	}
	int s=0;
	len++;
	REP(i,0,25){s+=mp[i];if(mp[i])id[s]=i;mp[i]=s;}
	man[min(k,n)]=1;
	DREP(i,min(k-1,n-1),0)man[i]=man[i+1]&&(mp[str[i]-'a']==s);
}

void doing()
{
	int flg=0;
	if(k>n)
	{
		REP(i,0,n-1)
		{
			printf("%c",str[i]);
		}
		REP(i,n,k-1)printf("%c",id[1]+'a');
		return;
	}
	REP(i,0,k-1)
	{
		if(flg)printf("%c",id[1]+'a');
		else
		if(!man[i+1] && i!=k-1)
		{
			printf("%c",str[i]);
		}else
		{
			printf("%c",id[mp[str[i]-'a']+1]+'a');
			flg=1;
		}
	}
}

int main()
{
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	init();
	doing();
	return 0;
}