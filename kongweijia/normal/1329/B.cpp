#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)

#define infty 0x3f3f3f3f

#define pb push_back
#define mp make_pair
#define xx first
#define yy second

using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;

//head
const int maxn=100000;
int mod;

int dp[32][32];

void add(int &x,int y) {x=x+y<mod?x+y:x+y-mod;}

int main()
{
    int CAS; scanf("%d",&CAS);
    while(CAS--)
    {
        int d; scanf("%d%d",&d,&mod);
        dp[0][0]=1;
        int ans=0;
        rep(i,1,30) rep(j,i,30)
        {
            dp[i][j]=0;
            int way=min(d,(1<<j)-1)-(1<<(j-1))+1;
            if(way<=0) continue;
            rep(k,0,j-1)
            {
                add(dp[i][j],1ll*dp[i-1][k]*way%mod);
            }
            add(ans,dp[i][j]);
        }
        printf("%d\n",ans);
    }
    return 0;
}