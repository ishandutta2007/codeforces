#include<bits/stdc++.h>
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
void die(string S){puts(S.c_str());exit(0);}
vector<int> res;
ll ans;
int n,m;
int room[200200];
void O()
{
	cout<<ans<<endl;
	for(int i=0;i<sz(res);i++)
		cout<<res[i]<<" ";
	exit(0);
}
inline int find_nearest(int x)
{
	int p=lower_bound(room,room+n,x)-room;
	if(!p)
		return 0;
	if(p==n)
		return n-1;
	if(abs(x-room[p-1])>abs(x-room[p]))
		return p;
	else	return p-1;
}
inline void upd(int x,int dist)
{
	ans+=dist;
	res.pb(x);
	m--;
	if(!m)
		O();
	return ;
}
int main()
{
//	freopen("p6.in","r",stdin);
//	freopen("p6.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>room[i];
	sort(room,room+n);
	vector<int> v,v1;
	for(int i=0;i<n;i++)
		v.pb(i);
	for(int dist=1;;dist++)
	{
		for(int j=0;j<sz(v);j++)
		{
			int i=v[j];
			bool ok=0;
			if(find_nearest(room[i]-dist)==i)
			{
				ok=1;
				upd(room[i]-dist,dist);
			}
			if(find_nearest(room[i]+dist)==i)
			{
				upd(room[i]+dist,dist);
				ok=1;
			}
			if(ok)
				v1.pb(i);
		}
		v=v1;
		v1.clear();
	}
	return 0;
}