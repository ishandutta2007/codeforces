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
int l[maxn+5],p[maxn+5];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,m) scanf("%d",&l[i]);
    int front=0,rear=0;
    ll sum=0;
    rep(i,1,m) sum+=l[i];
    if(sum<n) puts("-1");
    else
    {
        sum-=n;
        rep(i,1,m)   
        {
            ll x=min(sum,1ll*rear-front);
            sum-=x;
            p[i]=rear+1-x;
            front=p[i];
            rear=p[i]+l[i]-1;
        }
        int mark=1;
        rep(i,1,m) if(p[i]>n-l[i]+1) mark=0;
        if(p[m]+l[m]-1!=n) mark=0;
        if(mark==0) puts("-1");
        else
        {
            rep(i,1,m) printf("%d%c",p[i],"\n"[i==m]);
        }
    }
    return 0;
}