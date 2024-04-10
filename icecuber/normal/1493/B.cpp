#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mirror1(int a) {
  if (set<int>({0,1,8}).count(a)) return a;
  else if (set<int>({2,5}).count(a)) return a^2^5;
  else return 1e6;
}
int mirror(int a) {
  return mirror1(a%10)*10+mirror1(a/10);
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int A, B;
    cin >> A >> B;
    int a, b;
    char c;
    cin >> a >> c >> b;
    assert(c == ':');

    while (1) {
      int ma = mirror(a);
      int mb = mirror(b);
      if (ma < B && mb < A) break;
      if (++b == B) {
        if (++a == A) a = 0;
        b = 0;
      }
    }
    printf("%02d:%02d\n", a, b);
  }
}