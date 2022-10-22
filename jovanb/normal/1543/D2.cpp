#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 20000000;

int konstruisi(vector <int> p, int K){
    int res = 0, tr = 1;
    for(auto c : p){
        res += c*tr;
        tr *= K;
        if(tr > MAXN) break;
    }
    return res;
}

vector <int> dodaj(const vector <int> &a, const vector <int> &b, int k){
    vector <int> res;
    for(int i=0; i<a.size(); i++){
        res.push_back(a[i] + b[i]);
        if(res.back() >= k) res.back() -= k;
    }
    return res;
}

vector <int> oduzmi(const vector <int> &a, const vector <int> &b, int k){
    vector <int> res;
    for(int i=0; i<a.size(); i++){
        res.push_back(a[i] - b[i]);
        if(res.back() < 0) res.back() += k;
    }
    return res;
}

vector <int> convert(int x, int K, int sz){
    vector <int> res;
    for(int i=0; i<sz; i++){
        res.push_back(x%K);
        x /= K;
    }
    return res;
}

void solve(){
    int n, K;
    cin >> n >> K;
    int sz = 1;
    int trr = 1;
    while(trr < n){
        sz++;
        trr *= K;
    }
    vector <int> usta;
    for(int i=0; i<sz; i++) usta.push_back(0);
    for(int i=0; i<n; i++){
        vector <int> g = convert(i, K, sz);
        vector <int> kvr;
        if(i%2 == 0) kvr = dodaj(usta, g, K);
        else kvr = oduzmi(usta, g, K);
        cout << konstruisi(kvr, K) << endl;
        int x;
        cin >> x;
        if(x != 0) return;
        usta = oduzmi(kvr, usta, K);
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}