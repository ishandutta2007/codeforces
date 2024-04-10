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

int n, k;
int a[100005];

int pret[] = {0, 1, 0, 1, 2, 0};
int func(int x){
  if (x <= 5) return pret[x];

  if (x%2 == 1) return 0;
  int t = func(x/2);
  if (t == 1) return 2;
  return 1;
}

int main(){

  cin >> n >> k;
  REP(i,n) scanf("%d", a+i);

  int grundy = 0;
  
  if (k%2 == 0){
    REP(i,n){
      if (a[i] < 3) grundy ^= a[i];
      else grundy ^= (a[i]+1)%2;
    }
  } else {
    REP(i,n) grundy ^= func(a[i]);
  }

  if (grundy) cout << "Kevin\n";
  else cout << "Nicky\n";
  return 0;
}