#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    reverse(s.begin(),s.end());
    int ans = 0;
    for(int i = 0;i < y;i++){
        if(s[i]=='1'){
            ans++;
        }
    }
    if(s[y] == '0'){
        ans++;
    }
    for(int i = y + 1;i < x;i++){
        if(s[i]=='1'){
            ans++;
        }
    }
    cout << ans;



}