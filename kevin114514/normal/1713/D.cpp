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
int query(int a,int b)
{
	cout<<"? "<<a<<" "<<b<<endl;
	fflush(stdout);
	int x;
	cin>>x;
	return x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> vec;
		for(int i=1;i<=(1<<n);i++)
			vec.pb(i);
		while(sz(vec)>1)
		{
			vector<int> nvec;
			if(sz(vec)==2)
			{
				if(query(vec[0],vec[1])==1)
				{
					cout<<"! "<<vec[0]<<endl;
					fflush(stdout);
					break;
				}
				else
				{
					cout<<"! "<<vec[1]<<endl;
					fflush(stdout);
					break;
				}
			}
			for(int i=0;i<sz(vec);i+=4)
			{
				int x=query(vec[i],vec[i+2]);
				if(x==0)
				{
					if(query(vec[i+1],vec[i+3])==1)
						nvec.pb(vec[i+1]);
					else	nvec.pb(vec[i+3]);
				}
				else if(x==1)
				{
					if(query(vec[i],vec[i+3])==1)
						nvec.pb(vec[i]);
					else	nvec.pb(vec[i+3]);
				}
				else
				{
					if(query(vec[i+1],vec[i+2])==1)
						nvec.pb(vec[i+1]);
					else	nvec.pb(vec[i+2]);
				}
			}
			vec=nvec;
		}
		if(sz(vec)==2)
			continue;
		cout<<"! "<<vec[0]<<endl;
		fflush(stdout);
	}
	return 0;
}