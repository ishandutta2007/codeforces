#include <bits/stdc++.h>
using namespace std;
#define int long long
bool f(string s){
    set<char>st;
    for(char nxt: s){
        st.insert(nxt);
    }
    if(st.size()==1)return true;
    return false;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        string cur = "";
        bool flag = true;
        for(char nxt: s){
            if(nxt=='W'){
                if(f(cur)){
                    flag = false;
                }
                cur = "";
            }
            else{
                cur.push_back(nxt);
            }
        }
        if(f(cur)){
            flag = false;
        }
        if(flag)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}