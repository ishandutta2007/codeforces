#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int t[200005][55]={0},d[200005][55]={0},f=0,j;
long n,k,i,a[100005],dp[100005][55],v[100005];
void apply(int p, int value)
{
  t[p][f] += value;
  if (p < n) d[p][f] += value;
}

void build(int p)
{
  while (p > 1) p >>= 1, t[p][f] = max(t[p<<1][f], t[p<<1|1][f]) + d[p][f];
}
int h=20;
void push(int p) {
  for (int s = h; s > 0; --s) {
    int i = p >> s;
    if (d[i][f] != 0) {
      apply(i<<1, d[i][f]);
      apply(i<<1|1, d[i][f]);
      d[i][f] = 0;
    }
  }
}

void inc(int l, int r, int value) {
    if(l>=r) return;
  l += n, r += n;
  int l0 = l, r0 = r;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1) apply(l++, value);
    if (r&1) apply(--r, value);
  }
  build(l0);
  build(r0 - 1);
}

int query(int l, int r) {
  l += n, r += n;
  push(l);
  push(r - 1);
  int res = -2e9;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, t[l++][f]);
    if (r&1) res = max(t[--r][f], res);
  }
  return res;
}

int main()
{
    io
    cin>>n>>k;
    ml visi;
    for(i=1;i<=n;++i)
    cin>>a[i];
    for(i=1;i<=n;++i)
    if(visi[a[i]]==0)
    visi[a[i]]=i,v[i]=1;
    else {v[i]=visi[a[i]]+1;visi[a[i]]=i;}
    n++;
    for(i=0;i<n;i++)
    for(j=0;j<=k;++j)
    if(i<j || j==0)
    t[i+n][j]=-1e9;
    t[n][0]=0;
    f=0;
    build(n);
    for(j=1;j<=k;++j)
    {
        for(i=1;i<n;++i)
        {
            inc(v[i]-1,i,1);
            t[i+n][j]=query(0,i);
        }
        f++;
        build(n);
    }
    cout<<t[2*n-1][k];
    return 0;
}