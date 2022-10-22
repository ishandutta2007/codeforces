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

ll n,m,k,d,ans;

int main()
{
	n=read(); k=read(); m=read(); d=read();
    for(int y=1;y<=d;y++)  
    {  
        ll x=n/(k*y-k+1);  
        if(!x) break;  
        if(x>m) x=m;  
        ans=max(ans,x*y);  
    }  
    cout<<ans;  
    return 0; 
}