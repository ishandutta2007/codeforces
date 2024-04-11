#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

vector<ll> a;
ll n, k, A, B;
ll f(ll left, ll right) {
    //cout << left << " " << right << endl;
    ll number = distance(lower_bound(a.begin(), a.end(), right),  lower_bound(a.begin(), a.end(), left));
    number = -number;
    if(number == 0) return A;
    if((right - left) == 1) return B * number;
    ll now = number * (right - left) * B;
    ll LENGTH = right - left;
    LENGTH /= 2;
    return min(now, f(left, left + LENGTH) + f(left + LENGTH, right));
}


int main() {
    //cout.precision(10);
    cin >> n >> k >> A >> B;
    for(int i = 0; i < k; i++) {
        ll in;
        cin >> in;
        a.push_back(in);
    }
    sort(a.begin(), a.end());
    ll beki[35];
    beki[0] = 1;
    for(int i = 1; i <= 33; i++) {
        beki[i] = beki[i - 1] * 2;
    }
    cout << f(1, beki[n] + 1) << endl;
    return 0;
}