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
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s == "0"){
        cout << "0" << endl;
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans += s[i] == '0' ? 1 : 0;
    }
    cout << "1" << string(ans, '0') << endl;


}