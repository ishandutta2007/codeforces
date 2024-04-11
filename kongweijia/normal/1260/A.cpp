#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)

#define pb push_back
#define mp make_pair
#define xx first
#define yy second
#define INF 0x3f3f3f3f

using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int maxn=100000;
//head


int main()
{
    int CAS; scanf("%d",&CAS);
    while(CAS--)
    {
        int n,s; scanf("%d%d",&n,&s);
        int c=s/n,m=s%n;
        ll ans=1ll*(c+1)*(c+1)*m+1ll*c*c*(n-m);
        printf("%I64d\n",ans);
    }
	return 0;
}