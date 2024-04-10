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

int n,a[maxn],nxt[maxn],p[maxn],cnt;
vector <int> a1,a2;

int main()
{
	n=read(); rep(i,1,n) a[i]=read(),nxt[i]=n+1;
	rep(i,1,n) nxt[p[a[i]]]=i,p[a[i]]=i;
	int ed1=n+1,ed2=n+1;
	rep(i,1,n)
	{
		if(!a1.size()) a1.pb(i),ed1=i;
		else if(a[i]==a[ed1])
		{
			if(a2.size()&&a[i]==a[ed2]) a2.pb(i),ed2=i;
			a1.pb(i); ed1=i; cnt++;
		}
		else if(a2.size()&&a[i]==a[ed2]) a2.pb(i),ed2=i,cnt++;
		else if(!a2.size()) a2.pb(i),ed2=i;
		else if(nxt[ed1]<nxt[ed2]) a2.pb(i),ed2=i;
		else a1.pb(i),ed1=i;
	}
	cout<<n-cnt<<endl;
	return 0;
}