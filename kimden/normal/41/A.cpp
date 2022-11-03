#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


int main() {
    ios_base::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    reverse(t.begin(), t.end());
    if(s == t){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}