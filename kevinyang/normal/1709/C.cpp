#include <bits/stdc++.h>
using namespace std;
#define int long long
bool check(string s){
     if(s.size()%2==1){
            return false;
        }
        int cur = 0;
        bool f = true;
        for(int i = 0; i<s.size(); i++){
            if(s[i]==')')cur--;
            else cur++;
            if(cur<0)f = false;
        }
        return f;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int cur = 0;
        bool f = true;
        for(int i = 0; i<s.size(); i++){
            if(s[i]==')')cur--;
            else cur++;
            if(cur<0)f = false;
        }
        int n = s.size();
        int idx = 0;
        int cnt = count(s.begin(),s.end(),'?');
        if(cur==0||cur==cnt*2){
            cout << "YES\n";
            continue;
        }
        //cout << cur << " ";
        for(int i = n-1; i>=0; i--){
            if(s[i]=='?'&&cur){
                s[i] = ')';
                cur-=2;
                idx = i;
            }
        }
        s[idx] = '(';
        for(int i = idx; i>=0; i--){
            if(s[i]=='?'){
                s[i] = ')';
                break;
            }
        }
        //cout << s << " ";
        if(check(s)){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
    return 0;
}