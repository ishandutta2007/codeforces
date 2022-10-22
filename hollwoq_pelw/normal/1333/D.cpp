#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <map>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
int const nmax = 3000;
char v[1 + nmax];

vector<int> processlevel(int n){
  vector<int> sol;
  for(int i = 1;i < n; i++)
    if(v[i] == 'R' && v[i + 1] == 'L')
      sol.push_back(i);
  for(int i = 0; i < sol.size(); i++)
    swap(v[sol[i]], v[sol[i] + 1]);
  return sol;
}

int main()
{
  int n, k;
  cin >> n >> k;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  vector<vector<int>> solbig;
  int movesmax = 0;
  while(true){
    vector<int> sol = processlevel(n);
    if(sol.size() == 0)
      break;
    movesmax += sol.size();
    solbig.push_back(sol);
  }
  if(k < solbig.size() || movesmax < k){
    cout << -1;
    return 0;
  }
  int ptr = 0, movesmin = solbig.size();

  while(movesmin < k){
    if(solbig[ptr].size() == 0) {
      ptr++;
      movesmin--;
    }
    cout << 1 << " " << solbig[ptr].back() << '\n';
    solbig[ptr].pop_back();
    k--;
    if(solbig[ptr].size() == 0) {
      ptr++;
      movesmin--;
    }
  }

  for(int i = ptr; i < solbig.size(); i++){
    cout << solbig[i].size() << " ";
    for(int j = 0; j < solbig[i].size(); j++)
      cout << solbig[i][j] << " ";
    cout << '\n';
  }

  return 0;
}