#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> e[N];
int n, lc[2], rc[N];

void f(int x, int y, int c){
  if(e[x].size() == 1){
    lc[c] = 1;
    rc[e[x][0]]++;
  }
  for(int i : e[x]) if(i != y) f(i, x, !c);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n - 1; i++){
    int x, y;
    cin >> x >> y;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  f(1, 0, 1);
  if(lc[0] && lc[1]) cout << "3 ";
  else cout << "1 ";
  int r = n - 1;
  for(int i = 1; i <= n; i++) r -= max(0, rc[i] - 1);
  cout << r << '\n';
}