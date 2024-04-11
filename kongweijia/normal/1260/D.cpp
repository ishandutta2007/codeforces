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

const int maxn=200000;
//head

int s[maxn+5];
struct trap
{
    int l,r,d;
}t[maxn+5];
bool cmp(trap a,trap b) {return a.l<b.l;}

int m,n,k,T;

bool check(int x)
{
    int now=0,ti=0;
    rep(i,1,k) if(t[i].d>x)
    {
        if(t[i].l<=now)
        {
            ti+=max(0,t[i].r-now);
            now=max(now,t[i].r);
        }
        else
        {
            ti+=t[i].r-t[i].l+1;
            now=t[i].r;
        }
    }
    return ti*2+n+1<=T;
}

int lb(int l,int r)
{
    r++;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(mid)==1) r=mid;
        else l=mid+1;
    }
    return l;
}


int main()
{
    scanf("%d%d%d%d",&m,&n,&k,&T);
    rep(i,1,m) {int x; scanf("%d",&x); s[x]++;}
    rep(i,1,maxn) s[i]+=s[i-1];
    rep(i,1,k) scanf("%d%d%d",&t[i].l,&t[i].r,&t[i].d);
    sort(t+1,t+k+1,cmp);
    int ans=lb(1,maxn);
    printf("%d\n",m-s[ans-1]);
	return 0;
}