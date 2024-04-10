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

ll f(ll a){return a*(a-1)/2;}

int main(){
  ll n;
  cin >> n;

  ll lo = 0, hi = 1e8, mid;
  while (lo != hi){
    mid = (lo+hi+1)/2;
    if (f(mid) < n) lo = mid;
    else hi = mid-1;
  } cout << n-f(lo) << endl;
  
  return 0;
}