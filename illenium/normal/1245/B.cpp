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
		int n=read();
		int a,b,c,a1=0,b1=0,c1=0;
		int tmp=0;
		cin>>a>>b>>c; cin>>(s+1);
		int len=strlen(s+1);
		for(int i=1;i<=len;i++) if(s[i]=='R') a1++;
		else if(s[i]=='P') b1++;
		else c1++;
		tmp=min(a1,b)+min(b1,c)+min(c1,a);
		int f1=0,f2=0,f3=0;
		if(b>a1) f1=b-a1;
		if(c>b1) f2=c-b1;
		if(a>c1) f3=a-c1;
		if(tmp*2>=n)
		{
			puts("YES");
			for(int i=1;i<=len;i++)
			{
				if(s[i]=='R'&&b>0) printf("P"),b--;
				else if(s[i]=='P'&&c>0) printf("S"),c--;
				else if(s[i]=='S'&&a>0) printf("R"),a--;
				else
				{
					if(f1>0) printf("P"),f1--;
					else if(f2>0) printf("S"),f2--;
					else if(f3>0) printf("R"),f3--;
				}
			}
			puts("");
		}
		else puts("NO");
	}
	return 0;
}