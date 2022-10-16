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
//int a[1001000],b[1001000];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	vector<pii> v;
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v.pb(mp(a,-1));
		v.pb(mp(b,1));
	}
	srt(v);
	int cnt=0;
	vector<int> u;
	for(int i=0;i<sz(v);i++)
	{
		if(v[i].second==-1)
		{
			cnt++;
			if(cnt==k)
				u.pb(v[i].first);
		}
		else
		{
			if(cnt==k)
				u.pb(v[i].first);
			cnt--;
		}
	}
	printf("%d\n",sz(u)/2);
	for(int i=0;i<sz(u);i+=2)
		printf("%d %d\n",u[i],u[i+1]);
	return 0;
}