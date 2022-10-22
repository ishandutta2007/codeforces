#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll q, a[100], m, n, z;
    cin >> q; while(q--){
        cin >> n >> m;
        z = ((1ll << m) - n - 1) >> 1;
        for (ll i = 0; i < n; i++){
            string s; cin >> s;
            a[i] = stoll(s,nullptr,2);
        }
        sort(a,a+n);
        for (ll i = 0; i < n; i++){
            z += (a[i] <= z);
        }
        for (ll i = m-1; i >= 0; i--)
            cout << ((z >> i) & 1);
        cout << endl;
    }
}