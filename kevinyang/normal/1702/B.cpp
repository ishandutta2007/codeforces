#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int cnt = 0;
        set<char>st;
        string s;
        cin >> s;
        for(char nxt: s){
            st.insert(nxt);
            if(st.size()==4){
                st.clear();
                st.insert(nxt);
                cnt++;
            }
        }
        if(st.size())cnt++;
        cout << cnt << "\n";
    }
    return 0;
}