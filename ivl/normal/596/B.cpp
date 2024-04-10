#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pii pair < int, int >
#define x first
#define y second
#define ll long long

using namespace std;

int n;
int b[200005];

int main(){
  cin >> n;
  REP(i,n) scanf("%d", b+i);
  ll del = 0;
  ll R = 0;
  REP(i,n){
    R += abs(del - b[i]);
    del = b[i];
  } cout << R << endl;
  return 0;
}