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

int T = 1;
ll N;

void solve(){
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i-1] || (i > 1 && s[i-2] == s[i])){
            s[i] = 'A'; ans++;
        }
    }
    cout << ans << "\n";
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}