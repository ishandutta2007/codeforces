#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define ll long long
#define x first
#define y second
#define pii pair < int, int >

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n, k;
char in[1000005];

int main(){
  
  cin >> n >> k;
  scanf("%s", in);
  REP(i,n) in[i] -= 'a';

  REP(i,n){
    int t = (in[i] <= 12 ? +1 : -1);
    int lim = (in[i] <= 12 ? 25-in[i] : in[i]);
    if (lim >= k){
      in[i] += t*k;
      k = 0;
    } else {
      in[i] += t*lim;
      k -= lim;
    } in[i] += 'a';
  }

  if (k) printf("-1\n");
  else printf("%s\n", in);
  
  return 0;
}