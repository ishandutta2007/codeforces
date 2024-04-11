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

const int ff[4]={0,2,3,1};

int main()
{
    int cas; scanf("%d",&cas);
    while(cas--)
    {
        ll n; scanf("%lld",&n);
        ll g=(n-1)/3+1;
        int id=(n-1)%3+1;
        int B=0;
        ll N=1;
        while(g>N)
        {
            g-=N;
            N*=4;
            B++;
        }
        g--;
        ll x=N+g;
        ll y=1ll<<(B*2+1);
        rep(i,0,B-1)
        {
            ll t=(x>>(i*2))&3;
            ll tt=ff[t];
            y+=tt<<(i*2);
        }
        ll z=x^y;
        if(id==1) printf("%lld\n",x);
        if(id==2) printf("%lld\n",y);
        if(id==3) printf("%lld\n",z);
    }
    return 0;
}