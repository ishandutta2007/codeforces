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

const int maxn=300000;
//head
int a[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    int p=0;
    rep(i,1,n) if(a[i]==-1) p=i;

    int t=0,T=0;
    while((1<<T)<n) T++;
    rep(i,1,18) if(p>=(1<<i)) t=i;
    int now=n;
    priority_queue<int,VI,greater<int> > q;
    ll ans=0;
    per(i,t+1,T)
    {
        while(now>=(1<<i))
        {
            if(a[now]!=-1) q.push(a[now]);
            now--;
        }
        ans+=q.top();q.pop();
    }
    printf("%I64d\n",ans);
	return 0;
}