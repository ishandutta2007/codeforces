#include <bits/stdc++.h>
using namespace std;

deque<int> a, b;
vector<int> c, d;
string s;
int x, y;
int main(){
  cin >> s;
  int l = s.size(), r=0;
  for(int i=0;i<l;i++){
    if (s[i] == '(') a.push_back(i);
    else b.push_front(i);
  }
  a.push_back(l+1);
  b.push_back(-1);
  x = a.front(); y = b.front();
  while (x<y){
    c.push_back(x);
    d.push_back(y);
    a.pop_front(); b.pop_front();
    r++;
    x = a.front(); y = b.front();
  }
  if (r == 0) cout << 0 << "\n";
  else {
    printf("%d\n", 1);
    printf("%d\n", 2*r);
    for (int i=0;i<r;i++){
      printf("%d ", c[i]+1 );
    }
    for (int i=r-1;i>=0;i--){
      printf("%d ", d[i]+1);
    }
  }
  return 0;
}