#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
void die(string S){puts(S.c_str());exit(0);}
ll a[200200],b[200200];
ll Da[200200],Db[200200];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		ll m;
		scanf("%d%lld",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%lld%lld",a+i,b+i);
		ll sum=0;
		ll tot=n*m;
		ll delta=0;
		ll realdelta=0;
		for(int i=0;i<n;i++)
		{
			Da[i]=max(0ll,m-b[i]);
			Db[i]=max(0ll,m-a[i]);
			a[i]-=Da[i];
			sum+=min(a[i],m-Da[i]);
			tot-=Da[i];
			realdelta+=a[i]-b[i];
		}
		ll choose;
		if(sum<=(tot+realdelta)/2)
			choose=sum;
		else	choose=(tot+realdelta)/2;
		choose=max(choose,0ll);
		ll ans=0;
		vector<pii> v;
		for(int i=0;i<n;i++)
		{
			int x=min(choose,min(a[i],m-Da[i]))+Da[i];
			ans+=((a[i]+Da[i]-x)-(b[i]-m+x));
			v.pb(mp(x,m-x));
			choose-=x-Da[i];
		}
		cout<<abs(ans)<<endl;
		for(int i=0;i<n;i++)
			cout<<v[i].first<<" "<<v[i].second<<endl;
	}
	return 0;
}