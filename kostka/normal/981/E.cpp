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

const int N = 10007;
const int DRZ = 1<<14;

int op, ok, oile;
vi D[2*DRZ];
bitset <N> pos[2*DRZ];

void zmien(int gdz, int p, int k) {
  if(op<=p && k<=ok) {
    D[gdz].push_back(oile);
    return;
  }
  int m=(p+k)/2;
  if(op<m) zmien(2*gdz,p,m);
  if(ok>m) zmien(2*gdz+1,m,k);
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  while(q--) {
    cin >> op >> ok >> oile;
    ok++;
    zmien(1,0,DRZ);
  }
  pos[1][0] = true;
  for(int i=1; i<DRZ; i++) {
    for(auto d : D[i]) {
      pos[i] |= (pos[i] << d);
    }
    pos[2*i] = pos[i];
    pos[2*i+1] = pos[i];
  }
  bitset<N> ret;
  for(int i=DRZ; i<2*DRZ; i++) {
    for(auto d : D[i]) {
      pos[i] |= (pos[i] << d);
    }
    ret |= pos[i];
  }
  // cout << ans.count() << "\n";
  int ccc = 0;
  for(int i=1; i<=n; i++) if(ret[i]) ccc++;
  cout << ccc << "\n";
  for(int i=1; i<=n; i++) if(ret[i]) cout << i << " ";
  cout << "\n";
  return 0;
}

/*
10000 3
1 10000 10000
1 10000 9999
1 10000 2
*/