#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int h;
int a[100005];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> h;
  REP(i,h+1) cin >> a[i];

  REP(i,h) if (a[i] != 1 && a[i+1] != 1){
    cout << "ambiguous" << endl;
    int pt = 1;
    REP(j,h+1){
      int prev = pt-1;
      REP(k,a[j]) cout << prev << " ";
      pt += a[j];
    } cout << endl;
    pt = 1;
    REP(j,i+1){
      int prev = pt-1;
      REP(k,a[j]) cout << prev << " ";
      pt += a[j];
    }
    cout << pt-2 << " ";
    ++pt;
    --a[i+1];
    FOR(j,i+1,h+1){
      int prev = pt-1-(j==i+1);
      REP(k,a[j]) cout << prev << " ";
      pt += a[j];
    } cout << endl;
    return 0;
  }

  cout << "perfect" << endl;
  
  return 0;
}