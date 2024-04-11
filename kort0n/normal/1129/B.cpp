#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
ll k;
l_l diff(ll val) {
    for(ll i = 1; i <= 100; i++){
        if(val % i != 0) continue;
        ll sum = val / i;
        if(i * 1000000 < sum) continue;
        return {i, sum};
    }
    return {-1, -1};
} 

l_l diff2(ll val) {
    for(ll i = 1; i <= 1500; i += 2){
        if(val % i != 0) continue;
        ll a0 = val / i;
        ll an = a0 + i / 2;
        if(an > 1000000) continue;
        return {i, a0};
    }
    return {-1, -1};
}

int main() {
    //cout.precision(10);
    cin >> k;
    if(k <= 100000) {
        cout << 1 << endl;
        cout << -k << endl;
        return 0;
    }
    l_l ans1;
    l_l ans2;
    ll val = 1e7;
    while(true){
        val++;
        ans1 = diff(val);
        if(ans1.first == -1) continue;
        ans2 = diff2(val + k);
        if(ans2.first == -1) continue;
        //cout << ans1.first << " " << ans1.second << endl;
        //cout << ans2.first << " " << ans2.second << endl;
        break;
    }
    vector<ll> ANS1;
    for(int i = 1; i <= ans1.first; i++) {
        ll VALUE = 1000000;
        VALUE = min(ans1.second, VALUE);
        ANS1.push_back(VALUE);
        ans1.second -= VALUE;
    }
    vector<ll> ANS2;
    ANS2.push_back(ans2.second);
    for(ll i = 1; i <= ans2.first / 2; i++) {
        ll VALUE = ans2.second + i;
        ANS2.push_back(-VALUE);
        ANS2.push_back(VALUE);
    }
    ll ZERO = 2000 - ANS1.size() - ANS2.size();
    //cout << ANS1.size() << " " << ZERO << " " << ANS2.size() << endl;
    cout << 2000 << endl;
    for(int i = 0; i < ANS1.size(); i++) {
        cout << ANS1[i] << " ";
    }
    for(int i = 1; i <= ZERO; i++) {
        cout << "-1000000 ";
    }
    for(int i = 0; i < ANS2.size(); i++) {
        cout << ANS2[i] << " ";
    }
    cout << endl;
    return 0;
}