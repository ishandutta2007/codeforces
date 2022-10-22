#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

char s1[maxn],s2[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		int cnt=0,f1=0,f2=0;
		scanf("%s",s1+1); scanf("%s",s2+1);
		int len1=strlen(s1+1),len2=strlen(s2+1);
		if(len1!=len2) {puts("No"); continue;}
		for(int i=1;i<=len1;i++) if(s1[i]!=s2[i]) cnt++;
		if(cnt!=2) {puts("No"); continue;}
		for(int i=1;i<=len1;i++)
		{
			if(s1[i]!=s2[i]&&f1==0) f1=i;
			else if(s1[i]!=s2[i]) f2=i;
		}
		if(s1[f1]==s1[f2]&&s2[f1]==s2[f2]) puts("Yes");
		else puts("No");
	}
	return 0;
}