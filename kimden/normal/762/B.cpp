#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

//const ld eps = 1e-8;
const ll mod = 1000000007;
//const int MAXN = 100002;



int main() {
    ios_base::sync_with_stdio(false);
    ll a, b, c;
    ll n, m;
    vector<ll> v, w;
    cin >> a >> b >> c;
    cin >> m;
    ll q;
    string s;
    for(int i = 0; i < m; i++){
        cin >> q >> s;
        if(s == "USB"){
            v.push_back(q);
        }else if(s == "PS/2"){
            w.push_back(q);
        }
    }
    n = v.size();
    m = w.size();
    ll ans = 0;
    ll comp = 0;
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    int i1 = 0, i2 = 0;
    ll delta = 0;
    for(; i1 < min(a, n); i1++){
        ans += v[i1];
        comp++;
        delta++;
    }
    a -= delta;
    n -= delta;
    delta = 0;
    for(; i2 < min(b, m); i2++){
        ans += w[i2];
        comp++;
        delta++;
    }
    a -= delta;
    n -= delta;
    delta = 0;
    delta = min(n + m, c);
    v.push_back(mod);
    w.push_back(mod);
    comp += delta;
    for(int i = 0; i < delta; i++){
        if(v[i1] < w[i2]){
            ans += v[i1++];
        }else{
            ans += w[i2++];
        }
    }
    cout << comp << " " << ans << endl;


    return 0;
}