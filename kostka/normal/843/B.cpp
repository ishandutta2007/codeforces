//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int INF = 1000000007;
map <int, pair <int, int> > E;
int counter = 0;
int res = INF, act_res = INF, maks = -1, X;
const int MAXN = 50007;
int przynajmniej[MAXN];

pair <int, int> generated[MAXN];

int losowy(int n)
{
  return (rand()*rand() + rand())%n + 1;
} 

bool worth_asking(int x)
{
  return true;
  if(!przynajmniej[x])
    return true;
  if(res != INF and przynajmniej[x] > res)
    return false;
  if(maks < X and przynajmniej[x] < maks)
    return false;
  return true;
}

void ask(int x)
{
  if(E.find(x) != E.end())
    return;
  counter++;
  cout << "? " << x << "\n";
  fflush(stdout);
  pair <int, int> w; // = generated[x];
  cin >> w.first >> w.second;
  E[x] = w;
  if(w.first < res and w.first >= X)
    res = w.first;
  maks = max(w.first, maks);
  przynajmniej[w.second] = w.first+1;
}

void generate(int n, int start)
{
  set <int> S;
  while((int)S.size() != n)
    S.insert(rand()%10000000001);
  for(auto x : S)
  {
    if(x >= X and x < act_res)
      act_res = x;
  }
  vector <int> V = {start};
  for(int i=1; i<=n; i++)
    if(i != start)
      V.push_back(i);
  random_shuffle(V.begin()+1, V.end());
  V.push_back(-1);
  int ix = 1;
  for(auto jx : S)
  {
    generated[V[ix-1]].first = jx;
    generated[V[ix-1]].second = V[ix];
    ix++;
  }
  cerr << generated[start].first << "\n";
}


int main()
{
  ios_base::sync_with_stdio(0);
  srand(15061994);
  int n, start;
  cin >> n >> start >> X;
  //cerr << n << " " << start << " " << X << "\n";
  //generate(n, start);
  //X = act_res;
  if(n <= 1999)
  {
    for(int i=1; i<=n; i++)
      ask(i);
  }
  else
  {
    ask(start);
    while((int)E.size() != min(999, n))
    {
      int x = losowy(n);
      if(worth_asking(x))
        ask(x);
    }
    int found = start;
    //cerr << "FOUND " << E[start].first << "\n";
    for(auto e : E)
    {
      if(e.second.first > E[found].first and e.second.first <= X)
        found = e.first;
    }
    //cerr << "FOUND " << E[found].first << "\n";
    int x = E[found].second;
    while(x != -1 and (int)E.size() != min(1999, n))
    {
      ask(x);
      x = E[x].second;
    }
  }
  cout << "! " << (res == INF ? -1 : res) << "\n";
  //cerr << "! " << (act_res == INF ? -1 : act_res) << "\n";
  //assert(res == act_res);
  //cerr << "TRIES " << (int)E.size() << "\n";
  fflush(stdout);
  return 0;
}