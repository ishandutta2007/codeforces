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
        ll a,b,k; scanf("%I64d%I64d%I64d",&a,&b,&k);
        ll g=__gcd(a,b);
        a/=g;
        b/=g;
        if(a==b) puts("OBEY");
        else
        {
            if(a>b) swap(a,b);
            ll mx=max((b-1)/a,(b-2)/a+1);
            puts(mx<k?"OBEY":"REBEL");
        }
    }
	return 0;
}