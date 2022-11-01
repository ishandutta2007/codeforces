#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define x first
#define y second
#define pb push_back

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int offset = 1<<20;
int T[offset*2];

void add(int id, int lo, int hi, int p){
  if (lo > p || hi < p) return;
  ++T[id];
  if (lo == hi) return;
  int mid = (lo+hi)/2;
  add(id*2, lo, mid, p);
  add(id*2+1, mid+1, hi, p);
}

int query(int id, int lo, int hi, int slo, int shi){
  if (lo > shi || hi < slo) return 0;
  if (lo >= slo && hi <= shi) return T[id];
  int mid = (lo+hi)/2;
  return query(id*2, lo, mid, slo, shi) + query(id*2+1, mid+1, hi, slo, shi);
}

int main(){
  ios_base::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  k = min(k, n-k);
  ll sol = 1;
  int curr = 0;
  do {
    int nxt = curr+k;
    if (nxt < n) sol += query(1, 0, offset-1, curr+1, nxt-1);
    else {
      nxt -= n;
      sol += query(1, 0, offset-1, 0, nxt-1) + query(1, 0, offset-1, curr+1, n-1);
    }
    ++sol;
    add(1, 0, offset-1, curr);
    add(1, 0, offset-1, nxt);
    curr = nxt;
    cout << sol << " ";
  } while (curr); cout << endl;
  
  return 0;
}