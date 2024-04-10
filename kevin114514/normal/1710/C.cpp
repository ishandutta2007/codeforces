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
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
void die(string S){puts(S.c_str());exit(0);}
char buff[200200];
ll dp[200200][8][8];
const ll mod=998244353;
int main()
{
	int n;
	scanf("%s",buff);
	n=strlen(buff);
	for(int i=0;i<n;i++)
		buff[i]-='0';
	dp[0][7][0]=1;
	for(int i=0;i<n;i++)
		for(int m1=0;m1<8;m1++)
			for(int m2=0;m2<8;m2++)
				for(int m3=0;m3<8;m3++)
				{
					bool f=1;
					for(int j=0;j<3;j++)
						if(((m1&m3)>>j&1)&&buff[i]==0)
							f=0;
					if(!f)
						continue;
					int nm1=0;
					for(int j=0;j<3;j++)
						if((m1>>j&1)&&((m3>>j&1)==buff[i]))
							nm1|=(1<<j);
					int nm2=m2;
					if(((m3&1)^(m3>>1&1))&&((m3>>1&1)^(m3>>2&1)))
						nm2|=1;
					if(((m3&1)^(m3>>2&1))&&((m3>>1&1)^(m3>>2&1)))
						nm2|=2;
					if(((m3&1)^(m3>>2&1))&&((m3&1)^(m3>>1&1)))
						nm2|=4;
//					cout<<m1<<" "<<m2<<" "<<m3<<" "<<nm1<<" "<<nm2<<endl;
					dp[i+1][nm1][nm2]=(dp[i+1][nm1][nm2]+dp[i][m1][m2])%mod;
				}
	ll ans=0;
	for(int i=0;i<8;i++)
		ans=(ans+dp[n][i][7])%mod;
	cout<<ans<<endl;
	return 0;
}