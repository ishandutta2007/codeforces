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
bool used[100100];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			used[i]=0;
		vector<int> v;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			if(x<=n&&!used[x])
				used[x]=1;
			else v.pb(x);
		}
		srt(v);
		bool flg=0;
		int cnt=0;
		int p=0;
		for(int i=0;i<n;i++) if(!used[i+1])
		{
			if(v[p]!=i+1)
			{
				cnt++;
				if(v[p]<i+1||(v[p])%(v[p]-i-1)!=i+1)
					flg=1;
			}
			p++;
		}
		if(flg)
			puts("-1");
		else	cout<<cnt<<endl;
	}
	return 0;
}