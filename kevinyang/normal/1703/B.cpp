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
        set<char>st;
        string s;
        cin >> s;
        for(char nxt: s){
            st.insert(nxt);
        }
        cout << s.size()+st.size() << "\n";
    }
    return 0;
}