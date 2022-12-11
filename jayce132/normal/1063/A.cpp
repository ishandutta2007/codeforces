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
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=1e5+20;
const int maxp=26;

int tag[26],id[26];
char str[maxn];
int st[maxn],top;

int main()
{
	int n=read();
	scanf("%s",str+1);
	REP(i,1,n)tag[str[i]-'a']++;
	REP(i,0,maxp-1)id[i]=i;
	sort(id,id+maxp,[](int a,int b){ return tag[a]>tag[b];});
	REP(i,0,maxp-1)if(tag[id[i]])
	{
		int u=id[i];
		if(top && tag[st[top]]==tag[u]+1)
		{
			printf("%c",st[top]+'a');REP(j,1,tag[u])printf("%c%c",u+'a',st[top]+'a');
			top--;
		}else
		{
			st[++top]=u;
		}
		
	}
	REP(i,1,top)REP(j,1,tag[st[i]])printf("%c",st[i]+'a');
	
	return 0;
}