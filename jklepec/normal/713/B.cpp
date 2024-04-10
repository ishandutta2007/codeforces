#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

typedef double lf;
typedef long long ll;

int n;
int x11, x22, x12, x21, y11, y22, y12, y21;

void solve1() {
   int lo = 1, hi = n;
   while(lo < hi) {
      int mid = (lo + hi) / 2;
      cout << "? " << 1 << " " << 1 << " " << mid << " " << n << endl;
      int x; cin >> x;
      if(x == 0) lo = mid + 1;
      else hi = mid;
   }
   x12 = lo;
}
void solve2() {
   int lo = 1, hi = n;
   while(lo < hi) {
      int mid = (lo + hi) / 2;
      cout << "? " << 1 << " " << 1 << " " << mid << " " << n << endl;
      int x; cin >> x;
      if(x != 2) lo = mid + 1;
      else hi = mid;
   }
   x22 = lo;
}
void solve3() {
   int lo = 1, hi = n;
   while(lo < hi) {
      int mid = (lo + hi) / 2;
      cout << "? " << 1 << " " << 1 << " " << n << " " << mid << endl;
      int x; cin >> x;
      if(x == 0) lo = mid + 1;
      else hi = mid;
   }
   y12 = lo;
}
void solve4() {
   int lo = 1, hi = n;
   while(lo < hi) {
      int mid = (lo + hi) / 2;
      cout << "? " << 1 << " " << 1 << " " << n << " " << mid << endl;
      int x; cin >> x;
      if(x != 2) lo = mid + 1;
      else hi = mid;
   }
   y22 = lo;
}
void solve5() {
   int lo = 1, hi = n;
   while(lo < hi) {
      int mid = (lo + hi + 1) / 2;
      cout << "? " << mid << " " << 1 << " " << n << " " << n << endl;
      int x; cin >> x;
      if(x == 0) hi = mid - 1;
      else lo = mid;
   }
   x11 = lo;
}
void solve6() {
   int lo = 1, hi = n;
   while(lo < hi) {
      int mid = (lo + hi + 1) / 2;
      cout << "? " << mid << " " << 1 << " " << n << " " << n << endl;
      int x; cin >> x;
      if(x != 2) hi = mid - 1;
      else lo = mid;
   }
   x21 = lo;
}
void solve7() {
   int lo = 1, hi = n;
   while(lo < hi) {
      int mid = (lo + hi + 1) / 2;
      cout << "? " << 1 << " " << mid << " " << n << " " << n << endl;
      int x; cin >> x;
      if(x == 0) hi = mid - 1;
      else lo = mid;
   }
   y11 = lo;
}
void solve8() {
   int lo = 1, hi = n;
   while(lo < hi) {
      int mid = (lo + hi + 1) / 2;
      cout << "? " << 1 << " " << mid << " " << n << " " << n << endl;
      int x; cin >> x;
      if(x != 2) hi = mid - 1;
      else lo = mid;
   }
   y21 = lo;
}

void rek5() {
   if(x11 > x12 || x21 > x22 || y11 > y12 || y21 > y22) return;
   cout << "? " << x11 << " " << y11 << " " << x12 << " " << y12 << endl;
   int x; cin >> x;
   cout << "? " << x21 << " " << y21 << " " << x22 << " " << y22 << endl;
   int y; cin >> y;
   if(x == 1 && y == 1) {
      cout << "! " << x11 << " " << y11 << " " << x12 << " " << y12 << " " << x21 << " " << y21 << " " << x22 << " " << y22 << endl;
      exit(0);
   }
}
void rek4() {
   rek5();
   swap(y12, y22);
   rek5();
}
void rek3() {
   rek4();
   swap(y11, y21);
   rek4();
}
void rek2() {
   rek3();
   swap(x22, x12);
   rek3();
}
void rek1() {
   rek2();
   swap(x11, x21);
   rek2();
}


int main() {
   cin >> n;
   solve1();
   solve2();
   solve3();
   solve4();
   solve5();
   solve6();
   solve7();
   solve8();
   rek1();
}