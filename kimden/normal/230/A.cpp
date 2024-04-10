#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll x[1002], y[1002];

bool comp(int i, int j){
    if(x[i] == x[j]){
        return y[i] > y[j];
    }
    return x[i] < x[j];
}

int main() {
    ios_base::sync_with_stdio(false);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    ll s, n;
    cin >> s >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        v.push_back(i);
    }
    sort(v.begin(), v.end(), &comp);
    for(int i = 0; i < v.size(); i++){
        if(s <= x[v[i]]){
            cout << "NO" << endl;
            return 0;
        }
        s += y[v[i]];
    }
    cout << "YES" << endl;
    return 0;
}