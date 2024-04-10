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

int a[2000005];

int main(){
  int n;
  cin >> n;

  int k = n-1;
  if (k%2 == 0) --k;
  int p = 0;
  for (int i = k; i >= 1; i -= 2) a[p++] = i;
  for (int i = 1; i <= k; i += 2) a[p++] = i;

  k = n-1;
  if (k%2 == 1) --k;
  for (int i = k; i >= 0; i -= 2) a[p++] = i;
  for (int i = 2; i <= k; i += 2) a[p++] = i;
  a[p++] = 0;

  REP(i,2*n) printf("%d ", n-a[i]); cout << endl;
  
  return 0;
}