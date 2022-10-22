#include<bits/stdc++.h>
using namespace std;

#define sadasdads long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n;
string s;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        bool lck = 0;
        cin >> s;
        n = s.size();
        s = "$" + s;
        bool chk = 0;
        for(int i = 2; i <= n; i++){
            if(s[i] != s[i - 1]) continue;
            else
            if(lck){
                if(s[i] == '0') chk = 1;
            }
            else{
                if(s[i] == '1') lck = 1;
            }
          //   if(o == 0){
          //       cout << lck << chk << endl;
          //   }
        }
        if(chk) cout << "NO";
        else cout << "YES";
        cout << endl;
    }
}