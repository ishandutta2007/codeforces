#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int SQRT = 547,MOD=1e9+9;
const int maxn = 3e5+100;
int n,q,fib[maxn],fib_sum[maxn],b[maxn],a[maxn],sum[maxn];
vector<pii>query;

void relax()
{
  memset(b,0,sizeof b);
  for(int i=0;i<query.size();i++)
    {
      b[query[i].X] = (b[query[i].X] + fib[0]) % MOD;
      // b[query[i].X+1] = (b[query[i].X+1] + f[1]) %MOD;
      b[query[i].Y+1] = (b[query[i].Y+1] - fib[query[i].Y+1-query[i].X] + MOD)%MOD;
      b[query[i].Y+2] = (b[query[i].Y+2] - fib[query[i].Y-query[i].X] + MOD)%MOD;
    }
  query.clear();
  for(int i=1;i<=n;i++)
    {
      b[i]=((ll)b[i]+b[i-1]+b[i-2])%MOD;
      a[i]=(a[i]+b[i])%MOD;
      sum[i]=(sum[i-1]+a[i])%MOD;
    }
}

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>n>>q;

  fib[0]=fib[1]=1;
  fib_sum[0]=1,fib_sum[1]=2;
  for(int i=2;i<=n;i++)
    fib[i]=(fib[i-1]+fib[i-2])%MOD,fib_sum[i]=(fib_sum[i-1]+fib[i])%MOD;

  for(int i=1;i<=n;i++)
    cin>>a[i],sum[i]=(sum[i-1]+a[i])%MOD;

  while(q--)
    {
      int type,l,r;
      cin>>type>>l>>r;
      if(type==1)
	{
	  query.push_back(pii(l,r));
	  if(query.size()>SQRT)
	    relax();
	}
      else
	{
	  int ans = (sum[r]-sum[l-1]+MOD)%MOD;
	  for(int i=0;i<query.size();i++)
	    {
	      int x = max(query[i].X,l), y=min(query[i].Y,r);
	      if(x<=y)
		ans = ((ll)ans + fib_sum[y-query[i].X] - (x-1-query[i].X>=0 ? fib_sum[x-1 - query[i].X] : 0) + MOD) % MOD;
	    }
	  cout<<ans<<'\n';
	}
    }
}