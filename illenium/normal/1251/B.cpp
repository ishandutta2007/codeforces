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
vector <int> vec;

int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		int ans=0,f1=0,f2=0,flag=0,tmp=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			if(strlen(s+1)%2==1) {ans++; flag=1; continue;}
			for(int j=1;j<=strlen(s+1);j++) if(s[j]=='0') f1++; else f2++;
			if(f1%2==0) ans++;
			else tmp++;
			f1=0; f2=0;
		}
		if(flag==1) cout<<n<<endl;
		else if(tmp%2==0) cout<<n<<endl;
		else cout<<n-1<<endl;
	}
	return 0;
}