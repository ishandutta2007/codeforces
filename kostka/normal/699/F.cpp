//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

struct point
{
  int x, y;
};

const int MAXK = 17;
const int MAXN = 1007;

point K[MAXK];
point N[MAXN];
vector <vector <int> > A, B;

bool kill(int monster, vector <int> &P, unordered_set <int> &killed)
{
  if(P.empty())
    return false;

  int miejsce = P.back();
  P.pop_back();
  int kolejnosc = B[miejsce][monster];
  // careful!
  while(true)
  {
    while(kolejnosc > 0 and killed.find(A[miejsce][kolejnosc-1]) != killed.end())
      kolejnosc--;
    if(kolejnosc == 0)
      return true;

    int stoi = A[miejsce][kolejnosc-1];
    int ex = N[monster].x - K[miejsce].x, ey = N[monster].y - K[miejsce].y;
    int fx = N[stoi].x - K[miejsce].x, fy = N[stoi].y - K[miejsce].y;
    int ge = abs(__gcd(ex, ey)), gf = abs(__gcd(fx, fy));
    auto xx = make_pair(ex/ge, ey/ge), yy = make_pair(fx/gf, fy/gf);
    if(xx != yy)
    {
      killed.insert(monster);
      return true;
    }
    else
    {
      if(kill(stoi, P, killed) == false)
        return false;
      else
        killed.insert(stoi);
    }
  }

  return false;
}

int main()
{
  int k, n;
  cin >> k >> n;
  for(int i=0; i<k; i++)
    cin >> K[i].x >> K[i].y;
  for(int i=0; i<n; i++)
    cin >> N[i].x >> N[i].y;
  A.resize(k);
  B.resize(k);
  for(int i=0; i<k; i++)
  {
    for(int j=0; j<n; j++)
      A[i].push_back(j);
    sort(A[i].begin(), A[i].end(), [&](int a, int b){
      int ex = N[a].x - K[i].x, ey = N[a].y - K[i].y;
      int fx = N[b].x - K[i].x, fy = N[b].y - K[i].y;
      int ge = abs(__gcd(ex, ey)), gf = abs(__gcd(fx, fy));
      auto xx = make_pair(ex/ge, ey/ge), yy = make_pair(fx/gf, fy/gf);
      if(xx == yy)
        return make_pair(abs(ex),abs(ey)) < make_pair(abs(fx),abs(fy));
      else
        return xx < yy;
    });
    //for(int j=0; j<n; j++)
    //  cerr << A[i][j] << " ";
    //cerr << "\n";
    B[i].resize(n);
    for(int j=0; j<n; j++)
      B[i][A[i][j]] = j;
  }
  int res = 0;
  for(int i=0; i<n; i++)
  {
    vector <int> P;
    for(int j=0; j<k; j++)
      P.push_back(j);
    //cerr << i << "\n";
    do
    {
      unordered_set<int> T;
      auto E = P;
      if(kill(i, E, T))
      {
        res++;
        break;
      }
      //cerr << "\n";
    }while(next_permutation(P.begin(), P.end()));
  }
  cout << res << "\n";
  return 0;
}