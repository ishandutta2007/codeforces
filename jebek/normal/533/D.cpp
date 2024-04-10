#include <iostream>
#include<algorithm>
#include<map>
#include<vector>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
map<ll,ll>MIN;
const ll MAXN=200000,maxn=2100000000;
ll n,a[MAXN],x[MAXN],x1,b;
bool mark[MAXN],mark1[MAXN];
ll ans,dp[MAXN],dp1[MAXN];
vector<pii>v;

void add(ll x,ll val)
{
    x=max(x,(ll)1);
    while(x<=maxn)
    {
        if(MIN[x]==0)
            MIN[x]=val;
        else
            MIN[x]=min(MIN[x],val);
        x+=x&(-x);
    }
}

ll f(ll x)
{
    ll ans1=1000000000000;
    while(x>0)
    {
        if(MIN[x]>0)
            ans1=min(ans1,(ll)MIN[x]);
        x-=x&(-x);
    }
    return ans1;
}

int main()
{
    cin>>n;
    for(int i=0;i<=n+1;i++)
      {
        cin>>x[i];
	x[i]*=2;
      }
    for(int i=1;i<=n;i++)
      {
        cin>>a[i];
	a[i]*=2;
      }
    ans=x[n+1]/2;
    x1=x[n+1];
    for(int k=n;k>0;k--)
    {
      while(v.size() && (v.back().X-x[k])>v.back().Y*2)
	v.pop_back();
      if(v.size()==0)
        {
            if((x[n+1]-x[k])>=a[k]*2)
                continue;
            mark[k]=true;
            dp[k]=a[k]-(x[n+1]-x[k])/2;
	    v.push_back(pii(x[k],dp[k]));
	    ans=min(ans,x[k]/2);
	    if(x[k]<=dp[k]*2)
	      ans=0;
            continue;
        }
      x1=v.back().X,b=v.back().Y;
      if((x1-x[k])>=a[k]*2)
	continue;
      mark[k]=true;
      dp[k]=a[k]-(x1-x[k])/2;
      ans=min(ans,x[k]/2);
      if(x[k]<=dp[k]*2)
	ans=0;
      b=dp[k];
      x1=x[k];
      v.push_back(pii(x1,b));
    }
    x1=0,b=0;
    v.clear();
    for(int k=1;k<n+1;k++)
      {
	while(v.size() && x[k]-v.back().X>b*2)
	  v.pop_back();
        if(v.size()==0)
	  {
            if(x[k]>=a[k]*2)
	      continue;
            mark1[k]=true;
            dp1[k]=a[k]-x[k]/2;
            x1=x[k];
            b=dp1[k];
	    v.push_back(pii(x1,b));
	    if((x[n+1]-x[k])<=dp1[k]*2)
	      ans=0;
	    ans=min(ans,(x[n+1]-x[k])/2);
            continue;
	  }
	x1=v.back().X,b=v.back().Y;
        if((x[k]-x1)>=a[k]*2)
	  continue;
        mark1[k]=true;
        dp1[k]=a[k]-(x[k]-x1)/2;
        if((x[n+1]-x[k])<=dp1[k]*2)
	  ans=0;
        ans=min(ans,(x[n+1]-x[k])/2);
        b=dp1[k];
        x1=x[k];
	v.push_back(pii(x1,b));
      }
    for(int i=n-1;i>0;i--)
      {
        if(mark[i+1])
	  add(x[i+1]-2*dp[i+1],x[i+1]);
        if(mark1[i])
	  {
            ll MAX=f(x[i]+2*dp1[i]);
            ans=min(ans,(MAX-x[i])/2);
        }
    }
    ans=max(ans,(ll)0);
    cout<<(double)ans/2.0<<endl;
}