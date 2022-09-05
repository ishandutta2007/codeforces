#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int c,hr,hb,wr,wb;ll ans;
void chmax(const ll &x)
{
	if(x>ans)ans=x;
}
void check(int c,int hr,int hb,int wr,int wb)
{
	int mi=min(c/wr,100000);
	for(int i=0;i<=mi;++i)
	 chmax(ll(i)*hr+ll(hb)*( (c-i*wr)/wb ));
}

int main()
{
//	freopen("1.in","r",stdin);
	cin>>c>>hr>>hb>>wr>>wb;
	check(c,hr,hb,wr,wb);
	check(c,hb,hr,wb,wr);
	cout<<ans;
}