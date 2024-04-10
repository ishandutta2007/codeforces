#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> vec;
  for(int i = 1; i <= n; i++){
    vec.push_back(1);
    while(vec.size() >= 2 && vec.back() == vec[vec.size() - 2]){
        int x = vec.back() + 1;
      vec.resize(vec.size() - 2);
      vec.push_back(x);
    }
  }
  for(int v : vec) cout << v << " ";
}