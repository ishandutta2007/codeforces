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
int a[200100];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		ll sum=0;
		priority_queue<int,vector<int>,greater<int> > pq;
		for(int i=0;i<n;i++)
			pq.push(a[i]);
		ll ans=-1ll*inf*inf;
		while(!pq.empty())
		{
			int x=pq.top();
			pq.pop();
			ans=max(ans,x-sum);
			sum+=(x-sum);
		}
		cout<<ans<<endl;
	}
	return 0;
}