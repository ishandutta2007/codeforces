//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

const int DRZ = 1<<17;
int drz[2*DRZ];

const int MAXN = 100007;
int sum_pref[MAXN], lft[MAXN], rht[MAXN];

void change(int v, int k) {
  v += DRZ;
  while(v) {
    drz[v] = max(drz[v], k);
    v >>= 1;
  }
}

int query(int a, int b) {
  if(a > b) return 0; //aaaaa...
  a += DRZ;
  b += DRZ;
  int ret = max(drz[a], drz[b]);
  while(a < b) {
    if(a%2) ret = max(ret, drz[a++]);
    if(!(b%2)) ret = max(ret, drz[b--]);
    a /= 2;
    b /= 2;
  }
  if(a == b) ret = max(ret, drz[a]);
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  while(n--) {
    int a, b;
    cin >> a >> b;
    sum_pref[a-1]++;
    sum_pref[b]--;
  }
  for(int i=1; i<=m; i++) sum_pref[i] += sum_pref[i-1];
  for(int i=0; i<m; i++) {
    lft[i] = query(0, sum_pref[i]);
    change(sum_pref[i], 1+lft[i]);
  }
  for(int i=0; i<2*DRZ; i++) drz[i] = 0;
  for(int i=m-1; i>=0; i--) {
    rht[i] = query(0, sum_pref[i]);
    change(sum_pref[i], 1+rht[i]);
  }
  int ret = 0;
  for(int i=0; i<m; i++) ret = max(ret, lft[i]+rht[i]+1);
  cout << ret << "\n";
  return 0;
}