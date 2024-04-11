#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a, b, cost = 0;
  cin >> n >> a >> b;
	vector<int> v;
  v.resize(n);
  for(auto& i : v) {
    cin >> i;
  }

  for(int i = 0;i < (n/2 + n%2); i++) {

    if(v[i] != v[n - i - 1] && v[i] != 2 && v[n - i - 1] != 2)
    {
      cout << -1;
      return 0;
    }

    if(v[i] == v[n - i - 1] && v[i] == 2) {
      if(i == (n - i - 1))
        cost += min(a, b);
      else
        cost += 2 * min(a, b);
    }else if(v[i] == 2 || v[n - i - 1] == 2) {
      if(v[i] == 1 || v[n - i - 1] == 1)
        cost += b;
      else
        cost += a;
    }
    
  }

cout << cost;

}