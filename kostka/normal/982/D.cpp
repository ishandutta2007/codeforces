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

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vi A(n+7);
  for(int i=1; i<=n; i++) cin >> A[i];
  vi B(n);
  for(int i=1; i<=n; i++) B[i-1] = i;
  sort(B.begin(), B.end(), [&](int a, int b){
    return A[a] > A[b];
  });
  set <int> G, S;
  multiset <int> O;
  G.insert(0);
  G.insert(n+1);
  O.insert(n+1);
  int ret = A[B[0]]+1, loc = 1;
  for(int bb=0; bb<n; bb++) {
    int b = B[bb];
    auto jt = G.upper_bound(b);
    auto it = prev(jt);
    int dif = (*jt - *it);
    O.erase(O.find(dif));
    int p = (*jt - b);
    int q = (b - *it);
    if(p!=1) O.insert(p);
    if(q!=1) O.insert(q);
    if((O.empty() or *O.begin() == *O.rbegin()) and loc <= SZ(O)) {
      loc = SZ(O);
      ret = A[B[bb+1]]+1;
    }
    G.insert(b);
  }
  cout << ret << "\n";
  return 0;
}