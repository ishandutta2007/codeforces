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
ll N, K;
vector<vector<ll>> A;
ll maxi;
ll ret;
ll ok, ng;


void ask(vector<int> v) {
    cerr << "ask" << endl;
    sort(v.begin(), v.end());
    cout << "? " << v.size();
    for(auto val : v) {
        cout << " " << val + 1;
    }
    cout << endl;
    cin >> ret;
}

void getmaxi() {
    vector<int> v;
    for(int i = 0; i < N; i++) {
        v.push_back(i);
    }
    ask(v);
    maxi = ret;
}


void g(int l, int r) {
    cerr << "g" << endl;
    vector<int> v;
    set<int> st;
    for(int i = l; i < r; i++) {
        for(auto val : A[i]) st.insert(val);
    }
    for(int i = 0; i < N; i++) {
        if(st.find(i) == st.end()) v.push_back(i);
    }
    ask(v);
}

void ans() {
    cout << "!";
    for(int i = 0; i < K; i++) {
        if(i != ok) cout << " " << maxi;
        else cout << " " << ret;
    }
    cout << endl;
    string res;
    cin >> res;
    if(res != "Correct") exit(0);
}

void solve() {
    cin >> N >> K;
    ok = 0;
    ng = K;
    A.clear();
    A.resize(K);
    for(int i = 0; i < K; i++) {
        int M;
        cin >> M;
        A[i].resize(M);
        for(int j = 0; j < M; j++) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    getmaxi();
    if(K == 1) {
        vector<int> v;
        for(int i = 0; i < N; i++) {
            bool ok = true;
            for(auto val : A[0]) {
                if(val == i) ok = false;
            }
            if(ok) v.push_back(i);
        }
        ask(v);
        cout << "! " << ret << endl;
        string dust;
        cin >> dust;
        if(dust != "Correct") {
            exit(0);
        }
        return;
    }
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        g(ok, mid);
        if(ret == maxi) ok = mid;
        else ng = mid;
    }
    g(ok, ok + 1);
    ans();
}

int main() {
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}