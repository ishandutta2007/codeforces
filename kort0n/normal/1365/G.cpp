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
int N;
ll Total = 0;
ll bits[2000];
const int Q = 13;
vector<ll> query[100];
ll ret[100];
vector<ll> a;
const int LOCAL = 0;

void ask(int idx) {
    if(query[idx].empty()) return;
    cout << "? " << query[idx].size();
    for(auto val : query[idx]) {
        cout << " " << val + 1;
    }
    cout << endl;
    ll tmp;
    if(LOCAL) {
        tmp = 0;
        for(auto b : query[idx]) tmp |= a[b];
    } else {
        cin >> tmp;
    }
    if(tmp == -1) exit(0);
    Total |= tmp;
    ret[idx] = tmp;
}

void f(int idx) {
    ll tmp = 0;
    for(int q = 0; q < Q; q++) {
        if((1 << q) & bits[idx]) continue;
        tmp |= ret[q];
    }
    cout << " " << tmp;
    if(LOCAL) {
        ll ans = 0;
        for(int i = 0; i < N; i++) {
            if(i == idx) continue;
            ans |= a[i];
        }
        assert(ans == tmp);
    }
}

void ANSWER() {
    cout << "!";
    for(int i = 0; i < N; i++) {
        f(i);
    }
    cout << endl;
}

int main() {
    cin >> N;
    if(LOCAL) {
        a.resize(N);
        for(int i = 0; i < N; i++) {
            a[i] = i * i;
        }
    }
    vector<int> v(Q);
    for(int i = 0; i < 6; i++) v[i] = 1;
    int cnt = 0;
    sort(v.begin(), v.end());
    do {
        if(cnt >= N) break;
        for(int j = 0; j < Q; j++) {
            if(v[j]) {
                bits[cnt] |= (1 << j);
                query[j].push_back(cnt);
            }
        }
        cnt++;
    } while(next_permutation(v.begin(), v.end()));
    //cerr << cnt << endl;
    for(int i = 0; i < Q; i++) {
        ask(i);
    }
    ANSWER();
    return 0;
}