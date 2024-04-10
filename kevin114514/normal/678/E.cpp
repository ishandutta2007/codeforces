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
double dp[(1<<18)][18];
double win[18][18];
int main()
{
	dp[1][0]=1.0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>win[i][j];
	for(int i=1;i<(1<<n);i++) if(__builtin_popcount(i)>1)
		for(int j=0;j<n;j++) if(i>>j&1)
			for(int k=0;k<n;k++) if(i>>k&1) if(j!=k)
				dp[i][j]=max(dp[i][j],dp[i^(1<<j)][k]*win[k][j]+dp[i^(1<<k)][j]*win[j][k]);
	printf("%.12lf\n",*max_element(dp[(1<<n)-1],dp[(1<<n)-1]+n));
	return 0;
}