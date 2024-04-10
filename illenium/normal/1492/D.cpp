#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int a,b,k,a1[maxn],a2[maxn];

int main()
{
	cin>>a>>b>>k;
	if(a==0||b==1)
	{
		if(k==0)
		{
			puts("Yes");
			rep(i,1,b) printf("1"); rep(i,1,a) printf("0"); puts("");
			rep(i,1,b) printf("1"); rep(i,1,a) printf("0"); puts("");
		}
		else puts("No");
	}
	else if(k>a+b-2) puts("No");
	else if(k==0)
	{
		puts("Yes");
		rep(i,1,b) printf("1"); rep(i,1,a) printf("0"); puts("");
		rep(i,1,b) printf("1"); rep(i,1,a) printf("0");
	}
	else
	{
		puts("Yes");
		rep(i,1,a+b) a1[i]=-1,a2[i]=-1;
		a1[1]=1; a2[1]=1; a1[a+b]=0; a2[a+b]=1; a1[a+b-k]=1; a2[a+b-k]=0;
		int len=a+b; a--; b-=2;
		rep(i,1,len)
		{
			if(a1[i]!=-1) continue;
			if(a) a--,a1[i]=0,a2[i]=0;
			else b--,a1[i]=1,a2[i]=1;
		}
		
		rep(i,1,len) printf("%d",a1[i]); puts("");
		rep(i,1,len) printf("%d",a2[i]); puts("");
	}
	return 0;
}