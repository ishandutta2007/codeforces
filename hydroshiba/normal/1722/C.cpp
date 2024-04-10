#define x first
#define y second

#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

void solve(){
    int n; cin >> n;

    vector<string> a(n), b(n), c(n);
    map<string, int> cnt;


    for(string &s : a) cin >> s, ++cnt[s];
    for(string &s : b) cin >> s, ++cnt[s];
    for(string &s : c) cin >> s, ++cnt[s];

    int aa = 0, bb = 0, cc = 0;
    for(string s : a){
        if(cnt[s] == 1) aa += 3;
        else if(cnt[s] == 2) ++aa;
    }

    for(string s : b){
        if(cnt[s] == 1) bb += 3;
        else if(cnt[s] == 2) ++bb;
    }

    for(string s : c){
        if(cnt[s] == 1) cc += 3;
        else if(cnt[s] == 2) ++cc;
    }

    cout << aa << ' ' << bb << ' ' << cc << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}