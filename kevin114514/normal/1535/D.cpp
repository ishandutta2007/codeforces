#include<bits/stdc++.h>
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
void die(string S){puts(S.c_str());exit(0);}
int dp[(1<<20)];
int op[(1<<20)];
void upd(int x)
{
	if(!x)
		return ;
	if(op[x]==1)
		dp[x]=dp[x+x];
	if(op[x]==0)
		dp[x]=dp[x+x+1];
	if(op[x]==2)
		dp[x]=dp[x+x]+dp[x+x+1];
	upd(x/2);
	return ;
}
int main()
{
	int k;
	cin>>k;
	int n=(1<<k)-1;
	string s;
	cin>>s;
	reverse(ALL(s));
	for(int i=0;i<n;i++)
		if(s[i]=='?')
			op[i+1]=2;
		else	op[i+1]=s[i]-'0';
	for(int i=n+1;i<=n+n+1;i++)
		dp[i]=1;
	for(int i=1;i<=n;i++)
		upd(i);
	int q;
	cin>>q;
	while(q--)
	{
		int x;
		string t;
		cin>>x>>t;
		x=n+1-x;
		int tmp=op[x];
		if(t[0]=='?')
			op[x]=2;
		else	op[x]=t[0]-'0';
		upd(x);
		cout<<dp[1]<<endl;
//		op[x]=tmp;
//		upd(x);
	}
	return 0;
}