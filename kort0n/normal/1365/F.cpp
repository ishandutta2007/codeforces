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

bool solve() {
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < N; i++) cin >> b[i];
    if(N & 1) {
        if(a[N/2] != b[N/2]) {
            return false;
        }
        a.erase(a.begin() + (N / 2));
        b.erase(b.begin() + (N / 2));
        N--;
    }
    multiset<i_i> st;
    for(int i = 0; i < N; i++) {
        int A = a[i];
        int B = a[N-1-i];
        if(A > B) swap(A, B);
        st.insert({A, B});
    }
    for(int i = 0; i < N; i++) {
        int A = b[i];
        int B = b[N-1-i];
        if(A > B) swap(A, B);
        auto itr = st.find({A, B});
        if(itr == st.end()) {
            return false;
        } else {
            st.erase(itr);
        }
    }
    return true;
    /*
    set<int> checker;
    for(int i = 0; i < a.size(); i++) {
        checker.insert(a[i]);
    }
    if(checker.size() != N) return true;
    vector<int> A[2], B[2];
    for(int i = 0; i < N / 2; i++) {
        A[0].push_back(a[i]);
        A[1].push_back(a[N - 1 -i]);
        B[0].push_back(b[i]);
        B[1].push_back(b[N - 1 -i]);
    }
    */
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        if(solve()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}