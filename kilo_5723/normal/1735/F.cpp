#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
const double eps = 1e-11;
const int maxn = 3e5 + 5;
struct segment {
  ll x, y;
  int id;
  double len;
};
bool operator<(segment a, segment b) {
  ll det = a.x * b.y - a.y * b.x;
  if (det != 0) return det > 0;
  return a.id > b.id;
}
segment arr[maxn];
multiset<segment> st;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    double ar, br, al, bl;
    scanf("%d%lf%lf", &n, &ar, &br);
    al = ar;
    bl = br;
    for (int i = 0; i < n; i++) scanf("%lld", &arr[i].x);
    for (int i = 0; i < n; i++) scanf("%lld", &arr[i].y);
    for (int i = 0; i < n; i++) {
      arr[i].len = 2;
      arr[i].id = i;
    }
    st.clear();
    for (int i = 0; i < n; i++) {
      st.insert(arr[i]);
      al -= arr[i].x;
      bl += arr[i].y;
      ar += arr[i].x;
      br -= arr[i].y;
      while (al < -eps) {
        auto seg = *st.begin();
        if (al + seg.len * seg.x < eps) {
          al += seg.len * seg.x;
          bl -= seg.len * seg.y;
          st.erase(st.begin());
        } else {
          double det = -al / seg.x;
          seg.len -= det;
          al = 0;
          bl -= det * seg.y;
          st.erase(st.begin());
          st.insert(seg);
        }
      }
      while (br < -eps) {
        auto seg = *st.rbegin();
        if (br + seg.len * seg.y < eps) {
          ar -= seg.len * seg.x;
          br += seg.len * seg.y;
          st.erase(prev(st.end()));
        } else {
          double det = -br / seg.y;
          seg.len -= det;
          ar -= det * seg.x;
          br = 0;
          st.erase(prev(st.end()));
          st.insert(seg);
        }
      }
      // for (auto seg:st) printf("%lld %lld %.6f\n",seg.x,seg.y,seg.len);
      // printf("%lf %lf %lf %lf\n",al,bl,ar,br);
      printf("%.6f\n", ar);
    }
  }
  return 0;
}