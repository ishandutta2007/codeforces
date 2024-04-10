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
int dp[88][88][88][2];
vector<int> pos[3];
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='V')
			pos[0].pb(i);
		else if(s[i]=='K')
			pos[1].pb(i);
		else	pos[2].pb(i);
	}
	memset(dp,inf,sizeof(dp));
	dp[0][0][0][0]=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<=i&&j<=sz(pos[0]);j++)
			for(int k=0;k+j<=i&&k<=sz(pos[1]);k++) if(i-j-k<=sz(pos[2]))
				for(int flag=0;flag<2;flag++) if(dp[i][j][k][flag]<inf)
				{
//					cout<<i<<" "<<j<<" "<<k<<" "<<flag<<" "<<dp[i][j][k][flag]<<endl;
					int siz[3]={j,k,i-j-k};
					for(int l=0;l<3;l++) if(!flag||l!=1) if(siz[l]<sz(pos[l]))
					{
						int x=dp[i][j][k][flag]+pos[l][siz[l]]-i;
						for(int m=0;m<3;m++) if(m!=l)
							x+=max(0,(int)(pos[m].begin()+siz[m]-upper_bound(ALL(pos[m]),pos[l][siz[l]])));
//						cout<<" -> "<<l<<" "<<x<<endl;
						dp[i+1][j+(l==0)][k+(l==1)][(l==0)]=min(dp[i+1][j+(l==0)][k+(l==1)][(l==0)],x);
					}
				}
	cout<<min(dp[n][sz(pos[0])][sz(pos[1])][0],dp[n][sz(pos[0])][sz(pos[1])][1])<<endl;
	return 0;
}