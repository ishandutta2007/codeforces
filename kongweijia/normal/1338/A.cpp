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
const int maxn = 100000;

int a[maxn+5];

int main()
{
    int CAS; scanf("%d",&CAS);
    while(CAS--)
    {
        int n; scanf("%d",&n);
        rep(i,1,n) scanf("%d",&a[i]);
        int now=a[1],mx=0;
        rep(i,2,n)
        {
            now=max(now,a[i]);
            mx=max(mx,now-a[i]);
        }
        int t=0;
        while((1ll<<t)-1<mx) t++;
        printf("%d\n",t);
    }
    return 0;
}