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

char in[1000005];
int l;

int main(){
  scanf("%s", in);
  l = (int)strlen(in);
  REP(i,l) in[i] -= '0';
  
  ll R = 0;
  REP(i,l) if (in[i]%4 == 0) ++R;
  FOR(i,1,l) if ((in[i-1]*2+in[i])%4 == 0) R += i;
  cout << R << endl;
  
  return 0;
}