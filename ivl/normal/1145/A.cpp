#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)

#define pb push_back
#define x first
#define y second

using namespace std;

int f(vector<int>::iterator lo, vector<int>::iterator hi){
  if (hi-lo == 1) return 1;
  
  auto mid = lo + (hi-lo)/2;
  int lov = f(lo, mid);
  int hiv = f(mid, hi);

  if (lov == hiv && lov == (hi-lo)/2 && *mid >= *(mid-1))
    return (int)(hi-lo);
  else return max(lov, hiv);
}

int main(){

  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  cout << f(a.begin(), a.end()) << endl;

  return 0;
}