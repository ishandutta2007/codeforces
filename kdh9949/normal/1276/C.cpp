#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
#define x first
#define y second

const int N = 400005;

int n, a[N], c[N], k, ma, mb;
pii b[N];
vector<vector<int>> r;

int main(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for(int i = 0; i < n; i++){
    if(i && a[i-1] == a[i]) b[k].x++;
    else b[++k] = pii(1, a[i]);
  }
  sort(b + 1, b + k + 1);
  reverse(b + 1, b + k + 1);
  for(int i = 1, t = 0; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(b[j].x < i) break;
      a[t++] = b[j].y;
    }
    c[i] = t;
  }
  for(int i = 1; i * i <= n; i++){
    for(int j = i; i * j <= n; j++){
      if(c[i] >= i*j){
        if(i*j > ma*mb){
          ma = i; mb = j;
        }
      }
    }
  }
  sort(a, a + ma*mb);
  k = 0;
  for(int i = 0; i < ma*mb; i++){
    if(i && a[i-1] == a[i]) b[k].x++;
    else b[++k] = pii(1, a[i]);
  }
  sort(b + 1, b + k + 1);
  reverse(b + 1, b + k + 1);
  for(int i = 1, t = 0; i <= k; i++) while(b[i].x > 0){ a[t++] = b[i].y; b[i].x--; }
  for(int i = 0; i < ma; i++) r.push_back(vector<int>(mb));
  for(int i = 0, t = 0; i < mb; i++){
    for(int j = 0; j < ma; j++){
      r[j][(i+j)%mb] = a[t++];
    }
  }
  cout << ma*mb << '\n' << ma << ' ' << mb << '\n';
  for(int i = 0; i < ma; i++){
    for(int j = 0; j < mb; j++) cout << r[i][j] << ' ';
    cout << '\n';
  }
}