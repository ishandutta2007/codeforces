#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;

int n;
int a[200005]; int ptr;
bitset<200005> has;

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> a[i];
  REP(i,n){
    int b;
    cin >> b;
    if (has[b]){cout << 0 << " "; continue;}
    int cnt = 0;
    do {
      has[a[ptr]] = true;
      ++cnt;
    } while (a[ptr++] != b);
    cout << cnt << " ";
  } cout << endl;

  return 0;
}