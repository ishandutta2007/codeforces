#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        set<char> s;
        bool flag = false;
        for (auto c: a) s.insert(c);
        for (auto c: b){
            if (s.count(c)){
                flag = true;
            }
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}