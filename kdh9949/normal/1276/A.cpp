#include <bits/stdc++.h>
using namespace std;

const int N = 150005;

int n;
char s[N];
int t[N];

void solve(){
  cin >> s+1;
  n = strlen(s+1);
  vector<int> v;
  int j = 0;
  for(int i = 1; i <= n; i++){
    t[++j] = i;
    if(j >= 3 && s[t[j-2]] == 'o' && s[t[j-1]] == 'n' && s[t[j]] == 'e'){
      v.push_back(t[j-1]);
      t[j-1] = t[j];
      j--;
    }
    else if(j >= 3 && s[t[j-2]] == 't' && s[t[j-1]] == 'w' && s[t[j]] == 'o'){
      if(i < n && s[i+1] == 'n'){
        v.push_back(t[j]);
        j--;
      }
      else{
        v.push_back(t[j-1]);
        t[j-1] = t[j];
        j--;
      }
    }
  }
  cout << v.size() << '\n';
  for(int i : v) cout << i << ' ';
  cout << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--) solve();
}