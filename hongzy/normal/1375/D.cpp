#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
 
#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
 
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned uint;
typedef unsigned long long ull;
 
const int N = 5000 + 10;
int n, m, a[N], b[N];
vector<int> seq;
int mex() {
   bool vis[N];
   fill(vis, vis + n + 1, 0);
   rep(i, 1, n) vis[b[i]] = 1;
   rep(i, 0, n) if(!vis[i]) return i;
   return -1;
}
bool fix[N];
void modify(int u, int v) {
   seq.pb(u); b[u] = v;
}
int main() {
   ucin;
   int t; cin >> t;
   while(t --) {
      cin >> n; seq.clear();
      rep(i, 1, n) cin >> a[i], b[i] = a[i], fix[i] = 0;
      while(1) {
         int c = 0;
         rep(i, 1, n) if(fix[i]) c ++;
         if(c == n) break ;
         int t = mex();
         if(t == n) {
            rep(i, 1, n) if(!fix[i]) {
               modify(i, t); break ;
            }
         } else {
            modify(t + 1, t); fix[t + 1] = 1;
         }
      }
      cout << seq.size() << endl;
      for(int v : seq) cout << v << ' ';
      cout << endl;
      
   }
   return 0;
}