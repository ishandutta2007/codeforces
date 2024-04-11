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

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;
typedef pair<ll, vector<ll>> lv;
vector<ll> Prev, Next;
ll N, P, K;
vector<lv> a;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> P >> K;
    int NEET = N - P - K;
    a.resize(N);
    for(int i = 0; i < N; i++) cin >> a[i].first;
    for(int i = 0; i < N; i++) {
        a[i].second.resize(P);
        for(int j = 0; j < P; j++) {
            cin >> a[i].second[j];
        }
    }
    sort(a.begin(), a.end());
    Prev.resize(1 << P);
    Next.resize(1 << P);
    for(int i = 0; i < (1 << P); i++) {
        Prev[i] = -1e18;
    }
    Prev[0] = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < (1 << P); j++) {
            Next[j] = -1e18;
        }
        for(int bits = 0; bits < (1 << P); bits++) {
            int num = __builtin_popcount(bits);
            if(i - num >= NEET) chmax(Next[bits], Prev[bits] + a[i].first);
            else chmax(Next[bits], Prev[bits]);
            for(int j = 0; j < P; j++) {
                if(bits & (1 << j)) continue;
                chmax(Next[bits | (1 << j)], Prev[bits] + a[i].second[j]);
            }
        }
        swap(Prev, Next);
    }
    cout << Prev[(1 << P) - 1] << endl;
    return 0;
}