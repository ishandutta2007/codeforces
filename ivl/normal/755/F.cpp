#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define x first
#define y second
#define pb push_back

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, k;
int p[1000005];

int last[1000005];
bool vb[1000005];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> k;
  REP(i,n) cin >> p[i], --p[i];

  vector<int> v;
  REP(i,n) if (p[i] != -1){
    int x = i;
    int t = 0;
    do {
      ++t;
      int y = p[x];
      p[x] = -1;
      x = y;
    } while (x != -1);
    v.pb(t-1);
  }

  {
    int sol = k+1;
    vector<int> tmp = v;
    sort(v.begin(), v.end());
    while (!v.empty() && v.back() > k) v.pop_back();

    vb[0] = true;
    int maks = 0;
    for (int i = 0, j = 0; i < (int)v.size(); i = j){
      while (j < (int)v.size() && v[i] == v[j]) ++j;
      int del = j-i;
      int bla = v[i];
      REP(ii,maks+1) if (vb[ii]) last[ii] = del+1; else last[ii] = 0;
      maks += del*bla;
      REP(ii,maks+1) if (last[ii] && last[ii] > last[ii+bla]) last[ii+bla] = last[ii]-1;
      REP(ii,maks+1) if (last[ii]) vb[ii] = true;
    }

    if (vb[k]) sol = k;
    cout << sol << " ";
    
    v = tmp;
  }

  {
    int sol = 0;
    int tmp = 0;
    int rem = k;
    while (!v.empty() && rem){
      if (v.back() == 0){v.pop_back(); continue;}
      if (v.back() == 1){v.pop_back(); ++tmp; continue;}
      v.back() -= 2;
      sol += 2;
      --rem;
    }
    cout << sol + min(tmp, rem) << endl;
  }

  return 0;
}