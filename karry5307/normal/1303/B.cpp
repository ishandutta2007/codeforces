#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define iter iterator  
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll test,n,g,b,x,y;
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
} 
inline void solve()
{
	n=read(),g=read(),b=read();
	x=((n+1)/2)/g*(g+b)+(((n+1)/2)%g==0?-b:((n+1)/2)%g);
	cout<<max(x,n)<<endl;
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}