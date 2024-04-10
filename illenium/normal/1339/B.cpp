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

int a[maxn];
vector <int> vec;
multiset <int> s;
multiset <int>::iterator it;

int main()
{
	int T=read();
	while(T--)
	{
		vec.clear(); s.clear();
		int n=read(); rep(i,1,n) a[i]=read(),s.insert(a[i]);
		while(vec.size()<n)
		{
			it=s.end(); it--; vec.pb(*it); s.erase(it); if(vec.size()==n) break;
			it=s.begin(); vec.pb(*it); s.erase(it);
		}
		for(int i=vec.size()-1;i>=0;i--) printf("%d ",vec[i]); puts("");
	}
	return 0;
}