#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;
ll s[105000];
ll e[105000];

bool f(int t, ll low, ll odd, ll even) {
    //cerr << t << " " << low << " " << odd << " " << even << endl;
    if(s[t] >= low) {
        if(s[t] & 1LL) {
            if(odd) {
                if(t == 0) {
                    return true;
                } else {
                    return f(t-1, e[t-1]/2+1, 1, 1);
                }
            } else {
                if(t == 0) {
                    return false;
                } else {
                    return f(t-1, e[t-1]/2+1, 1-(e[t-1]&1LL), (e[t-1]&1LL));
                }
            }
        } else {
            if(even) {
                if(t == 0) {
                    return true;
                } else {
                    return f(t-1, e[t-1]/2+1, 1, 1);
                }
            } else {
                if(t == 0) {
                    return false;
                } else {
                    return f(t-1, e[t-1]/2+1, 1-(e[t-1]&1LL), (e[t-1]&1LL));
                }
            }
        }
    }
    ll newlow = (low + 1) / 2;
    if(!even) {
        return f(t, newlow, 1, 1);
    } else {
        ll neweven;
        ll newodd;
        if(low % 2 == 1) {
            if(odd) {
                neweven = 0;
                newodd = 1;
            } else {
                neweven = 1;
                newodd = 0;
            }
        } else {
            if(even) {
                newodd = 0;
                neweven = 1;
            } else {
                newodd = 1;
                neweven = 0;
            }
        }
        return f(t, newlow, newodd, neweven);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    for(int i = 0; i < T; i++) cin >> s[i] >> e[i];
    cout << f(T-1, e[T-1]/2+1, 1-(e[T-1]&1LL), (e[T-1]&1LL));
    cout << " ";
    cout << f(T-1, e[T-1]/2+1, 1, 1);
    cout << endl;
    return 0;
}