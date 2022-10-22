#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll eval(ll a, ll b, ll c){
    a /= 2;
    b /= 2;
    c /= 2;
    return (a-b)*(a-b) + (b-c)*(b-c) + (c-a)*(c-a);
}

ll uradi(vector <int> a, vector <int> b, vector <int> c){
    ll res = 2e18;
    int A = a.size();
    int B = b.size();
    int C = c.size();
    for(int i=0; i<A; i++){
        ll x = a[i];
        auto y = lower_bound(b.begin(), b.end(), x);
        if(y == b.end()) continue;
        auto z = lower_bound(c.begin(), c.end(), *y);
        if(z != c.end()){
            res = min(res, eval(x, *y, *z));
            //cout << x << " naso " << *y << " " << *z << endl;
        }
        ll jos = (x+(*y))/2;
        //cout << "gledam i " << jos << endl;
        auto z1 = lower_bound(c.begin(), c.end(), jos);
        if(z1 != c.end()) res = min(res, eval(x, *y, *z1));
        if(z1 != c.begin()){
            z1--;
            res = min(res, eval(x, *y, *z1));
        }
     }
    return res;
}

void solve(){
    int R, G, B;
    cin >> R >> G >> B;
    vector <int> r;
    for(int i=1; i<=R; i++){
        int x;
        cin >> x;
        x *= 2;
        r.push_back(x);
    }
    vector <int> g;
    for(int i=1; i<=G; i++){
        int x;
        cin >> x;
        x *= 2;
        g.push_back(x);
    }
    vector <int> b;
    for(int i=1; i<=B; i++){
        int x;
        cin >> x;
        x *= 2;
        b.push_back(x);
    }
    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());
    ll res = 2e18;
    res = min(res, uradi(r, g, b));
    res = min(res, uradi(r, b, g));
    res = min(res, uradi(b, g, r));
    res = min(res, uradi(b, r, g));
    res = min(res, uradi(g, r, b));
    res = min(res, uradi(g, b, r));
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

/*
1
3 4 1
1 2 3
3 3 4 7
6
*/
/*
1
2 2 2
1 2
3 4
6 7
*/