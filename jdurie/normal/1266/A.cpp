#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T;
    cin >> T;
    while(T--) {
        string n;
        cin >> n;
        bool zer = false, ev = false;
        ll sum = 0;
        for(char c : n) {
            if(c == '0') {
                if(zer) ev = true;
                else zer = true;
            } else if((c - '0') % 2 == 0) ev = true;
            sum += c - '0';
        }
        cout << (zer && ev && (sum % 3 == 0) ? "red" : "cyan") << endl;
    }
}