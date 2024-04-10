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
int ans[1001000];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<pii> v;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			v.pb(mp(x,i));
		}
		rsrt(v);
		ll aans=0;
		for(int i=0;i<n;i++)
		{
			aans+=1ll*((i+2)/2)*v[i].first;
			ans[v[i].second]=(i+2)/2;
			if(i%2)
				ans[v[i].second]*=-1;
		}
		cout<<aans*2<<endl;
		cout<<0<<" ";
		for(int i=0;i<n;i++)
			cout<<ans[i]<<" ";
		puts("");
	}
	return 0;
}