#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h1,m1, h2,m2;
  char tmp1,tmp2;
  cin >> h1 >> tmp1 >> m1;
  cin >> h2 >> tmp2 >> m2;
  int t = ((h1+h2)*60+(m1+m2)>>1);
  printf("%02d:%02d\n",t/60,t%60);
}