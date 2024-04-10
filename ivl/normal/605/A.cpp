#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n;
int p[100005];

int last[100005];

int main(){
  cin >> n;
  REP(i,n) scanf("%d", p+i);

  memset(last, -1, sizeof last);
  REP(i,n){
    if (p[i] == 0 || last[p[i]-1] == -1) last[p[i]] = 0;
    else last[p[i]] = last[p[i]-1]+1;
  }

  
  
  int R = 0;
  REP(i,n+1) R = max(R, last[i]+1);
  cout << n-R << endl;
  
  return 0;
}