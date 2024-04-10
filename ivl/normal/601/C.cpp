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

int n, m;
int x[105];

double prob(int id, int sum);

double prefix(int id, int sum){
  if (sum <= 0) return 0;
  if (id == n) return m-1;
  
  static double memo[105][105*1005];
  static bool bio[105][105*1005];
  double &r = memo[id][sum];
  if (bio[id][sum]++) return r;
  r = 0;

  //FOR(i,1,m+1) if (i != x[id]) r += prob(id+1, sum-i) / (m-1);
  r = prefix(id, sum-1) + prob(id+1, sum-1) - prob(id+1, sum-m-1);
  
  return r;
  
}

double prob(int id, int sum){
  if (sum <= 0) return 0;
  if (id == n) return 1;
  
  static double memo[105][105*1005];
  static bool bio[105][105*1005];
  double &r = memo[id][sum];
  if (bio[id][sum]++) return r;
  r = 0;

  //FOR(i,1,m+1) if (i != x[id]) r += prob(id+1, sum-i) / (m-1);
  r = prefix(id, sum) - prob(id+1, sum-x[id]);
  r /= m-1;
  
  return r;
  
}

int main(){
  cin >> n >> m;
  REP(i,n) cin >> x[i];

  if (m == 1){cout << 1 << endl; return 0;}
  
  int sum = 0;
  REP(i,n) sum += x[i];
  //cout << prob(0, sum) << endl;
  printf("%.15lf\n", 1+(m-1)*prob(0, sum));
  
  return 0;
}