//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 200007;
const int LOG = 20;
vector <pair <int, int> > G[MAXN];
int pre[MAXN], post[MAXN];
long long odl[MAXN];
int prz[LOG][MAXN];
int tim = 0;

void dfs(int v, long long d = 0)
{
  pre[v] = ++tim;
  odl[v] = d;
  for(auto& ele : G[v])
  {
    int w, e;
    tie(w,e) = ele;
    dfs(w, d+e);
    prz[0][w] = v;
  }
  post[v] = ++tim;
}

int A[MAXN];
int war[MAXN], res[MAXN];

bool ok(int kan, int ja)
{
  return (odl[ja] - odl[kan]) <= A[ja];
}

void dfs2(int v)
{
  for(auto ele : G[v])
  {
    int a, b;
    tie(a,b) = ele;
    dfs2(a);
    war[v] += war[a];
  }
}

int main()
{
  int n;
  cin >> n;
  for(int i=1; i<=n; i++)
    cin >> A[i];
  for(int i=2; i<=n; i++)
  {
    int a, b;
    cin >> a >> b;
    G[a].push_back(make_pair(i,b));
  }
  dfs(1);
  prz[0][1] = 0;
  odl[0] = - (1e9+7);
  for(int poz=1; poz<LOG; poz++)
    for(int i=1; i<=n; i++)
      prz[poz][i] = prz[poz-1][prz[poz-1][i]];
  //for(int i=1; i<=n; i++)
  //  cerr << odl[i] << " " << prz[0][i] << "\n";
  //cerr << "\n";
  for(int i=2; i<=n; i++)
  {
    int j = i;
    for(int poz=LOG-1; poz>=0; poz--)
  	{
  		if(ok(prz[poz][j],i))
  			j = prz[poz][j];
  	}
    war[prz[0][i]]++;
    war[prz[0][j]]--;
    //cerr << i << " " << j << "\n";
  }
  dfs2(1);
  for(int i=1; i<=n; i++)
    cout << war[i] << " ";
  cout << "\n";
  return 0;
}