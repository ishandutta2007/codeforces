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
ll n, q;
ll a[100050];
ll b[100050];
deque<ll> deq;
ll A[100500], B[100500];
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> q;
    ll maxi = -1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        deq.push_back(a[i]);
        chmax(maxi, a[i]);
    }
    int index = 0;
    while(true) {
        ll Anow, Bnow;
        Anow = deq.front();
        if(Anow == maxi) {
            break;
        }
        deq.pop_front();
        Bnow = deq.front();
        deq.pop_front();
        index++;
        A[index] = Anow;
        B[index] = Bnow;
        deq.push_front(max(A[index], B[index]));
        deq.push_back(min(A[index], B[index]));
    }
    for(int i = 1; i <= n; i++) {
        b[i] = deq.front();
        deq.pop_front();
    }
    /*
    for(int i = 1; i <= index; i++) cerr << A[i] << " " << B[i] << endl;
    cerr << endl;
    for(int i = 1; i <= n; i++) cerr << b[i] << " ";
    cerr << endl;
    */
    while(q--) {
        ll m;
        cin >> m;
        if(m <= index) {
            cout << A[m] << " " << B[m] << endl;
            continue;
        }
        m -= index;
        m %= (n - 1);
        if(m == 0) m += n - 1;
        cout << maxi << " "<< b[1 + m] << endl;
    }
    return 0;
}