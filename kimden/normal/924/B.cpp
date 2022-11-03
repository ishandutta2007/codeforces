#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
    int n;
    ll u;
    cin >> n >> u;
    vector<ll> e(n);
    for(int i = 0; i < n; ++i){
        cin >> e[i];
    }
    int ptr1 = 0, ptr2 = 2;
    ld ans = 2;
    while(ptr1 < n - 1){
        while(ptr2 < n && e[ptr2] - e[ptr1] <= u){
            ++ptr2;
        }
        --ptr2;
        if(ptr2 - ptr1 >= 2){
            ans = min(ans, (e[ptr1 + 1] - e[ptr1]) / ld(e[ptr2] - e[ptr1]));
        }
        ++ptr1;
        ptr2 = max(ptr2, ptr1 + 2);
    }
    if(ans > 1.2){
        cout << -1 << endl;
        return 0;
    }
    cout << setprecision(15) << fixed << 1 - ans << endl;


}