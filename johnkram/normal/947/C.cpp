#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
int n,m,root,i,a[MAXN],b[MAXN],c[10000005][2],s[10000005];
void ins(int &R,int x,int d)
{
	if(!R)R=++m;
	s[R]++;
	if(!~d)return;
	ins(c[R][x>>d&1],x,d-1);
}
int ask(int R,int x,int d)
{
	s[R]--;
	if(!~d)return 0;
	bool b=x>>d&1;
	if(s[c[R][b]])return ask(c[R][b],x,d-1);
	return 1<<d|ask(c[R][!b],x,d-1);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)
	{
		scanf("%d",b+i);
		ins(root,b[i],29);
	}
	for(i=1;i<=n;i++)printf("%d ",ask(root,a[i],29));
	return 0;
}