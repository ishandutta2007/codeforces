#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 500000;

int gr[N+5];

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int r = 0, b = 0;
    for(auto c : s){
        if(c == 'R') r++;
        else b++;
    }
    if(r > b){
        cout << "Alice\n";
        return;
    }
    if(b > r){
        cout << "Bob\n";
        return;
    }
    int tr = 0;
    vector <int> vec;
    for(int i=1; i<n; i++){
        if(s[i] != s[i-1]){
            tr++;
        }
        else{
            if(!tr) continue;
            vec.push_back(tr + 1);
            tr = 0;
        }
    }
    if(tr){
        vec.push_back(tr + 1);
    }
    int res = 0;
    for(auto c : vec){
        res ^= gr[c];
    }
    if(res) cout << "Alice\n";
    else cout << "Bob\n";
}

bool ima[N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    for(int i=2; i<=N; i++){
        if(i > 300){
            gr[i] = gr[i-34];
            continue;
        }
        for(int j=0; j<=i+1; j++) ima[j] = 0;
        for(int j=0; i-2-j>=j; j++){
            ima[gr[j] ^ gr[(i - 2 - j)]] = 1;
        }
        while(ima[gr[i]]) gr[i]++;
    }
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}