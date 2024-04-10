#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll bit[100005];
const int BMAX = 100000;

void addbit(int x, ll val){
    while(x <= BMAX){
        bit[x] = max(bit[x], val);
        x += x & -x;
    }
}

ll getbit(int x){
    ll res = 0;
    while(x){
        res = max(res, bit[x]);
        x -= x & -x;
    }
    return res;
}

int gde[100005];
int r[100005];
ll h[100005];
vector <pair <ll, int>> vec;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    ll res = 0;
    for(int i=1; i<=n; i++){
        cin >> r[i] >> h[i];
        vec.push_back({h[i]*r[i]*r[i], i});
    }
    sort(vec.begin(), vec.end());
    int tr = 0;
    for(int i=0; i<vec.size(); i++){
        if(i == 0 || vec[i].first != vec[i-1].first) tr++;
        gde[vec[i].second] = tr;
    }
    for(int i=1; i<=n; i++){
        ll vol = h[i]*r[i]*r[i];
        ll mx = vol + getbit(gde[i] - 1);
        res = max(res, mx);
        addbit(gde[i], mx);
    }
    cout << res*acosl(-1);
    return 0;
}