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

int n, k;
string in[1005];
string out[1005];

string name(int i){
  if (i < 26) return {i+'A'};
  return {'A', 'a'+i-26};
}

int main(){
  ios_base::sync_with_stdio(false);
  
  cin >> n >> k;
  int cnt = 0;
  REP(i,k-1) out[i] = name(cnt++);
  REP(i,n-k+1){
    string tmp;
    cin >> tmp;
    if (tmp == "YES")
      out[i+k-1] = name(cnt++);
    else out[i+k-1] = out[i];
  }

  REP(i,n) cout << out[i] << " "; cout << endl;
  
  return 0;
}