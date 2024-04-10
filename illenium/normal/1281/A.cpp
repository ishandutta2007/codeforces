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

char s[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",s+1);
		int len=strlen(s+1);
		if(len>=2&&s[len-1]=='p'&&s[len]=='o') puts("FILIPINO");
		else if(len>=4&&s[len-3]=='d'&&s[len-2]=='e'&&s[len-1]=='s'&&s[len]=='u') puts("JAPANESE");
		else if(len>=4&&s[len-3]=='m'&&s[len-2]=='a'&&s[len-1]=='s'&&s[len]=='u') puts("JAPANESE");
		else if(len>=5&&s[len-4]=='m'&&s[len-3]=='n'&&s[len-2]=='i'&&s[len-1]=='d'&&s[len]=='a') puts("KOREAN");
	}
	return 0;
}