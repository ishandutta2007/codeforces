

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
    unordered_map<string, int> mp;
    int n;
    cin >> n;
    string s;
    mp.reserve(n);
    for(int i = 0; i < n; ++i){
        cin >> s;
        int x = mp[s]++;
        if(x == 0){
            cout << "OK\n";
        }else{
            cout << s << x << "\n";
        }
    }



}