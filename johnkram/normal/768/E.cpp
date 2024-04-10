#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pli pair<ll,int>
#define mp make_pair
map<pli,int> m;
int n,i,a[61],ans;
int work(ll x,int y)
{
	if(!y)return 0;
	if(m.count(mp(x,y)))return m[mp(x,y)];
	bool b[61];
	int i;
	for(i=0;i<=60;i++)b[i]=0;
	for(i=1;i<=y;i++)if(!(x>>i&1))b[work(x|1<<i,y-i)]=1;
	for(i=0;i<=60;i++)if(!b[i])break;
	return m[mp(x,y)]=i;
}
int main()
{
	for(i=1;i<=60;i++)
	{
		a[i]=work(0,i);
		m.clear();
	}
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&i);
		ans^=a[i];
	}
	puts(ans?"NO":"YES");
	return 0;
}