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
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,H;
		cin>>n>>H;
		vector<int> v;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			v.pb(x);
		}
		rsrt(v);
		int sum=v[0]+v[1];
		int ans=H/sum*2;
		H%=sum;
		if(!H)
			cout<<ans<<endl;
		else if(H<=v[0])
			cout<<ans+1<<endl;
		else	cout<<ans+2<<endl;
	}
	return 0;
}