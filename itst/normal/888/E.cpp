#include<bits/stdc++.h>
using namespace std;

int cnt1 , cnt2 , N , M , num1[20] , num2[20] , ans1[300001] , ans2[300001];

void dfs1(int num , int mod){
  if(num == (N >> 1)){
    ans1[++cnt1] = mod;
    return;
  }
  dfs1(num + 1 , mod);
  dfs1(num + 1 , (mod + num1[num]) % M);
}

void dfs2(int num , int mod){
  if(num == N - (N >> 1)){
    ans2[++cnt2] = mod;
    return;
  }
  dfs2(num + 1 , mod);
  dfs2(num + 1 , (mod + num2[num]) % M);
}

int main(){
  cin >> N >> M;
  for(int i = 0 ; i < (N >> 1) ; i++)
    cin >> num1[i];
  dfs1(0,0);
  for(int i = 0 ; i < N - (N >> 1) ; i++)
    cin >> num2[i];
  dfs2(0,0);
  sort(ans1 + 1 , ans1 + cnt1 + 1);
  sort(ans2 + 1 , ans2 + cnt2 + 1);
  int dir = cnt2 , ans = 0;
  for(int i = 1 ; i <= cnt1 ; i++){
    while(dir > 0 && ans1[i] + ans2[dir] >= M)
      dir--;
    if(dir > 0)
      ans = max(ans , ans1[i] + ans2[dir]);
    else
      ans = max(ans , ans1[i] + ans2[cnt2] - M);
    while(i < cnt1 && ans1[i] == ans1[i + 1])
      i++;
  }
  cout << ans;
  return 0;
}