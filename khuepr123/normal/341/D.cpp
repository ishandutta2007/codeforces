/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 2005;
const ll oo = 1e18 + 7;
int n;
int x, y, z, k;

int a[maxN][maxN], B[maxN][maxN][4];
void upd(int x, int y, int v) {
  for(int i = x ; i <= n ; i += i & -i) {
    for(int j = y ; j <= n ; j += j & -j) {
      B[i][j][0] ^= v;
      B[i][j][1] ^= (x & 1) * v;
      B[i][j][2] ^= (y & 1) * v;
      B[i][j][3] ^= ((x * y) & 1) * v;
    }
  }
}
int qry(int x, int y) {
  int ans = 0; ++x; ++y;
  for(int i = x - 1 ;i; i -= i & -i) {
    for(int j = y - 1 ;j; j -= j & -j) {
      ans ^= (((x * y) & 1) * B[i][j][0]) ^ ((y & 1) * B[i][j][1]) ^ ((x & 1) * B[i][j][2]) ^ B[i][j][3];
    }
  }
  return ans;
}
void update(int x1, int y1, int x2, int y2, int v) {
  upd(x1, y1, v);
  upd(x1, y2 + 1, v);
  upd(x2 + 1, y1, v);
  upd(x2 + 1, y2 + 1, v);
}
int query(int x1, int y1, int x2, int y2) {
  return qry(x2, y2) ^ qry(x1 - 1, y2) ^ qry(x2, y1 - 1) ^ qry(x1 - 1, y1 - 1);
}
void init() {
  for1(i, 1, n) for1(j, 1, n) upd(i, j, a[i][j]);
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    memset(B, 0, sizeof(B));
    int x1, y1, x2, y2;
    int o; cin >> o; while(o--){
        cin >> z >> x1 >> y1 >> x2 >> y2;
        if(z == 1){
            cout << query(x1, y1, x2, y2) << endl;
        }
        else{
            cin >> z;
            update(x1, y1, x2, y2, z);
        }
    }
}