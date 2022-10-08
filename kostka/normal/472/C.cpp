#include "bits/stdc++.h"

using namespace std;

int perm[100007];
int war[100007][2];
vector <pair <string, int> > V;

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i=1; i<=n; i++)
  {
    string a, b;
    cin >> a >> b;
    V.push_back(make_pair(a, -i));
    V.push_back(make_pair(b, i));
  }
  sort(V.begin(), V.end());
  for(int i=0; i<(int)V.size(); i++)
  {
    int nr = V[i].second;
    if(nr>0)
      war[nr][1] = i+1;
    else
      war[-nr][0] = i+1;
  }
  for(int i=0; i<n; i++)
    cin >> perm[i];
  int start = 0;
  for(int i=0; i<n; i++)
  {
    int a = min(war[perm[i]][0], war[perm[i]][1]), b = max(war[perm[i]][0], war[perm[i]][1]);
    if(start < a)
      start = a;
    else if(start < b)
      start = b;
    else
    {
      puts("NO");
      return 0; 
    }
  }
  puts("YES");
  return 0;
}