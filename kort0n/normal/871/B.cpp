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

const long long INF = 1e18;
//const ll mod = 1000000007;
ll N;
ll A[5000], B[5000];

void f(int a, int b) {
    cout << "? " << a << " " << b << endl;
}

vector<int> p, b;
vector<int> psub;
bool exist[5000];
int main() {
    cin >> N;
    p.resize(N), b.resize(N);
    for(int i = 0; i < N; i++) {
        f(i, 0);
        cin >> A[i];
    }
    for(int i = 0; i < N; i++) {
        f(0, i);
        cin >> B[i];
    }
    int ansnum = 0;
    for(p[0] = 0; p[0] < N; p[0]++) {
        bool ok = true;
        for(int i = 0; i < N; i++) {
            exist[i] = false;
            b[i] = p[0] ^ B[i];
            if(b[i] >= N) ok = false;
        }
        for(int i = 1; i < N; i++) {
            p[i] = b[0] ^ A[i];
            if(p[i] >= N) ok = false;
        }
        if(!ok) continue;
        for(int i = 0; i < N; i++) {
            if(exist[p[i]]) ok = false;
            exist[p[i]] = true;
            if(b[p[i]] != i) ok = false;
        }
        if(ok) {
            ansnum++;
            if(ansnum == 1) {
                psub = p;
            }
        }
    }
    cout << "!" << endl;
    cout << ansnum << endl;
    for(int i = 0; i < N; i++) {
        if(i != 0) cout << " ";
        cout << psub[i];
    }
    cout << endl;
    return 0;
}