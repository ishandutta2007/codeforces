#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);
#define strs(args...) string args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  ints(t);
  while(t--) {
    ints(n);
    vll a(n);
    for(ll &x : a) cin >> x;
    for(int i = 1; i < n; i++) a[i] += a[i - 1];
    if(a.back() != 0) { cout << "No\n"; continue; }
    int ans = 1;
    if(*min_element(all(a)) < 0) { cout << "No\n"; ans = 0; }
    for(int i = 1; i < n && ans; i++) if(a[i - 1] == 0 && a[i] != 0) { cout << "No\n"; ans = 0; break; }
    if(ans) cout << "Yes\n";
  }
}