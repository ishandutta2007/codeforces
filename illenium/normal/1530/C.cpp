#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define ins insert
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

int n,a[maxn],b[maxn],t1,t2;
multiset <int> s1,s2,s3;
multiset <int>::iterator it;

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); t1=0; t2=0; s1.clear(); s2.clear(); s3.clear();
		rep(i,1,n) a[i]=read(),s1.ins(a[i]),t1+=a[i];
		rep(i,1,n) b[i]=read(),s2.ins(b[i]),t2+=b[i];
		int tmp=n-n/4,p=0;
		while(s1.size()!=tmp)
		{
			it=s1.begin(); p=*it; t1-=p; s1.erase(it);
			it=s2.begin(); p=*it; t2-=p; s2.erase(it); s3.ins(p);
		}
		int ans=0;
		while(t1<t2)
		{
			ans++; t1+=100; s1.ins(100);
			if(s3.size())
			{
				it=s3.end(); it--; s2.ins(*it); p=*it; t2+=p; s3.erase(it);
			}
			else s2.ins(0);
			int nw=(n+ans)-(n+ans)/4;
			while(s1.size()!=nw)
			{
				it=s1.begin(); p=*it; t1-=p; s1.erase(it);
				it=s2.begin(); p=*it; t2-=p; s2.erase(it); s3.ins(p);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}