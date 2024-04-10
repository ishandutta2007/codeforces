#include<bits/stdc++.h>
using namespace std;
using LL = long long;
LL cnt[26];
LL ans[26][26];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    for(char c : s){
        for(int i = 0; i < 26; i += 1) ans[i][c - 'a'] += cnt[i];
        cnt[c - 'a'] += 1;
    }
    LL x = 0;
    for(int i = 0; i < 26; i += 1){
        x = max(x, cnt[i]);
        for(int j = 0; j < 26; j += 1) x = max(x, ans[i][j]);
    }
    cout << x;
    return 0;
}