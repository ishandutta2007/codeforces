#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=2e5+5;
int n,a[N];
map<int,int>ap;
int last[30],q[30];
bool xiao(int x,int y)
{
	return last[x]<last[y];
}

int main()
{
	//freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	rep(i,1,n)scanf("%d",a+i);
	ll ans=0;
	rep(j,0,29)q[j]=j;
	per(i,n,1)
	{
		rep(j,0,29)
		if((a[i]>>j)&1)last[j]=i;
		if(ap.count(a[i]))ap.erase(a[i]);
		ap[a[i]]=i;
		
		sort(q,q+30,xiao);
		int h=0;
		while(h<30&&last[q[h]]<=i)++h;
		int x=a[i];
		int nr=i;
		for(;h<30;++h)
		{
			if(ap.count(x)==0) 
			{
				ans+=last[q[h]]-nr;
				nr=last[q[h]];
			}
			else
			{
				ans+=min(last[q[h]],ap[x])-nr;
				nr=last[q[h]];
			}
			x+=1<<q[h];
		}
		if(ap.count(x)==0) ans+=n-nr+1;
		else ans+=ap[x]-nr;
	}
	cout<<ans;
}