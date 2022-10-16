#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
  out << v.size() << '\n';
  for(auto e : v) out << e << ' ';
  return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
  return out << '(' << p.st << ' ' << p.nd << ')';  
}

const int N = 20001000;
unsigned int n, k, m, b[N], x, y, z, l, r, t;
int a[N];
long long max_ans = 4.1e18;

void solve() {
  // dbg(max_ans);
  cin >> n;
  cin >> l >> r;
  cin >> x >> y >> z;
  cin >> b[1] >> b[2];

  a[1] = (1LL * b[1] % (long long)(r - l + 1) + 1LL * l);
  a[2] = (1LL * b[2] % (long long)(r - l + 1) + 1LL * l);
  for(int i = 3; i <= n; i++) {
    b[i] = b[i - 2] * x + b[i - 1] * y + z;
    a[i] = (1LL * b[i] % (long long)(r - l + 1) + 1LL * l);
  }

  vector<int> s;
  int mn = 2.1e9, aux;
  long long ans = max_ans;
  // n = 6;
  // a[1] = 6;
  // a[2] = 3;
  // a[3] = 10;
  // a[4] = -6;
  // a[5] = -103;
  // a[6] = -3;
  // dbg_ok;
  // dbg_v(a, n + 1);
  for(int i = 1; i <= n; i++) {
    int val = a[i];
    // dbg(val);
    if(mn < val) {
      ans = min(ans, 1LL * val * mn);

      if(val < 0) {
        aux = val;
        // dbg(s);
        while(!s.empty() && s.back() < val) {
          aux = s.back(); 
          // dbg(aux);
          s.pop_back();
        }
        // dbg_ok;
        if(aux != val)
          ans = min(ans, 1LL* val * aux);

        if(s.empty() || s.back() != val)
        	s.push_back(val);
      }
      // dbg_ok;
    } else {
    	if(val < 0) {
    		s.push_back(val);
    	}
    }
    mn = min(mn, val);
  }
  if(ans == max_ans) cout << "IMPOSSIBLE\n";
  else cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> t;
  while(t--)
    solve();

}