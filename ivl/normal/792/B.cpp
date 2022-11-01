#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  vector<int> ch(n);
  iota(ch.begin(), ch.end(), 1);
  int id = 0;
  REP(i,k){
    int x;
    cin >> x;
    id += x;
    id %= ch.size();
    cout << ch[id] << " ";
    ch.erase(ch.begin()+id);
  } cout << endl;

  return 0;
}