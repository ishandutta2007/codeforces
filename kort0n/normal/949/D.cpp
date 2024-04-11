#include <bits/stdc++.h>
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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll N, D, B;
ll a[100500];
ll Right[100500];
ll Left[100500];

bool check(int mid) {
    //cerr << "----" << mid << "----" << endl;
    for(int timer = 1; ; timer++) {
        int room = timer + mid;
        //cerr << timer << " " << room << endl;
        if(room > (N + 1) / 2) break;
        if(Left[timer] - room > room * D) return false;
    }
    for(int timer = 1; ; timer++) {
        int room = N + 1 - timer - mid;
        if(room <= (N + 1) / 2) break;
        if(room - Right[timer] > (N + 1 - room) * D) return false;
    }
    return true;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> D >> B;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    ll index = 1;
    ll num = 0;
    for(int i = 1; i <= N; i++) {
        num += a[i];
        while(num >= B) {
            Left[index] = i;
            num -= B;
            index++;
        }
    }
    index = 1;
    num = 0;
    for(int i = N; i >= 1; i--) {
        num += a[i];
        while(num >= B) {
            Right[index] = i;
            num -= B;
            index++;
        }
    }
    /*
    for(int i = 1; i <= N; i++) {
        cerr << Left[i] << " ";
    }
    cerr << endl;
    for(int i = 1; i <= N; i++) {
        cerr << Right[i] << " ";
    }
    cerr << endl;
    */
    int ok = N / 2;
    int ng = -1;
    while(ok - ng > 1) {
        int mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}