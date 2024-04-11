//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 507;
int w[MAXN];
long long dp[MAXN][MAXN];
vector <pair <int, char> > W;
int odp[MAXN][MAXN];
char odp2[MAXN][MAXN];

long long eat(int a, int b)
{
  if(a >= b)
    return 0;
  if(a+1 == b)
    return w[a];
  if(dp[a][b] != -2)
  {
    return dp[a][b];
  }
  dp[a][b] = -1;
  for(int k=a+1; k<b; k++)
  {
    long long lew = eat(a,k);
    long long pra = eat(k,b);
    if(lew > pra and dp[a][b] < lew+pra)
    {
      odp[a][b] = k;
      odp2[a][b] = 'R';
      dp[a][b] = lew+pra;
    }
    if(pra > lew and dp[a][b] < lew+pra)
    {
      odp[a][b] = k;
      odp2[a][b] = 'L';
      dp[a][b] = lew+pra;
    }
  }
  return dp[a][b];
}

void answer(int a, int b, int &nr)
{
  if(a+1 == b)
    return;
  answer(a, odp[a][b], nr);
  nr++;
  answer(odp[a][b], b, nr);
  W.emplace_back(nr + (odp2[a][b] == 'L' ? 1 : 0), odp2[a][b]);
  nr--;
}


int main()
{
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> w[i];
  for(int i=0; i<=n; i++)
    for(int j=0; j<=n; j++)
      dp[i][j] = -2;
  int m;
  cin >> m;
  int wsk = 0;
  int nr = 0;
  for(int i=0; i<m; i++)
  {
    int x;
    cin >> x;
    long long sum = 0;
    int wsk2 = wsk;
    while(wsk2 < n and sum < x)
    {
      sum += w[wsk2++];
    }
    if(sum != x or eat(wsk, wsk2) != sum)
    {
      puts("NO");
      return 0;
    }
    answer(wsk, wsk2, nr);
    nr++;
    wsk = wsk2;
  }
  if(wsk != n)
  {
    puts("NO");
    return 0;
  }
  cout << "YES\n";
  for(auto ele : W)
    cout << ele.first << " " << ele.second << "\n";
  return 0;
}