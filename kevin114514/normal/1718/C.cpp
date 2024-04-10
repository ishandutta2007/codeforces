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
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
#define longer __int128_t
void die(string S){puts(S.c_str());exit(0);}
int a[200200];
vector<ll> sum[162];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t;
	cin>>t;
	while(t--)
	{
		for(int i=0;i<162;i++)
			sum[i].clear();
		int n,q;
		cin>>n>>q;
//		n=16;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		vector<int> vect;
		for(int i=1;i*i<=n;i++)
			if(n%i==0)
			{
				vect.pb(i);
				if(i*i!=n&&i>1)
					vect.pb(n/i);
			}
		vector<int> vec;
//		for(auto x:vect)
//			cout<<x<<" ";
		for(int i=0;i<sz(vect);i++)
		{
			int x=vect[i];
			bool f=1;
//			cout<<x<<endl;
			for(int j=0;j<sz(vect);j++)
			{
				int y=vect[j];
//				cout<<"  "<<y<<endl;
				if(y%x==0&&y>x)
				{
					f=0;
					break;
				}
			}
			if(f)
				vec.pb(x);
		}
		multiset<ll> st;
		for(int i=0;i<sz(vec);i++)
			for(int j=1;j<=vec[i];j++)
			{
				ll s=0;
				for(int k=j;k<=n;k+=vec[i])
					s+=1ll*(vec[i])*a[k];
				sum[i].pb(s);
				st.insert(-s);
			}
		cout<<-(*(st.begin()))<<'\n';
		while(q--)
		{
			int p,x;
			cin>>p>>x;
			int delta=x-a[p];
			a[p]=x;
			for(int i=0;i<sz(vec);i++)
			{
				int j=(p%vec[i]-1+vec[i])%vec[i];
				st.erase(st.lower_bound(-sum[i][j]));
				sum[i][j]+=1ll*vec[i]*delta;
				st.insert(-sum[i][j]);
//				pq.push(mp(sum[i][j],mp(i,j)));
			}
//			while(pq.top().first!=sum[pq.top().second.first][pq.top().second.second])
//				pq.pop();
//			cout<<pq.top().first<<'\n';
			cout<<-(*(st.begin()))<<'\n';
		}
	}
	return 0;
}