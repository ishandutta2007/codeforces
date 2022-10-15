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
map<ll,int> Mp;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ll sum=0;
		Mp.clear();
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			Mp[x]++;
			sum+=x;
		}
		priority_queue<ll> pq;
		pq.push(sum);
		while(!pq.empty()&&sz(pq)<=n)
		{
			ll x=pq.top();
			pq.pop();
			if(Mp[x])
			{
				Mp[x]--;
				n--;
				continue;
			}
			if(x==1)
				goto fail;
			pq.push(x/2);
			pq.push((x+1)/2);
		}
		if(pq.empty())
		{
			puts("YES");
			continue;
		}
		fail:;
		puts("NO");
	}
	return 0;
}