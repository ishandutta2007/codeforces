#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ld res;

ld eps = 0.000001;

void idi(int turns, ld c, ld m, ld v, ld prob){
    /// biram p
    res += (1-c-m)*prob;
    prob = prob*(turns+1)/turns;
    turns++;
    /// biram c
    if(c > 0){
        if(c >= v){
            if(m > eps) idi(turns, c-v, m+v/2, v, prob*c);
            else idi(turns, c-v, m, v, prob*c);
        }
        else{
            if(m > eps) idi(turns, 0, m+c/2, v, prob*c);
            else idi(turns, 0, m, v, prob*c);
        }
    }
    /// biram m
    if(m > 0){
        if(m >= v){
            if(c > eps) idi(turns, c+v/2, m-v, v, prob*m);
            else idi(turns, c, m-v, v, prob*m);
        }
        else{
            if(c > eps) idi(turns, c+m/2, 0, v, prob*m);
            else idi(turns, c, 0, v, prob*m);
        }
    }
}

void solve(){
    ld c, m, p, v;
    cin >> c >> m >> p >> v;
    res = 0;
    idi(1, c, m, v, 1);
    cout << res << "\n";
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


/*
1
0.4998 0.4998 0.0004 0.1666
*/