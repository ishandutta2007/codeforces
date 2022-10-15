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
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
int cnt[200200],a[200200];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<=n;i++)
			cnt[i]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			cnt[a[i]]++;
		}
		int mex=0;
		while(cnt[mex]) mex++;
		vector<int> v;
		int p=1;
		while(p<=n)
		{
			set<int> s;
//			bool flag=0;
			int nmex=mex;
			while(p<=n&&sz(s)<mex)
			{
				if(a[p]<mex)
					s.insert(a[p]);
				cnt[a[p]]--;
				if(!cnt[a[p]])
					nmex=min(nmex,a[p]);
				p++;
			}
			if(p<=n&&!mex)
			{
				cnt[a[p]]--;
				if(!cnt[a[p]])
					nmex=min(nmex,a[p]);
				p++;
			}
//			cout<<p<<endl;
			v.pb(mex);
			mex=nmex;
		}
		cout<<sz(v)<<endl;
		for(auto x:v)
			cout<<x<<" ";
		puts("");
	}
	return 0;
}