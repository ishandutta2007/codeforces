#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define all(a) (a).begin(), (a).end()
#define gcd(a, b) __gcd(a, b)
#define _ << " " <<

using namespace std;

typedef unsigned long long int64;
typedef pair<int64, int64> point;

#define x first
#define y second


int64 mult(int64 x) {
   return x * x;
}

int64 ccw(point a, point b, point c) {
   return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
}

int64 dist(point a, point b) {
   return mult(a.x - b.x) + mult(a.y - b.y);
}

point points[100005];
vector<point> v;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);
   int n; cin >> n; n--;
   point F; cin >> F.x >> F.y; cout << 1 << " ";
   for(int i = 0; i < n; ++i) {
      point S; cin >> S.x >> S.y;
      points[i + 2] = S;
      v.push_back(point(dist(F, S), i + 2));
   }
   sort(all(v));
   int cnt = 1;
   while(ccw(F, points[v.front().y], points[v[cnt].y]) == 0) {
      cnt ++;
   }
   cout << v.front().y << " " << v[cnt].y;
}