#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
const ll mod = 1000000007;
int n; string s[1005];
int cnt[27]; bool x;

int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n; x = 1;
        for(int i = 1; i <= 26; i++){
             cnt[i] = 0;
        }
        for(int i = 1; i <= n; i++){
             cin >> s[i];
             for(int j = 0; j < s[i].length(); j++){
                 cnt[s[i][j] - 96]++;
             }
        }
        for(int i = 1; i <= 26; i++){
            if(cnt[i] % n){
                x = 0; cout << "NO"; break;
            }
        }
        if(x){
            cout << "YES";
        }
        cout << "\n";
    }
}