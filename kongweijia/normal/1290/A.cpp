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

const int maxn=3500;
//head

int a[maxn+5];
int b[maxn+5];

int main()
{
	int cas; scanf("%d",&cas);
    while(cas--)
    {
        int n,m,k; scanf("%d%d%d",&n,&m,&k);
        k=min(k,m-1);
        rep(i,1,n) scanf("%d",&a[i]);
        rep(i,1,m) b[i]=max(a[i],a[n-m+i]);
        int ans=0;
        rep(i,1,k+1) 
        {
            int mn=INF;
            rep(j,1,m-k) mn=min(mn,b[i+j-1]);
            ans=max(ans,mn);
        }
        printf("%d\n",ans);
    }
    return 0;
}