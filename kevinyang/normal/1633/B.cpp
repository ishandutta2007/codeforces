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
        int a = count(s.begin(),s.end(),'0');
        int b = s.length()-a;
        if(a==b){
            cout << a-1 << "\n";
        }
        else{
            cout << min(a,b) << "\n";
        }
    }
    return 0;
}