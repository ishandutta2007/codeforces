#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        char ch = 'a';
        for(char nxt: s){
            ch = max(ch,nxt);
        }
        cout << ch-'a'+1 << "\n";
    }
    return 0;
}