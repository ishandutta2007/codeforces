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

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
} 

ll sum=1,ans=0,n;
struct st{ll x,y;}a[maxn];  
inline bool cmp(st q,st w){return q.x<w.x;}  
inline bool cmo(st q,st w){return q.y<w.y;}

inline bool cmi(st q,st w)  
{  
    if(q.x==w.x)  
    return q.y<w.y;  
    return q.x<w.x;  
}
 
int main()  
{
	n=read();
	for(int i=0;i<n;i++) a[i].x=read(),a[i].y=read();
    sort(a,a+n,cmp);  
    for(int i=1;i<n;i++)  
	{  
	    if(a[i].x==a[i-1].x)  sum++;  
	    else ans=ans+sum*(sum-1)/2,sum=1;
	}
    ans=ans+sum*(sum-1)/2; sum=1;
    sort(a,a+n,cmo);
    for(int i=1;i<n;i++)
	{
	    if(a[i].y==a[i-1].y) sum++;
	    else ans=ans+sum*(sum-1)/2,sum=1;
	}
    ans=ans+sum*(sum-1)/2; sum=1;
    sort(a,a+n,cmi);
    for(int i=1;i<n;i++)
	{
	    if(a[i].y==a[i-1].y&&a[i].x==a[i-1].x) sum++;
	    else ans-=sum*(sum-1)/2,sum=1;
	}
	ans-=sum*(sum-1)/2;
	printf("%lld\n",ans);
	return  0;
}