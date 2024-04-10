#include <bits/stdc++.h>
using namespace std;

const int N = 1000005, M = int(1e9)+7;

int n, x;
char s[N];

void dp(int c){
  int t = s[c] - '1';
  int nn = n;
  while(t--){
    for(int i = c+1; i < nn; i++){
      if(n >= x) break;
      s[n++] = s[i];
    }
    if(n == x) break;
  }
}

void solve(){
  cin >> x >> s;
  n = strlen(s);
  int m = n;
  for(int i = 0; i < x; i++){
    dp(i);
    m = (1LL*m + 1LL*(s[i]-'1')*(m-(i+1)+M)) % M;
  }
  cout << m << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int t;
  cin >> t;
  while(t--) solve();
}