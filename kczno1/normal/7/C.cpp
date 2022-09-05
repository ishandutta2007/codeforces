#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
void exgcd(int a,int &x,int b,int &y)
{
	if(!b)
	{
		x=1;y=0;return ;
	}
	exgcd(b,y,a%b,x);
	y-=(a/b)*x;
}
int main()
{
//	freopen("1.in","r",stdin);
	int a,b,c;
	cin>>a>>b>>c;
	if(!c){puts("0 0");return 0;}
	c=-c;
	int x=0,y=0;
	exgcd(a,x,b,y);
	ll d=(ll)a*x+(ll)b*y;
	if(c%d)puts("-1");
	else printf("%lld %lld\n",(ll)c/d*x,(ll)c/d*y);
}