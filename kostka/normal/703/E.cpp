#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1007;
const int INF = 1e9 + 7;
long long a[MAXN];

vector <long long> PR;
vector <vector <int> > DDZ, AAA;
int p;

vector <int> factor(long long x)
{
  long long px = x;
  vector <int> W;
  for(int i=0; i<p; i++)
  {
    int ile = 0;
    while(x % PR[i] == 0LL)
    {
      ile++;
      x /= PR[i];
    }
    W.push_back(ile);
  }
  return W;
}

long long gcd(long long a, long long b)
{
  long long r = 1;
  for(int i=0; i<p; i++)
  {
    int e = min(DDZ[a][i], AAA[b][i]);
    while(e--)
      r *= PR[i];
  }
  return r;
}

vector <long long> primes(long long x)
{
  vector <long long> P;
  long long px = x;
  for(int i=2; 1LL*i*i <= px; i++)
  {
    if(x % i == 0)
      P.push_back(i);
    while(x % i == 0)
      x /= i;
  }
  if(x != 1)
    P.push_back(x);
  return P;
}

vector <long long> divisors(long long x)
{
  vector <long long> R;
  for(int i=1; 1LL*i*i <= x; i++)
  {
    if(x % i == 0)
    {
      R.push_back(i);
      R.push_back(x/i);
    }
  }
  sort(R.begin(), R.end());
  R.resize(unique(R.begin(), R.end())-R.begin());
  return R;
}

int dp[MAXN][10000]; //?
long long dps[MAXN][10000];
vector <int> R;
vector <long long> DZ;
map <long long, int> M;

void wroc(int n, int k)
{
  long long d = DZ[k] / gcd(k, n);
  if((dp[n][k] == dp[n-1][k]) and (dps[n][k] == dps[n-1][k]))
    return wroc(n-1, k);
  if((dp[n][k] == 1) and (a[n] % DZ[k] == 0LL))
  {
    R.push_back(n);
    return;
  }
  R.push_back(n);
  wroc(n-1, M[d]);
}

int main()
{
  int n;
  long long k;
  cin >> n >> k;
  PR = primes(k);
  p = (int)PR.size();
  vector <pair <long long, int> > N;
  for(int i=1; i<=n; i++)
  {
    long long x;
    cin >> x;
    N.emplace_back(x,i);
  }
  sort(N.begin(), N.end());
  AAA.push_back(vector<int>());
  for(int i=1; i<=n; i++)
  {
    a[i] = N[i-1].first;
    AAA.push_back(factor(a[i]));
  }
  DZ = divisors(k);
  int s = (int)DZ.size();
  for(int i=0; i<s; i++)
    DDZ.push_back(factor(DZ[i]));
  for(int i=0; i<s; i++)
    M[DZ[i]] = i;
  for(int i=0; i<=n; i++)
    for(int j=0; j<s; j++)
    {
      if(a[i] % DZ[j] == 0)
      {
        dp[i][j] = 1;
        dps[i][j] = a[i];
      }
      else
      {
        dp[i][j] = INF;
        dps[i][j] = 1e18;
      }
    }
  for(int i=2; i<=n; i++)
    for(int j=0; j<s; j++)
    {
      if((dp[i][j] > dp[i-1][j]) or (dp[i][j] == dp[i-1][j] and dps[i][j] > dps[i-1][j]))
      {
        dp[i][j] = dp[i-1][j];
        dps[i][j] = dps[i-1][j];
      }
      int ttt = M[DZ[j] / gcd(j,i)];
      if((dp[i][j] > 1 + dp[i-1][ttt]) or (dp[i][j] == 1 + dp[i-1][ttt]
        and dps[i][j] > dps[i][ttt] + a[i]))
      {
        dp[i][j] = 1 + dp[i-1][ttt];
        dps[i][j] = dps[i-1][ttt] + a[i];
      }
    }
  int res = dp[n][M[k]];
  if(res == INF)
    res = -1;
  else
    wroc(n, M[k]);
  cout << res << "\n";
  sort(R.begin(), R.end());
  for(auto ele : R)
    cout << N[ele-1].second << " ";
  cout << "\n";
}