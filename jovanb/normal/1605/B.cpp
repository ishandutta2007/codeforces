#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector <int> vec;
        int cnt = 0;
        for(auto c : s) if(c == '0') cnt++;
        for(int i=1; i<=n; i++){
            if(s[i-1] == '0' && i > cnt) vec.push_back(i);
            if(s[i-1] == '1' && i <= cnt) vec.push_back(i);
        }
        if(vec.empty()){
            cout << "0\n";
            continue;
        }
        cout << "1\n";
        cout << vec.size() << " ";
        for(auto c : vec) cout << c << " ";
        cout << "\n";
    }
    return 0;
}