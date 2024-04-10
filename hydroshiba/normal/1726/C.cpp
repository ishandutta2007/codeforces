#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n;
    cin >> n;

    n <<= 1;

    string s;
    cin >> s;

    queue<int> q;
    int depth = 0, num = 0, ans = 0;

    for(int i = 0; i < n; ++i){
        if(s[i] == '('){
            ++depth;
            num = 0;
        }
        else{
            --depth;
            ++num;
            if(num >= 2) ++ans;
        }
    }

    ++ans;
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}