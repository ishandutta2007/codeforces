#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n, b;
pii v[200005];
queue < int > Q;
ll out[200005];

int main(){
  ios_base::sync_with_stdio(false);

  memset(out, -1, sizeof out);
  cin >> n >> b;
  ll ct = -100;
  REP(i,n){
    cin >> v[i].x >> v[i].y;
    ll tl = v[i].x - ct;
    while (!Q.empty()){
      if (tl >= v[Q.front()].y){
	tl -= v[Q.front()].y;
	out[Q.front()] = v[i].x - tl;
	Q.pop();
      } else {
	v[Q.front()].y -= tl;
	break;
      }
    } ct = v[i].x;
    if (Q.size() <= b) Q.push(i);
  }
  while (!Q.empty()){
    ct += v[Q.front()].y; //TRACE(ct);
    out[Q.front()] = ct;
    Q.pop();
  }

  REP(i,n) cout << out[i] << ' '; cout << endl;
  
  return 0;
}