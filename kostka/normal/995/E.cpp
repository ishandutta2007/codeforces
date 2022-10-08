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

const int STEPS = 50;

int pot(int a, int b, int m) {
  if(b==0) return 1;
  int p = pot(a, b/2, m);
  int p2 = (1LL*p*p)%m;
  if(b%2) return (1LL*p2*a)%m;
  else return p2;
}

int odw(int a, int p, int e) {
  if(e == 1) return pot(a, p-2, p);
  else return pot(a, p-2, p);
}

map <int, pair <int, int> > mov[2];
int p;

void go(int e, int a, int steps) {
  if(steps == 0) return;
  vector <int> pos = {a-1, odw(a, p, e), a+1};
  for(int i=-1; i<=1; i++) {
    int q = (pos[i+1]%p+p)%p;
    if(mov[e].find(q) == mov[e].end()) {
      mov[e][q] = {i, a};
      go(e, q, steps-1);
    }
  }
}

map <int, int> CODE = {{1, 1}, {-1, 2}, {0, 3}};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  assert(odw(3, 5, 0) == 2);
  assert(odw(2, 5, 1) == 3);
  int u, v;
  cin >> u >> v >> p;
  if(u == v) {
    cout << "0\n\n";
    return 0;
  }
  mov[0][u] = {-7, -7};
  mov[1][v] = {-8, -8};
  go(0, u, STEPS);
  go(1, v, STEPS);
  vi E1, E2;
  for(auto e1 : mov[0]) E1.push_back(e1.x);
  for(auto e2 : mov[1]) E2.push_back(e2.x);
  sort(E1.begin(), E1.end());
  sort(E2.begin(), E2.end());
  for(auto e1 : E1) {
    auto e21 = lower_bound(E2.begin(), E2.end(), e1);
    vector <int> PP = {*e21};
    if(e21 != E2.begin()) {
      e21--;
      PP.push_back(*e21);
    }
    for(auto e2 : PP) {
      if(abs(e1 - e2) <= 200-STEPS-STEPS-2) {
        vi D1, D2;
        int f1 = e1;
        int f2 = e2;
        // cerr << f1 << " " << f2 << "\n";
        while(mov[0][f1].x != -7) {
          // cerr << "F1 " << f1 << "\n";
          D1.push_back(mov[0][f1].x);
          f1 = mov[0][f1].y;
        }
        while(mov[1][f2].x != -8) {
          // cerr << "F2 " << f2 << "\n";
          D2.push_back(mov[1][f2].x);
          f2 = mov[1][f2].y;
        }
        // cerr << f1 << " " << f2 << "\n";
        reverse(D1.begin(), D1.end());
        for(auto& d : D2) d *= -1;
        // for(auto d : D1) cerr << d << " ";
        // cerr << "\n";
        // for(auto d : D2) cerr << d << " ";
        // cerr << "\n";
        vi D3;
        // cerr << f1 << " " << f2 << "\n";
        f1 = e1;
        f2 = e2;
        while(f1 > f2) {
          D3.push_back(-1);
          f1--;
        }
        while(f1 < f2) {
          D3.push_back(1);
          f1++;
        }
        cout << SZ(D1) + SZ(D2) + SZ(D3) << "\n";
        for(auto d : D1) cout << CODE[d] << " ";
        for(auto d : D3) cout << CODE[d] << " ";
        for(auto d : D2) cout << CODE[d] << " ";
        cout << "\n";
        return 0;
      }
    }
  }
  assert(false);
  return 0;
}