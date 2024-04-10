#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define ll long long
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n, m;

int main(){
  cin >> n >> m;

  int lo = 0, hi = 1000000000, mid;
  while (lo != hi){
    mid = (lo+hi)/2;
    int nn = max(n-mid/2+mid/6, 0);
    int mm = max(m-mid/3+mid/6, 0);
    int rem = mid/6;
    if (nn+mm > rem) lo = mid+1;
    else hi = mid;
  } cout << lo << endl;
  
  return 0;
}