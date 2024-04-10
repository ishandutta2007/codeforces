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
int cnt2,w[maxn],e[maxn],ans;

int main()
{
	int n=read(); scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		if(s[i]=='G')
		{
			cnt2++; cnt=0;
			while(s[i]=='G') cnt++,i++;
			w[cnt2]=cnt; e[cnt2]=i-1;
		}
	}
	for(int i=1;i<=cnt2;i++) ans=max(ans,w[i]);
	if(cnt2==1) cout<<w[1]<<endl;
	else if(cnt2==2)
	{
		if(s[e[1]+2]=='G') cout<<w[1]+w[2]<<endl;
		else cout<<max(w[1]+1,w[2]+1)<<endl;
	}
	else
	{
		for(int i=1;i<=cnt2;i++)
		{
			int tmp=0;
			if(s[e[i]+2]=='G') tmp=w[i]+w[i+1]+1;
			ans=max(ans,tmp);
		}
		for(int i=1;i<=cnt2;i++) ans=max(w[i]+1,ans);
		cout<<ans<<endl;
	}
	return 0;
}