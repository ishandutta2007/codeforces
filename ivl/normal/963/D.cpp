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

const int P = 101;
int pot[200005];
struct hstring{
  const string *src;
  vector<int> h;
  hstring() : src(nullptr), h(1){}
  hstring(const string &str) : src(&str), h(str.size()+1){
    REP(i,str.size()) h[i+1] = h[i]*P + str[i];
  }

  int size() const {return (int)src->size();}
  char operator[](int x) const {return (*src)[x];}
  int operator()(int x) const {return h[x];}
};

struct hstring2{
  const hstring *src;
  int shift;
  hstring2(hstring &_src, int _shift = 0) : src(&_src), shift(_shift){}

  int size() const {return src->size() - shift;}
  char operator[](int x) const {return (*src)[x+shift];}
  int operator()(int x) const {return (*src)(x+shift) - (*src)(shift) * pot[x];}
};

int lcp(const hstring2 &a, const hstring2 &b){
  int lo = 0, hi = min(a.size(), b.size()), mid;
  while (lo != hi){
    mid = (lo+hi+1)/2;
    if (a(mid) != b(mid)) hi = mid-1;
    else lo = mid;
  } return lo;
}

bool operator<(const hstring2 &a, const hstring2 &b){
  int tmp = lcp(a, b);
  if (tmp == a.size()) return b.size() != tmp;
  if (tmp == b.size()) return false;
  return a[tmp] < b[tmp];
}

string s;
int n;

int main(){
  ios_base::sync_with_stdio(false);

  pot[0] = 1;
  REP(i,2e5) pot[i+1] = P * pot[i];

  cin >> s;

  hstring hs(s);
  vector<hstring2> suffix;
  REP(i,s.size()) suffix.emplace_back(hs, i);
  sort(suffix.begin(), suffix.end());

  cin >> n;
  REP(blatruc,n){
    int k; cin >> k;
    string m; cin >> m;
    hstring hm(m);
    hstring2 hm2(hm);
    int sz = (int)m.size();
    vector<int> loc;
    for (auto it = lower_bound(suffix.begin(), suffix.end(), hm2);
	 it != suffix.end() && it->size() >= sz && (*it)(sz) == hm(sz); ++it)
      loc.pb(it->shift);
    if ((int)loc.size() < k){cout << -1 << endl; continue;}
    sort(loc.begin(), loc.end());
    int sol = 1e9;
    REP(i,loc.size()-k+1) sol = min(sol, loc[i+k-1]-loc[i]);
    cout << sol+sz << endl;
  }

  return 0;
}