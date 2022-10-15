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
int x[100100];
int cnt[2];
int n;
int calc(int st)
{
	priority_queue<int,vector<int>,greater<int> > q[2];
	for(int i=0;i<n;i++)
		q[x[i]].push(i);
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		if(q[st].top()==i)
		{
			q[st].pop();
		}
		else
		{
			q[st^1].pop();
			ans+=q[st].top()-i;
			q[st^1].push(q[st].top());
			q[st].pop();
		}
		st^=1;
	}
	return ans;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cnt[0]=cnt[1]=0;
		for(int i=0;i<n;i++)
		{
			cin>>x[i];
			x[i]%=2;
			cnt[x[i]]++;
		}
		if(abs(cnt[0]-cnt[1])>1)
			puts("-1");
		else if(cnt[0]>cnt[1])
		{
			cout<<calc(0)<<endl;
		}
		else if(cnt[0]<cnt[1])
		{
			cout<<calc(1)<<endl;
		}
		else	cout<<min(calc(0),calc(1))<<endl;
	}
	return 0;
}