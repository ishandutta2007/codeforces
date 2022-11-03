#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    map<char, int> mp;
    int ans = 0;
    mp['.'] = 0;
    mp['Q'] = 9;
    mp['R'] = 5;
    mp['B'] = 3;
    mp['N'] = 3;
    mp['P'] = 1;
    mp['K'] = 0;
    mp['q'] = -9;
    mp['r'] = -5;
    mp['b'] = -3;
    mp['n'] = -3;
    mp['p'] = -1;
    mp['k'] = 0;
    string s;
    for(int i = 0; i < 8; ++i){
        cin >> s;
        for(int j = 0; j < 8; ++j){
            ans += mp[s[j]];
        }
    }
    if(ans > 0){
        cout << "White" << endl;
    }else if(ans < 0){
        cout << "Black" << endl;
    }else{
        cout << "Draw" << endl;
    }
}