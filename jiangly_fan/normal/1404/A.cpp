#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 300000 + 1;
char s[maxn + 2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, k;
        cin >> n >> k >> s;
        int ok = 1;
        for(int i = 0; i < n; i += 1)
            if(s[i] == '?' and s[i % k] == '?') continue;
            else if(s[i] == '?')s[i] = s[i % k];
            else if(s[i % k] == '?') s[i % k] = s[i];
            else if(s[i] != s[i % k]) ok = 0;
        int cnt[2] = {0, 0};
        for(int i = 0; i < k; i += 1) if(s[i] != '?') cnt[s[i] - '0'] += 1;
        cout << (ok and cnt[0] <= k / 2 and cnt[1] <= k / 2 ? "YES\n" : "NO\n");
    }
    return 0;
}