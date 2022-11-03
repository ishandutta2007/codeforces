#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ll L, R;
ll n, k;
mt19937 mt(time(nullptr));

int query(ll x, ll y){
    cout << x << " " << y << endl;
    string s;
    cin >> s;
    if(s == "Bad"){
        exit(0);
    }
    if(s == "Yes"){
        return 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    L = 1;
    R = n;
    ll mid;
    while(R - L > (k << 2LL)){
        L = max(1LL, L - k);
        R = min(n, R + k);
        mid = (L + R) >> 1LL;
        if(query(L, mid)){
            if(L == mid){
                return 0;
            }
            R = mid;
        }else{
            L = mid + 1;
        }
    }
    while(1){
        L = max(1LL, L - k);
        R = min(n, R + k);
        mid = mt() % (R - L + 1) + L;
        if(query(mid, mid)){
            return 0;
        }
        if(R - L > (k << 2LL)){
            L = max(1LL, L - k);
            R = min(n, R + k);
            mid = (L + R) >> 1LL;
            if(query(L, mid)){
                if(L == mid){
                    return 0;
                }
                R = mid;
            }else{
                L = mid + 1;
            }
        }
    }


    return 0;
}