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
int pos[200200];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> a,b;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			a.pb(x);
			pos[x]=i;
		}
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			b.pb(x);
			pos[x]=i;
		}
		int ans=1e9;
		int mn=1e9;
		for(int i=2*n;i;i--)
		{
			if(i%2==0)
				mn=min(mn,pos[i]);
			else	ans=min(ans,mn+pos[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}