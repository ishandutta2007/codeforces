#include "bits/stdc++.h"

using namespace std;

const int MAXN = 5007;
long long pref[MAXN], revpref[MAXN];
long long pott[MAXN];
const int pri = 17;
const int mod = 1234567891; //aka liczba Hazego

string s;

void hashe(int st)
{
  long long a = 1;
  long long w = 0;
  for(int i=st; i<(int)s.size(); i+=2)
  {
    w += s[i]*a;
    w %= mod;
    a *= pri;
    a %= mod;
    pref[i] = w;
  }
}

void revhashe(int st)
{
  long long a = 1;
  long long w = 0;
  for(int i=st; i>=0; i-=2)
  {
    w += s[i]*a;
    w %= mod;
    a *= pri;
    a %= mod;
    revpref[i] = w;
  }
}

int pottgen()
{
  pott[0] = 1;
  for(int i=1; i<=5000; i++)
  {
    pott[i] = pott[i-1] * pri;
    pott[i] %= mod;
  }
}

int pow(int a, int b, int c)
{
  if(b==0)
    return 1%c;
  int e = pow(a,b/2,c);
  long long f = (1LL*e*e)%c;
  if(b%2)
    return (f*a)%c;
  else
    return f;
}

int odwmod(int a, int c)
{
  return pow(a,c-2,c);
}

bool checked[MAXN][MAXN];
bool what[MAXN][MAXN];

bool check(int a, int b)
{
  if(checked[a][b] == true)
    return what[a][b];
  checked[a][b] = true;
  int pom1 = a/2;
  int pom2 = ((int)s.size()-b-1)/2;
  int mpom = max(pom1,pom2);
  long long hash1;
  int xb = (a+b)/2;
  if((xb-a) % 2 == 0)
    hash1 = pref[xb];
  else
    hash1 = pref[xb-1];
  if(a>1)
  {
    hash1 -= pref[a-2];
    hash1 += mod;
    hash1 %= mod;
  }
  hash1 = (1LL*hash1*pott[mpom-pom1])%mod;
  long long hash2;
  int xa = (a+b+1)/2;
  if((b-xa) % 2 == 0)
    hash2 = revpref[xa];
  else
    hash2 = revpref[xa+1];
  if(b<(int)s.size()-2)
  {
    hash2 -= revpref[b+2];
    hash2 += mod;
    hash2 %= mod;
  }
  hash2 = (1LL*hash2*pott[mpom-pom2])%mod;
  return what[a][b] = (hash1 == hash2);
}


vector <pair <int, int> > M = {{0,0},{0,0}};
vector <int> ile = {0,0}, sum = {0,0};
int mapgen = 1;

void buildtree()
{
  for(int i=0; i<(int)s.size(); i++)
  {
    int ak = 1;
    for(int j=i; j<(int)s.size(); j++)
    {
      if(s[j]=='a')
      {
        if(M[ak].first == 0)
        {
          M[ak].first = ++mapgen;
          M.push_back({0,0});
          ile.push_back(0);
          sum.push_back(0);
        }
        ak = M[ak].first;
      }
      else
      {
        if(M[ak].second == 0)
        {
          M[ak].second = ++mapgen;
          M.push_back({0,0});
          ile.push_back(0);
          sum.push_back(0);
        }
        ak = M[ak].second;
      }
      if(check(i,j))
        ile[ak]++;
    }
  }
  /*
  int coun = 0;
  for(int i=1; i<=mapgen; i++)
  {
    cout << "  " << ile[i] << "\n";
    coun += ile[i];
    cout << M[i].first << " " << M[i].second << "\n";
  }
  cout << coun << "\n";
  */
  for(int i=mapgen; i>=1; i--)
    sum[i] = ile[i]+sum[M[i].first] + sum[M[i].second];
  /*
  for(int i=1; i<=mapgen; i++)
  {
    cout << i << ":  " << sum[i] << "\n";
    cout << M[i].first << " " << M[i].second << "\n";
  }
  */
}

void find(int v, int k)
{
  int lef = sum[M[v].first],
      my = ile[v],
      pra = sum[M[v].second];
  //cout << lef << " " << my << " " << pra << "\n";
  if(k <= my)
    return;
  if(k <= my + lef)
  {
    cout << "a";
    return find(M[v].first, k-my);
  }
  else
  {
    cout << "b";
    return find(M[v].second, k-my-lef);
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> s;
  int n = (int)s.size();
  pottgen();
  hashe(0);
  hashe(1);
  revhashe(n-1);
  revhashe(n-2);
  buildtree();
  int k;
  cin >> k;
  find(1,k);
  cout << "\n";
}