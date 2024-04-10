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
const int threshold=5000000;
int cnt[threshold+10];
ll dp[threshold+10];
int ccnt[threshold+10];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}
	for(int i=threshold;i>=1;i--)
	{
		int Cnt=0;
		for(register int j=i;j<=threshold;j+=i)
			Cnt+=cnt[j];
		for(register int j=i+i;j<=threshold;j+=i)
			dp[i]=max(dp[j]-1ll*ccnt[j]*i,dp[i]);
		dp[i]+=1ll*Cnt*i;
		ccnt[i]=Cnt;
	}
	printf("%lld\n",dp[1]);
	return 0;
}