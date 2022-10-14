#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

ll cts[200];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T; cin >> T;
    while(T--) {
        string p, h;
        cin >> p >> h;
        if(p == "") {
            cout << "YES" << endl;
            continue;
        }
        for(ll i = 0; i < 200; i++) cts[i] = 0;
        for(char c : p) cts[c]++;
        bool works = false;
        for(ll i = 0; i < h.size(); i++) {
            cts[h[i]]--;
            if(i >= p.size()) cts[h[i - p.size()]]++;
            bool temp = true;
            for(ll c : cts) if(c) temp = false;
            if(temp) works = true;
        }
        cout << (works ? "YES" : "NO") << endl;
    }
}