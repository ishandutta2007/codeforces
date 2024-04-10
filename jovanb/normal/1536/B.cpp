#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    queue <string> q;
    for(int i=0; i<26; i++){
        string t = "";
        t += 'a' + i;
        q.push(t);
    }
    while(!q.empty()){
        string g = q.front();
        q.pop();
        if(s.find(g) == string::npos){
            cout << g << "\n";
            return;
        }
        for(int i=0; i<26; i++){
            g += 'a' + i;
            q.push(g);
            g.pop_back();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}