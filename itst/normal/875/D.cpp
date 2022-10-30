#include<bits/stdc++.h>
#define MAXN 200010
#define int long long
using namespace std;

inline int read(){
  int a = 0;
  char c = getchar();
  while(!isdigit(c))
    c = getchar();
  while(isdigit(c)){
    a = (a << 3) + (a << 1) + (c ^ '0');
    c = getchar();
  }
  return a;
}

int lasApp[31] , ST[MAXN][20] , num[MAXN] , ansLeft[MAXN] , ansRight[MAXN] , N , ans;

inline int maxx(int a , int b){
  return num[a] > num[b] ? a : b;
}

inline int query(int a , int b){
  int t = log2(b - a + 1);
  return maxx(ST[a][t] , ST[b - (1 << t) + 1][t]);
}

void solve(int l , int r){
  if(l >= r)
    return;
  int dir = query(l , r) , L = ansLeft[dir] , R = ansRight[dir];
  if(L < l)
    L = l - 1;
  if(R > r)
    R = r + 1;
  ans += (L - l + 1) * (r - dir + 1) + (r - R + 1) * (dir - l + 1) - (L - l + 1) * (r - R + 1);
  solve(l , dir - 1);
  solve(dir + 1 , r);
}

main(){
  N = read();
  for(int i = 1 ; i <= N ; i++){
    num[i] = read();
    ST[i][0] = i;
    for(int j = 0 ; j <= 30 ; j++)
      if(num[i] & (1 << j))
	lasApp[j] = i;
      else
	ansLeft[i] = max(ansLeft[i] , lasApp[j]);
  }
  for(int i = 0 ; i <= 30 ; i++)
    lasApp[i] = N + 1;
  for(int i = N ; i ; i--){
    ansRight[i] = N + 1;
    for(int j = 0 ; j <= 30 ; j++)
      if(num[i] & (1 << j))
	lasApp[j] = i;
      else
	ansRight[i] = min(ansRight[i] , lasApp[j]);
  }
  for(int i = 1 ; 1 << i <= N ; i++)
    for(int j = 1 ; j + (1 << i) - 1 <= N ; j++)
      ST[j][i] = maxx(ST[j][i - 1] , ST[j + (1 << i - 1)][i - 1]);
  solve(1 , N);
  cout << ans;
  return 0;
}