#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " _ " << x << endl
#define _ << " _ " <<

using namespace std;

int n;
pii in[1<<20];

int sol[1<<20];
int Get(int id){if (id < 0) return 0; return sol[id];}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> in[i].x >> in[i].y, in[i].x += 5;
  sort(in, in+n);

  int prev = 0;
  REP(i,n){
    FOR(j,prev+1,in[i].x) sol[j] = sol[prev];
    sol[in[i].x] = 1+Get(in[i].x-in[i].y-1);
    prev = in[i].x;
  }

  int r = 0;
  REP(i,1<<20) r = max(r, sol[i]);
  cout << n-r << endl;
  
  return 0;
}