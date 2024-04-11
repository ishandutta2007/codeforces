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
int N;
int a[200500];
int b[200050];
int firsttime[200050];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> a[i];
    for(int i = 1; i <= N; i++) cin >> b[i];
    for(int i = 1; i <= N; i++) {
        if(a[i] > 0) firsttime[a[i]] = 0;
    }
    for(int i = 1; i <= N; i++) {
        if(b[i] > 0) firsttime[b[i]] = i;
    }
    //for(int i = 1; i <= N; i++) cerr << i << " " << firsttime[i] << endl;
    if(firsttime[1] > 0) {
        int nowans = firsttime[1] - 1;
        bool clear = true;
        for(int i = 2; i <= N; i++) {
            if(firsttime[i] == firsttime[1] + i - 1 || ((N - i + 1) <= nowans - firsttime[i])) {
                continue;
            }
            //cerr << "OUT: " << i << endl;
            clear = false;
        }
        if(clear) {
            cout << nowans << endl;
            return 0;
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        chmax(ans, firsttime[i] + (N - i + 1));
    }
    cout << ans << endl;
    return 0;
}