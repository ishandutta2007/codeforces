#pragma GCC optimize(2)
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

int a[maxn],n;

int main()
{
	int T=read();
	while(T--)
	{
		vector <int> v1,v2; v1.clear(); v2.clear();
		n=read();
		rep(i,1,2*n)
		{
			a[i]=read();
			if(a[i]%2==1) v1.pb(i); else v2.pb(i);
		}
		if(v1.size()%2==0)
		{
			if(v1.size()>0)
			{
				for(int i=0;i<v1.size()-2;i+=2) printf("%d %d\n",v1[i],v1[i+1]);
				for(int i=0;i<v2.size();i+=2) printf("%d %d\n",v2[i],v2[i+1]);
			}
			else
			{
				for(int i=0;i<v1.size();i+=2) printf("%d %d\n",v1[i],v1[i+1]);
				for(int i=0;i<v2.size()-2;i+=2) printf("%d %d\n",v2[i],v2[i+1]);
			}
		}
		else
		{
			for(int i=0;i<v1.size()-1;i+=2) printf("%d %d\n",v1[i],v1[i+1]);
			for(int i=0;i<v2.size()-1;i+=2) printf("%d %d\n",v2[i],v2[i+1]);
		}
	}
	return 0;
}