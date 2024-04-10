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

const int Mod = 1e9+7;
int add(int x, int y){x += y; if (x >= Mod) return x-Mod; return x;}
int mul(int x, int y){return (int)((ll)x*y%Mod);}
int sub(int x, int y){x -= y; if (x < 0) return x+Mod; return x;}
int pot(int x, int y){
  int r = 1;
  while (y){
    if (y&1) r = mul(r, x);
    x = mul(x, x), y >>= 1;
  } return r;
}
int inv(int x){assert(x != 0); return pot(x, Mod-2);}

const int Mod2 = 1e9+6;
int add2(int x, int y){x += y; if (x >= Mod2) return x-Mod2; return x;}
int mul2(int x, int y){return (int)((ll)x*y%Mod2);}
int sub2(int x, int y){x -= y; if (x < 0) return x+Mod2; return x;}
int pot2(int x, int y){
  int r = 1;
  while (y){
    if (y&1) r = mul2(r, x);
    x = mul2(x, x), y >>= 1;
  } return r;
}

pii concat(pii a, pii b){
  return {add(mul(a.x, pot(10, b.y)), b.x), add2(a.y, b.y)};
}

pii cast(string s){
  pii sol = {0, 0};
  for (auto t : s)
    sol = {add(mul(sol.x, 10), t-'0'), add2(sol.y, 1)};
  return sol;
}

pii concatself(pii a, int b){
  if (b == 0) return {0, 0};
  pii sol = a;
  REP(i,b-1) sol = concat(sol, a);
  return sol;
}

void inc(string &s){
  int pos = (int)s.size()-1;
  while (s[pos] == '9')
    s[pos--] = '0';
  if (pos == -1) s.insert(s.begin(), '1');
  else ++s[pos];
}

pii kojikurac4(int l){

  // TRACE(l);

  int lambda = pot(10, l);
  int lo1 = pot(10, l-1);
  int lo2 = pot2(10, l-1);
  int hi1 = sub(pot(10, l), 1);
  int hi2 = sub2(pot2(10, l), 1);

  int explen = mul2(l, add2(1, sub2(hi2, lo2)));

  int del1 = sub(hi1, lo1);
  int del2 = sub2(hi2, lo2);

  if (lambda == 1){
    return {sub(mul(hi1, add(del1, 1)), mul(mul(del1, add(del1, 1)), inv(2))), explen};
  }

  int expmod = mul(hi1, mul(sub(pot(lambda, add2(del2, 1)), 1), inv(sub(lambda, 1))));
  int phi = inv(sub(lambda, 1));
  phi = mul(lambda, mul(phi, phi));
  expmod = sub(expmod, sub(sub(phi, mul(phi, pot(lambda, del2))), mul(del1, mul(pot(lambda, add(del2, 1)), inv(sub(1, lambda))))));

  

  return {expmod, explen};
  
}

pii kojikurac2(string &a, string &b){
  if (a.size() == b.size()){
    int len = (int)a.size();

    vector<int> delta(len);
    REP(i,len) delta[i] =  b[i]-'0';
    REP(i,len) delta[i] -= a[i]-'0';
    for (int i = len-1; i >= 0; --i)
      if (delta[i] < 0)
	delta[i] += 10, --delta[i-1];

    // explen = len * delta % mod2

    int del2 = 0;
    int del1 = 0;
    for (auto t : delta)
      del2 = add2(mul2(del2, 10), t),
	del1 = add(mul(del1, 10), t);
    int explen = mul2(add2(del2, 1), len);

    // expmod = neka suma - neka druga suma
    int lambda = pot(10, len);

    int mod1 = 0;
    int mod2 = 0;
    int bb = 0;
    for (auto t : b)
      bb = add(mul(bb, 10), t-'0');

    if (lambda == 1) mod1 = mul(bb, add(del1, 1));
    else mod1 = mul(bb, mul(sub(pot(lambda, add2(del2, 1)), 1), inv(sub(lambda, 1))));

    if (lambda == 1) mod2 = mul(mul(del1, add(del1, 1)), inv(2));
    else {
      int tmp = inv(sub(1, lambda));
      tmp = mul(mul(tmp, lambda), tmp);
      mod2 = sub(sub(tmp, mul(tmp, pot(lambda, add2(0, del2)))), mul(del1, mul(pot(lambda, add2(del2, 1)), inv(sub(1, lambda)))));
    }

    int expmod = sub(mod1, mod2);

    // TRACE(expmod _ explen);
    
    return {expmod, explen};
  } else {

    string bla(a.size(), '9');
    pii sol = kojikurac2(a, bla);
    int len = (int)a.size()+1;
    while (len < (int)b.size()){
      sol = concat(sol, kojikurac4(len));
      // TRACE(len _ kojikurac4(len).x _ kojikurac4(len).y);
      ++len;
    }
    bla = '1' + string(b.size()-1, '0');
    return concat(sol, kojikurac2(bla, b));
    
  }
}

pii kojikurac(string &a, string &b){
  return kojikurac2(a, b);
  pii sol = cast(a);
  while (a != b){
    inc(a);
    sol = concat(sol, cast(a));
  } return sol;
}

string s;
int pos = 0;

string number(){
  string sol;
  while (s[pos] >= '0' && s[pos] <= '9')
    sol.pb(s[pos++]);
  return sol;
}

pii expression();

pii term(){
  string tmp = number();
  if (s[pos] == '-'){
    ++pos;
    string tmp2 = number();
    return kojikurac(tmp, tmp2);
  } else if (s[pos] == '('){
    ++pos;
    pii tmp2 = expression();
    ++pos;
    pii sol = {0, 0};
    for (auto t : tmp){
      sol = concat(concatself(sol, 10), concatself(tmp2, t-'0'));
    } return sol;
  } else {
    return cast(tmp);
  }
}

pii expression(){
  pii sol = {0, 0};
  while (true){
    sol = concat(sol, term());
    if (s[pos] != '+') break;
    ++pos;
  }
  return sol;
}

int main(){
  ios_base::sync_with_stdio(false);

  // int A = 2;
  // TRACE(kojikurac4(A).x _ kojikurac4(A).y);
  // string a = '1' + string(A-1, '0');
  // string b = string(A, '9');
  // string aa = a, bb = b;
  // TRACE(kojikurac(a, b).x _ kojikurac(aa, bb).y);
  // exit(0);

  cin >> s;
  s.pb('#');
  pii sol = expression();
  cout << sol.x << endl;
  
  return 0;
}