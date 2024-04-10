#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second
#define point pair < ll, ll >

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

#define double long double

using namespace std;

int n;
double p[1005][1005];

double E[1005];
double prob[1005];
bool bio[1005];

int pp[1005][1005];

int main(){
  cin >> n;
  REP(i,n) REP(j,n) scanf("%d", pp[i]+j), p[i][j] = pp[i][j] / 100.0;

  vector < int > V = {n-1};
  vector < int > V2;
  REP(i,n-1) V2.pb(i);
  bio[n-1] = true;
  
  REP(i,n){
    if (bio[i]) continue;
    E[i] = 1;
    prob[i] = 1;
    prob[i] *= 1-p[i][n-1];
  }

  while (!V2.empty()){
    int id = -1;
    double cal = 1e9;
    REP(i,V2.size()){
      if (prob[V2[i]] > 0.999) continue;
      double cc = E[V2[i]] / (1 - prob[V2[i]]);
      if (cc < cal) cal = cc, id = i;
    }
    if (id == -1) break;
    int x = V2[id]; 
    V2.erase(V2.begin()+id);
    bio[x] = true;
    E[x] /= 1-prob[x];
    REP(i,n){
      if (bio[i]) continue;
      if (pp[i][x] == 0) continue;
      E[i] += prob[i] * p[i][x] * E[x];
      prob[i] *= 1-p[i][x];
    }
    V.pb(x);
  } 
  
  #undef double
  printf("%.15lf\n", (double)E[0]);
  
  return 0;
}