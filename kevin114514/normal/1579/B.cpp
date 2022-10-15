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
int x[55],y[55];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			y[i]=x[i];
		}
		sort(y+1,y+n+1);
		vector<pair<pii,int> > v;
		for(int i=1;i<n;i++)
		{
			int pos=0;
			for(int j=i;j<=n;j++)
				if(y[i]==x[j])
				{
					pos=j;
					break;
				}
			if(i==pos)
				continue;
			v.pb(mp(mp(i,pos),pos-i));
			for(int j=pos;j>i;j--)
				x[j]=x[j-1];
			x[i]=y[i];
		}
		cout<<sz(v)<<endl;
		for(int i=0;i<sz(v);i++)
			cout<<v[i].first.first<<" "<<v[i].first.second<<" "<<v[i].second<<endl;
	}
	return 0;
}