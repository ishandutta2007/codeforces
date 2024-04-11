//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())

string g0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string g1 = "What are you doing while sending \"";
string g2 = "\"? Are you busy? Will you send \"";
string g3 = "\"?";
long long f[100007];

char go(int n, long long k) {
  if(n == 0) {
    if(k < SZ(g0)) return g0[k];
    else return '.';
  }
  if(k < SZ(g1)) return g1[k];
  k -= SZ(g1);
  if(k < f[n-1]) return go(n-1, k);
  k -= f[n-1];
  if(k < SZ(g2)) return g2[k];
  k -= SZ(g2);
  if(k < f[n-1]) return go(n-1, k);
  k -= f[n-1];
  if(k < SZ(g3)) return g3[k];
  return '.';
}

char test() {
  int n;
  long long k;
  cin >> n >> k;
  return go(n, k-1);
}

int main()
{
  ios_base::sync_with_stdio(0);
  int q;
  cin >> q;
  f[0] = SZ(g0);
  for(int i=1; i<55; i++) {
    f[i] = SZ(g1) + f[i-1] + SZ(g2) + f[i-1] + SZ(g3);
  }
  for(int i=55; i<=100000; i++) {
    f[i] = f[i-1];
  }
  while(q--) {
    cout << test();
  }
  cout << "\n";
  return 0;
}