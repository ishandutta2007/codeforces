#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    for(cin >> T; T; T -= 1){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int& x : a) cin >> x;
        vector<int> s;
        for(int x : a){
            if(x == 1) s.push_back(x);
            else{
                while(s.back() + 1 != x) s.pop_back();
                s.back() = x;
            }
            for(int i = 0; i < (int)s.size(); i += 1){
                if(i) cout << '.';
                cout << s[i];
            }
            cout << "\n";
        }
    }
    return 0;
}