#include "bits/stdc++.h"

using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using lll = __int128;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
const int mn = 100+10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int iinf = 0x3f3f3f3f;

struct DSU {
  int n;
  vi p;
  DSU(int n) : n(n), p(n) {
    rep(i,0,n) p[i] = i;
  }
  int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
  }
  void unite(int x, int y) {
    p[find(x)] = find(y);
  }
};


void solve() {
  int n;
  cin >> n;
  vi a(n);
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vi> lst(n+1);
  for(int i = 0; i < n; ++i) {
    lst[a[i]].push_back(i);
  }
  int nodd = -1;
  int it = 0;
  vi p(n);
  for(int i=1;i<=n;i++){
    if(sz(lst[i])&1){
      if(nodd==-1){
        nodd=i;
        if(lst[i].back()==n/2)swap(lst[i].back(),lst[i][0]);
        p[n/2]=lst[i].back();
      }
      else {
        printf("NO\n");
        return;
      }
    }
    for(int j=0;j+1<sz(lst[i]);j+=2){
      p[it]=lst[i][j];
      p[n-1-it]=lst[i][j+1];
      it++;
    }
  }
  if(nodd!=-1&&n%2==0){
    printf("NO\n");
    return;
  };
  if(nodd!=-1&&sz(lst[nodd])==1&&lst[nodd][0]==n/2){
    printf("NO\n");
    return;
  }
  DSU dsu(n);
  rep(i,0,n) {
    dsu.unite(i,p[i]);
  }
  rep(i,0,n/2) {
    if(dsu.find(i)!=dsu.find(n-i-1)) {
      swap(p[i],p[n-i-1]);
      dsu.unite(i,n-i-1);
    }
  }
  rep(i,0,n/2-1) {
    if(dsu.find(i)!=dsu.find(i+1)) {
      int t=p[i];
      p[i]=p[i+1];
      p[i+1]=p[n-i-1];
      p[n-i-1]=p[n-i-2];
      p[n-i-2]=t;
      dsu.unite(i,i+1);
    }
  }
  printf("YES\n");
  rep(i,0,n) {
    printf("%d ",p[i]+1);
  }
  printf("\n");
}

int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
  int tcc;
  cin >> tcc;
  for(int tc = 1; tc <= tcc; ++tc){
    solve();
  }
}