#include <bits/stdc++.h>

#define fi first
#define se second
#define fo(i, a, b) for(int i = a; i <= b; i++)
#define pii pair<int, int>
using namespace std;
const int N = 210;

char s1[N], s2[N];
char s3[N], s4[N];

void solve() {
  cin >> s1 >> s2;
  int l1 = strlen(s1), l2 = strlen(s2);
  int t1 = 0, t2 = 0, sum1 = 0, sum2 = 0;
  fo(i, 0, l1 - 1) {
    if(s1[i] == 'B') sum1 ^= 1;
    else {
      if(t1 && s3[t1] == s1[i]) t1--;
      else s3[++t1] = s1[i];
    }
  }
  fo(i, 0, l2 - 1) {
    if(s2[i] == 'B') sum2 ^= 1;
    else {
      if(t2 && s4[t2] == s2[i]) t2--;
      else s4[++t2] = s2[i];
    }
  }
  if(sum1 != sum2 || t1 != t2 || (t1 > 0 && s3[1] != s4[1])) puts("NO");
  else puts("YES");
}

int main(){
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int T; cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}