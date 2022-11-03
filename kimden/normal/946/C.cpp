#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    string s;
    cin >> s;
    char x = 'a';
    int n = s.length();
    for(int i = 0; i < n; ++i){
        if(s[i] <= x){
            s[i] = x;
            ++x;
        }
        if((int)x == 1 + (int)'z'){
            break;
        }
    }
    if((int)x != 1 + (int)'z'){
        cout << -1 << endl;
        return 0;
    }
    cout << s << endl;



}