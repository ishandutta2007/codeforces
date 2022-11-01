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

int n;
char in[100005];

int main(){
  cin >> n;
  scanf("%s", in);

  int r[] = {0, 0};
  REP(i,n){
    int t = in[i]-'0';
    r[t] = max(r[t], r[!t]+1);
  }

  cout << min(max(r[0],r[1])+2, n) << endl;
  
  return 0;
}