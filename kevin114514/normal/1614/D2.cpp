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
const int threshold=20000000;
int cnt[threshold+10];
ll dp[threshold+10];
int ccnt[threshold+10];
bool check[threshold+10];
vector<int> pr;
void init()
{
	memset(check, 0, sizeof(check));
	for (int i = 2; i < threshold; ++i)
	{
		if (!check[i])
		{
			pr.pb(i);
		}
		for (int j = 0; j < sz(pr); ++j)
		{
	    	if (i * pr[j] > threshold)
    		{
				break;
    		}
    		check[i*pr[j]] = 1;
    		if (i % pr[j] == 0)
    		{
				break;
    		}
  		}
	}
}
int main()
{
	init();
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}
	for(register int i=threshold;i>=1;i--)
	{
		int Cnt=0;
		if(i+i<=threshold)
			Cnt=ccnt[i+i];
		for(register int j=i;j<=threshold;j+=i+i)
			Cnt+=cnt[j];
		for(register int j=0;j<sz(pr)&&pr[j]*i<=threshold;j++)
			dp[i]=max(dp[pr[j]*i]-1ll*ccnt[pr[j]*i]*i,dp[i]);
		dp[i]+=1ll*Cnt*i;
		ccnt[i]=Cnt;
	}
	printf("%lld\n",dp[1]);
	return 0;
}