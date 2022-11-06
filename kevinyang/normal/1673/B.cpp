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
        set<char>st;
        for(char nxt: s){
            st.insert(nxt);
        }
        int v = st.size();
        bool f = true;
        for(int i = v; i<s.size(); i++){
            if(s[i]!=s[i-v]){
                f = false;
            }
        }
        cout << (f?"YES":"NO") << "\n";
    }
    return 0;
}