#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int v = (s[0]-'a')*25;
        v+=s[1]-'a'+1;
        if(s[1]>s[0])v--;
        cout << v << "\n";
    }
    return 0;
}