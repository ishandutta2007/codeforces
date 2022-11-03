#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    if(s != t){
        cout << max(s.length(), t.length()) << endl;
    }else{
        cout << -1 << endl;
    }
}