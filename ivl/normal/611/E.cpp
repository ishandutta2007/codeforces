#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second
#define ll long long

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int t[200005];

int solve(int a, int b, int c, int ab){
  int r = 0;
  int tmp = 0;

  r += ab;
  tmp = min(ab, c);
  c -= tmp;
  ab -= tmp;
  tmp = min(ab, b);
  b -= tmp;
  ab -= tmp;
  tmp = min(ab, a);
  a -= tmp;
  ab -= tmp;
  ab = 0;

  tmp = min(min(a, b), c);
  r += tmp;
  a -= tmp;
  b -= tmp;
  c -= tmp;

  if (c){
    if (a){
      r += c;
      a -= 2*c;
      a = max(a, 0);
      c = 0;
      return r+(a+2)/3;
    } else {
      r += c;
      b = max(0, b-c);
      return r+(b+1)/2;
    }
  } else {
    tmp = b/2;
    r += tmp;
    b -= tmp*2;
    a = max(0, a-tmp);
    if (b) ++r, a = max(0, a-2);
    return r+(a+2)/3;
  }
  
}

int main(){
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  REP(i,n) scanf("%d", t+i);
  sort(t, t+n);
  if (t[n-1] > a+b+c){cout << -1 << endl; return 0;}

  if (a > b) swap(a, b);
  if (b > c) swap(b, c);
  if (a > b) swap(a, b);

  int cnt[] = {0, 0, 0};
  int cnt2[] = {0, 0, 0};
  int cnt3 = 0;
  int weird = 0;
  
  REP(i,n){
    int x = t[i];
    if (x <= a){++cnt[0]; continue;}
    if (x > b+c){++cnt3; continue;}
    if (x > c){
      if (x <= a+b) ++cnt2[0];
      else if (x <= a+c) ++cnt2[1];
      else ++cnt2[2];
      continue;
    }
    if (x <= b){++cnt[1]; continue;}
    if (x > a+b){++cnt[2]; continue;}
    ++weird; // ili (c) ili (a+b)
  }

  // (a+b+c) AC
  // (a+b)+(c)
  // (a)+(b+c) AC
  // (a+c)+(b) AC
  // (a)+(b)+(c)
  
  int R = 0;
  R += cnt3; cnt3 = 0; // a+b+c
  R += cnt2[2]; cnt[0] -= min(cnt[0], cnt2[2]); cnt2[2] = 0; // b+c
  R += cnt2[1];
  if (cnt2[1] <= cnt[1]) cnt[1] -= cnt2[1];
  else cnt[0] -= min(cnt[0], cnt2[1]-cnt[1]), cnt[1] = 0;
  cnt2[1] = 0; // a+c

  int cr = 1000000000;
  REP(i,weird+1) cr = min(cr, solve(cnt[0], cnt[1], cnt[2]+i, cnt2[0]+weird-i));
  cout << R+cr << endl;
  
  return 0;
}