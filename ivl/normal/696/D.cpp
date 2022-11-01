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
typedef pair < int, int > pii;

const int oo = 1e9;
const ll ool = (ll)oo * oo * 2;
const int MAX = 205;
typedef ll matrix[MAX][MAX];

void mul(matrix &A, matrix &B, matrix &out){
  REP(i,MAX) REP(j,MAX) out[i][j] = -ool;
  REP(i,MAX) REP(j,MAX) REP(k,MAX) out[i][j] = max(out[i][j], A[i][k] + B[k][j]);
}

void mul_safe(matrix &A, matrix &B, matrix &out){
  static matrix tmp;
  mul(A, B, tmp);
  memcpy(out, tmp, sizeof tmp);
}

int n; ll l;
int a[205];
string s[205];

pii conv[205];
string str[205];
int conv2[205][205];
int num = 0;
void add(int x, int y){conv[num] = {x, y}; conv2[x][y] = num; ++num;}

int val[205];
bool nxt[205][205];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> l;
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> s[i];

  add(0, 0);
  REP(i,n) REP(j,s[i].size()) add(i, j+1);
  assert(num < 205);

  REP(i,num){
    int x = conv[i].x, y = conv[i].y;
    string curr(s[x].begin(), s[x].begin()+y);
    str[i] = curr;
    REP(j,n) if (s[j].size() <= curr.size()){
      bool check = true;
      REP(k,s[j].size()) check &= s[j][k] == curr[curr.size()-s[j].size()+k];
      if (check) val[i] += a[j];
    }
  }

  REP(i,num) REP(j,26){
    string curr = str[i];
    curr.pb((char)('a' + j));
    REP(k,num) if (str[k].size() <= curr.size()){
      bool check = true;
      REP(t,str[k].size()) check &= str[k][t] == curr[curr.size()-str[k].size()+t];
      if (check) nxt[i][k] = true;
    }
  }

  matrix A, R;
  REP(i,MAX) REP(j,MAX) A[i][j] = R[i][j] = -ool;
  REP(i,MAX) A[i][i] = R[i][i] = 0;
  REP(i,num) REP(j,num) if (nxt[i][j]) A[i][j] = val[j];

  while (l){
    if (l&1) mul_safe(A, R, R);
    mul_safe(A, A, A);
    l >>= 1;
  }

  ll r = -ool;
  REP(i,num) r = max(r, R[0][i]);
  cout << r << endl;
  
  return 0;
}