#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef string str;

ll T;
ll N, K;
string s;

int main(){
    cin >> T;
    while(T--){
        cin >>N >> K;
        vector<int> lol(30,0);
        cin >> s;
        sort(s.begin(), s.end());
        for(int i = 0; i < N; i++) lol[s[i]-'a']++;
        ll sos = 0; for(auto x: lol)if(x>0)sos++;
        if (K == 1){
          cout << s << "\n";
          continue;
        }
        vector<string> sess(K);
        int i = 1, j = 1, conta = 0;
        bool lel = 0;
        sess[0] += s[0];
        while (j < K){
          sess[j] += s[i];
          j = (j+1);
          i++;
        }
        if (sess[K-1] != sess[0]){
          cout << sess[K-1] << "\n";
          lel = true;
        }
        if (!lel){
          if (sos > 2 || (sos == 2 && s[i] == s[i-1])){
            cout << sess[0];
            for(int e = i; e < N; e++) cout << s[e];
            cout << "\n";
          }

          else{
            j = j%K;
            while (i < N){
              sess[j] += s[i];
              j = (j+1)%K;
              i++;
            }
            sort(sess.rbegin(), sess.rend());
            cout << sess[0] << "\n";
          }
        }
    }
    return 0;
}