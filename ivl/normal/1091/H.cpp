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

int erat[200005];

const int BIT = 200;
int mex(const vector<int> &v){
  bitset<BIT> bit;
  for (auto t : v)
    if (t < BIT)
      bit[t] = 1;
  REP(i,BIT)
    if (!bit[i])
      return i;
  assert(false);
}

const int SMALL = 1<<7;
const int BIG = 1<<18;
const int LEN = BIG/SMALL;
struct Magija {
  bool dead[LEN];
  bitset<SMALL> bits[LEN];
  int shift;

  Magija(){
    REP(i,LEN) dead[i] = true;
  }

  void set(int pos){
    int id = (pos + shift) % LEN;
    bits[id][pos/LEN] = 1;
    dead[id] = false;
  }

  void sshift(){
    --shift;
    if (shift < 0) shift += LEN;
    bits[shift] <<= 1;
  }

  bool intersects(const Magija &bla){
    int ii = bla.shift;
    REP(i,LEN){
      if (!dead[i])
	if ((bits[i] & bla.bits[ii]).count())
	  return true;
      ++ii;
      if (ii == LEN) ii = 0;
    }
    return false;
  }
};

vector<int> moves;
vector<int> grundies(int f){
  vector<int> grundy(200005);
  int ind = 0;

  Magija bitsets[BIT];
  Magija curr;

  FOR(i,1,grundy.size()){
    curr.sshift();
    if (moves[ind] == f) ++ind;
    if (moves[ind] < i){
      curr.set(1);
      ++ind;
    }
    
    int tmp = 0;
    while (bitsets[tmp].intersects(curr)) ++tmp;
    grundy[i] = tmp;
    bitsets[grundy[i]].set(i);
  }

  return grundy;
}

int main(){
  ios_base::sync_with_stdio(false);

  TRACE(SMALL);

  FOR(i,2,200005)
    if (erat[i] == 0)
      for (int j = i; j < 200005; j += i)
	erat[j] = i;

  FOR(i,2,200005)
    if (erat[i] == i || erat[i / erat[i]] == i / erat[i])
      moves.pb(i);
  moves.pb(1e9);

  int n, f;
  cin >> n >> f;

  vector<int> grundy = grundies(f);

  int g = 0;
  REP(i,n){
    int a, b, c; cin >> a >> b >> c;
    g ^= grundy[b-a];
    g ^= grundy[c-b];
  }

  if (g) cout << "Alice" << endl << "Bob" << endl;
  else cout << "Bob" << endl << "Alice" << endl;
  
  return 0;
}