#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Block {
  int cost[3][3];
  Block() {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        cost[i][j] = 0;
  }
  Block(char c) {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        cost[i][j] = 0;
    int i = c-'a';
    cost[i][i] = 1;
  }
};

Block operator+(Block a, Block b) {
  Block r;
  r.cost[0][0] = a.cost[0][0]+b.cost[0][0];
  r.cost[1][1] = a.cost[1][1]+b.cost[1][1];
  r.cost[2][2] = a.cost[2][2]+b.cost[2][2];
  r.cost[0][1] = min(a.cost[0][0]+b.cost[0][1], a.cost[0][1]+b.cost[1][1]);
  r.cost[1][2] = min(a.cost[1][1]+b.cost[1][2], a.cost[1][2]+b.cost[2][2]);
  r.cost[0][2] = min({a.cost[0][0]+b.cost[0][2], 
                      a.cost[0][1]+b.cost[1][2],
                      a.cost[0][2]+b.cost[2][2]});
  return r;
}

const int nax = 1<<17;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  string s;  
  cin >> s;

  vector<Block> tree(nax*2);
  for (int i = nax; i < nax+n; i++) {
    tree[i] = Block(s[i-nax]);
  }
  for (int i = nax-1; i; i--) {
    tree[i] = tree[i*2]+tree[i*2+1];
  }
  while (q--) {
    int p;
    char c;
    cin >> p >> c;
    p--;
    s[p] = c;
    tree[p+nax] = Block(c);
    for (int i = (p+nax)>>1; i; i >>= 1) {
      tree[i] = tree[i*2]+tree[i*2+1];
    }
    //cout << s << endl;
    //cout << (tree[nax+2]+tree[nax+3]+tree[nax+4]).cost[0][2] << endl;
    cout << tree[1].cost[0][2] << endl;
  }
}