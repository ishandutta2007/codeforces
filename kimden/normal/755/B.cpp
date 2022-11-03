#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using ull = unsigned long long;





int main() {
    int n;
    int m;
    cin >> n >> m;
    map<string, int> mp;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        mp[s] = 1;
    }
    int k = 0;
    for(int j = 0; j < m; j++){
        cin >> s;
        if(mp[s] == 1){
            k++;
        }
    }
    n -= k;
    m -= k;
    if(k % 2 == 0){
        if(n > m){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }else{
        if(n >= m){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}