//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 500007, MAXM = 500007;

struct krawedz {
  int a, b, wag, nr;
};

bool odp[MAXN], ans[MAXN];
int rep[MAXN], ile[MAXN], ktory[MAXN];
vector <int> kraw[MAXN];
vector <int> wagi_kraw[MAXN], wagi_zap[MAXN];
vector <pair <int, int> > UF;
// map <int, int> wag_ile;

vector <krawedz> E;

bool cmpwag(const krawedz& p, const krawedz& q) {
  return p.wag < q.wag;
}

bool cmpnr(const krawedz& p, const krawedz& q) {
  return p.nr < q.nr;
}

int find(int v, bool sklej = false) {
  if(sklej) return rep[v] = rep[v] == v ? v : find(rep[v]);
  return rep[v]==v ? v : find(rep[v]);
}

void unia(int& a, int& b) {
  if(ile[b]>ile[a]) swap(a,b);
  rep[b] = a;
  ile[a] += ile[b];
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i=1; i<=n; i++) rep[i] = i;
  for(int i=1; i<=n; i++) ile[i] = 1;
  for(int i=0; i<m; i++) {
    krawedz tmp;
    cin >> tmp.a >> tmp.b >> tmp.wag;
    tmp.nr = i;
    //if(tmp.wag > 4) continue;
    E.push_back(tmp);
    wagi_kraw[tmp.wag].push_back(i);
  }
  for(int i=1; i<=n; i++) {
    rep[i] = i;
    ile[i] = 1;
  }
  int q;
  cin >> q;
  for(int qq=0; qq<q; qq++) {
    int k;
    cin >> k;
    for(int i=0; i<k; i++) {
      int e;
      cin >> e;
      kraw[qq].push_back(e-1);
    }
    sort(kraw[qq].begin(), kraw[qq].end(), [&](const int& a, const int& b) {
      return E[a].wag < E[b].wag;
    });
    //for(auto k : kraw[qq]) cerr << k << " ";
    //cerr << "\n";
    wagi_zap[E[kraw[qq][0]].wag].push_back(qq);
    for(int i=1; i<k; i++) {
      if(E[kraw[qq][i]].wag != E[kraw[qq][i-1]].wag) {
        wagi_zap[E[kraw[qq][i]].wag].push_back(qq);
      }
    }
  }
  for(int w=1; w<MAXN; w++) {
    if(wagi_kraw[w].empty()) continue;
    //cerr << "W" << w << "\n";
    for(auto z : wagi_zap[w]) {
      if(ans[z] == true) continue;
      //cerr << "Z" << z << "\n";
      UF.clear();
      while(ktory[z]<(int)kraw[z].size() and E[kraw[z][ktory[z]]].wag == w) {
        int fa = find(E[kraw[z][ktory[z]]].a), fb = find(E[kraw[z][ktory[z]]].b);
        //for(int i=1; i<=n; i++) cerr << "F: " << i << " " << find(i) << "\n";
        //cerr << "\n";
        //cerr << "KRA" << E[kraw[z][ktory[z]]].a << " " << E[kraw[z][ktory[z]]].b << "\n";
        //cerr << "F" << fa << " " << fb << "\n";
        if(fa == fb) {
          //cerr << "KRAW" << kraw[z][ktory[z]] << "\n";
          //cerr << "Z" << z << " " << w << "\n";
          ans[z] = true;
          break;
        } else {
          unia(fa, fb);
          UF.emplace_back(fa, fb);
        }
        ktory[z]++;
      }
      reverse(UF.begin(), UF.end());
      for(auto u : UF) {
        //cerr << "COFNIJ " << u.first << " " << u.second << "\n";
        rep[u.second] = u.second;
        ile[u.first] -= ile[u.second];
      }
    }
    for(auto e : wagi_kraw[w]) {
      int fa = find(E[e].a, true), fb = find(E[e].b, true);
      if(fa != fb) {
        unia(fa, fb);
        //cerr << "U" << fa << " " << fb << "\n";
      }
    }
  }
  for(int qq=0; qq<q; qq++) cout << (!ans[qq] ? "YES" : "NO") << "\n";
  return 0;
}