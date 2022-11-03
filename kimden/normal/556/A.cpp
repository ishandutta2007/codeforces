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
    int n;
    string s;
    cin >> n;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == '0'){
            ++ans;
        }else{
            --ans;
        }
    }
    ans = abs(ans);
    cout << ans << endl;

}