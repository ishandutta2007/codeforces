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
//int ans[200200];
int x[200200],b[200200];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>b[i];
		for(int i=1;i<=n;i++)
		{
			int p;
			cin>>p;
			x[p]=i;
		}
		int mn=1e9;
		for(int i=1;i<=n;i++)
			mn=min(mn,x[i]-x[b[i]]);
		if(mn>=0)
			for(int i=1;i<=n;i++)
				cout<<x[i]-x[b[i]]<<" ";
		else	cout<<-1;
		puts("");
	}
	return 0;
}