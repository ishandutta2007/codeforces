#include <bits/stdc++.h>
using namespace std;
#define int long long
bool has(string s, char ch){
    bool f = false;
    for(char nxt: s){
        if(nxt==ch)f = true;
    }
    return f;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        string t;
        cin >> t;
        if(t=="a"){
            cout << "1\n";
        }
        else if(has(t,'a')){
            cout << "-1\n";
        }
        else{
            int v = count(s.begin(),s.end(),'a');
            cout << (1LL<<v) << "\n";
        }
    }
    return 0;
}