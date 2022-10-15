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
		int n;
		cin>>n;
		vector<pii> v;
		priority_queue<pii> pq;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			if(x)
				pq.push(mp(x,i));
		}
		while(true)
		{
			if(pq.empty())
				break;
			pii x=pq.top();
			pq.pop();
			if(pq.empty())
				break;
			pii y=pq.top();
			pq.pop();
			v.pb(mp(x.second,y.second));
			x.first--;
			y.first--;
			if(x.first)
				pq.push(x);
			if(y.first)
				pq.push(y);
		}
		cout<<sz(v)<<endl;
		for(int i=0;i<sz(v);i++)
			cout<<v[i].first<<" "<<v[i].second<<endl;
	}
	return 0;
}