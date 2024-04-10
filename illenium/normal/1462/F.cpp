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

struct node{int l,r;}p[maxn];
int b1[maxn],b2[maxn],t1,t2,c1,c2,C1[maxn],C2[maxn];

inline void a1(int x,int val){for(int i=x;i<=t1;i+=i&-i) C1[i]+=val;}
inline int q1(int x){int res=0; for(int i=x;i;i-=i&-i) res+=C1[i]; return res;};
inline void a2(int x,int val){for(int i=x;i<=t2;i+=i&-i) C2[i]+=val;}
inline int q2(int x){int res=0; for(int i=x;i;i-=i&-i) res+=C2[i]; return res;};

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(); rep(i,1,n) p[i].l=read(),p[i].r=read();
		c1=0,c2=0;
		rep(i,1,n) b1[++c1]=p[i].l,b2[++c2]=p[i].r;
		sort(b1+1,b1+c1+1); sort(b2+1,b2+c2+1);
		t1=unique(b1+1,b1+c1+1)-b1-1;
		t2=unique(b2+1,b2+c2+1)-b2-1;
		
		rep(i,1,n)
		{
			int p1=lower_bound(b1+1,b1+t1+1,p[i].l)-b1; a1(p1,1);
			int p2=lower_bound(b2+1,b2+t2+1,p[i].r)-b2; a2(p2,1);
		}
		
		int ans=inf;
		rep(i,1,n)
		{
			int res1=lower_bound(b1+1,b1+t1+1,p[i].r+1)-b1;
			int res2=upper_bound(b2+1,b2+t2+1,p[i].l-1)-b2;
			//cout<<res1<<" "<<res2<<" "<<n-q1(res1-1)<<" "<<q2(res2)<<endl;
			ans=min(ans,n-q1(res1-1)+q2(res2-1));
		}
		
		rep(i,1,n) C1[i]=0,C2[i]=0;
		printf("%d\n",ans);
	}
	return 0;
}