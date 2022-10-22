#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
vector<vector<int>> step;
int n, k;
ll mask;
vector<ll> stepmask;
 
void rec(ll qs, ll os, int ind) {
  ll zs = ~os & mask & ~qs;
  if (ind == k) {
    if ((qs&(qs>>1)) || 
        (os&((qs|zs)>>1)) || 
        ((zs>>1)&(qs|os))) {
      cout << "REJECTED" << endl;
      exit(0);
    }
    return;
  }
 
  int Qs = __builtin_popcountll(stepmask[ind]&qs); 
  int Zs = __builtin_popcountll(stepmask[ind]&zs);
 
  ll nqs = qs & ~stepmask[ind], nos = os & ~stepmask[ind];
  for (int i = Zs; i < (int)step[ind].size(); i++) {
    int s = step[ind][i];
    nos |= 1ll<<s;
  }
  for (int x = 0; x <= Qs; x++) {
    rec(nqs, nos, ind+1);
    if (x < Qs)
      nos ^= 1ll<<step[ind][Zs+x];
  }
}
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  mask = (1ll<<n)-1;
  step.resize(k);
  stepmask.resize(k);
  for (int i = 0; i < k; i++) {
    int q;
    cin >> q;
    step[i].resize(q);
    for (int&v : step[i]) cin >> v, v--;
    for (int v : step[i]) stepmask[i] |= 1ll<<v;
  }
  rec(mask,0, 0);
  cout << "ACCEPTED" << endl;
}