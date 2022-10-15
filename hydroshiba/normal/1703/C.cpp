#include "bits/stdc++.h"
using namespace std;

int up(int num){
    if(num + 1 > 9) return 0;
    return num + 1;
}

int down(int num){
    if(num - 1 < 0) return 9;
    return num - 1;
}

void solve(){
    int n;
    cin >> n;

    vector<int> vec(n);
    for(int &i : vec) cin >> i;

    for(int i = 0; i < n; ++i){
        int m;
        cin >> m;

        string s;
        cin >> s;

        for(char c : s){
            if(c == 'D') vec[i] = up(vec[i]);
            else vec[i] = down(vec[i]);
        }
    }

    for(int i : vec) cout << i << ' ';
    cout << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}