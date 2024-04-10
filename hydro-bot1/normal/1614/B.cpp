#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
#include<limits>
#include<cmath>
#include<map>
#include <set>
using namespace std;
#define ll long long
const int N = 2e5 + 10;
ll a[N];
int pos[N];
struct node{
    int timi;
    int idx;
};
node e[N];
int main () {
    int t;
    cin >> t;
    while (t--) {
      int n;
      cin >> n;
      for(int i = 1; i <= n; i++) {
          cin >> e[i].timi;
          e[i].idx = i;
      }
      sort(e + 1, e + 1 + n,[](node&n1, node &n2) {
          return n1.timi > n2.timi;
      });
      ll lo = -1, hi = 1;
      ll dist = 0;
      for(int i = 1; i <= n; i++) {
          if(abs(lo) < abs(hi)) { // lo++
              pos[e[i].idx] = lo;
              dist += e[i].timi * abs(lo);
              lo--;

          }else {
              pos[e[i].idx] = hi;
              dist += e[i].timi * hi;
              hi++;

          }
      }
      cout << dist * 2 << "\n";
      for(int i = 0; i <= n; i++)
          cout << pos[i] << " ";
      puts("");

    }
}