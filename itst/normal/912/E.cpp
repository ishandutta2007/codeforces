#include<bits/stdc++.h>
#define int long long
using namespace std;

int ans1[10000001] , ans2[10000001] , num1[9] , num2[9] , N , K , cnt1 , cnt2;

void dfs1(int num , int ans){
  if(num == N / 2){
    ans1[++cnt1] = ans;
    return;
  }
  dfs1(num + 1 , ans);
  while(1e18 / ans >= num1[num]){
    ans *= num1[num];
    dfs1(num + 1 , ans);
  }
}

void dfs2(int num , int ans){
  if(num == N - N / 2){
    ans2[++cnt2] = ans;
    return;
  }
  dfs2(num + 1 , ans);
  while(1e18 / ans >= num2[num]){
    ans *= num2[num];
    dfs2(num + 1 , ans);
  }
}

inline bool check(int dir){
  int p = cnt2 , ans = 0;
  for(int i = 1 ; i <= cnt1 && p ; i++){
    while(p != 0 && (long double)ans1[i] * ans2[p] - 1e-8 > dir)
      p--;
    if((ans += p) >= K)
      return 1;
  }
  return 0;
}

main(){
  cin >> N;
  for(int i = 0 ; i < N / 2 ; i++)
    cin >> num1[i];
  for(int i = 0 ; i < N - N / 2 ; i++)
    cin >> num2[i];
  cin >> K;
  dfs1(0,1);
  dfs2(0,1);
  sort(ans1 + 1 , ans1 + cnt1 + 1);
  sort(ans2 + 1 , ans2 + cnt2 + 1);
  int L = 0 , R = 1e18;
  while(L < R){
    int mid = L + R >> 1;
    if(check(mid))
      R = mid;
    else
      L = mid + 1;
  }
  cout << L;
  return 0;
}