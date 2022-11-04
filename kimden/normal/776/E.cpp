#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const ll N = 1000001;

vector<int> lp(N, -1);

ll phi(ll x){
    ll ans = x;
    for(int i = 2; i < N; ++i){
        int cnt = 0;
        while(x % i == 0){
            x /= i;
            ++cnt;
        }
        if(cnt){
            ans /= i;
            ans *= (i - 1);
        }
    }
    if(x > 1){
        ans /= x;
        ans *= (x - 1);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    for(ll i = 2; i < N; ++i){
        if(lp[i] == -1){
            lp[i] = i;
            for(ll j = i * i; j < N; j += i){
                if(lp[j] == -1){
                    lp[j] = i;
                }
            }
        }
    }
    ll n, k;
    cin >> n >> k;
    k = (k + 1) / 2;
    for(int i = 0; i < k && n > 1; ++i){
        n = phi(n);
    }
    cout << n % 1000000007 << endl;
}