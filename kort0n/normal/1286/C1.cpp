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
int N;
string ans;
void SubQuery() {
    cout << "? 1 1" << endl;
    cin >> ans[0];
    cout << "! " << ans << endl;
}

vector<int> h(string S) {
    vector<int> ret(26);
    for(auto c : S) {
        ret[(int)(c - 'a')]++;
    }
    return ret;
}

void print(vector<int> v) {
    for(int i = 0; i < 26; i++) {
        if(v[i]) {
            cerr << (char)('a' + i) << v[i];
        }
    }
    cerr << endl;
}

multiset<vector<int>> st[2][105];
vector<int> ALL;
void f(int index, int from, int now) {
    cerr << "f: " << index << " " << from << " " << now << endl;
    if(from == now) return;
    int SIZE = abs(now - from);
    for(int i = 0; i + SIZE <= N; i++) {
        vector<int> w = ALL;
        bool ok = true;
        for(int j = 0; j < N; j++) {
            if(i <= j and j < i + SIZE) continue;
            if(ans[j] == '#') {
                ok = false;
                break;
            }
            w[(int)(ans[j] - 'a')]--;
        }
        if(!ok) continue;
        cerr << ans << endl;
        cerr << i;
        print(w);
        auto itr = st[index][SIZE].lower_bound(w);
        st[index][SIZE].erase(itr);
    }
    assert(st[index][SIZE].size() == 1);
    auto v = *st[index][SIZE].begin();
    cerr << "V:";
    print(v);
    v[(int)(ans[from] - 'a')]--;
    vector<int> w = ALL;
    for(int i = 0; i < N; i++) {
        if(i < min(from, now) and i > max(from, now)) {
            w[(int)(ans[i] - 'a')]--;
        }
    }
    for(int i = 0; i < 26; i++) {
        w[i] -= v[i];
        if(w[i]) ans[now] = (char)('a' + i);
    }
    if(index == 0) {
        f(1, now, from + 1);
    } else {
        f(0, now, from - 1);
    }
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) {
        ans.push_back('#');
    }
    if(N == 1) {
        SubQuery();
        return 0;
    }
    cout << "? 1 1" << endl;
    cin >> ans[0];
    cout << "? " << 1 << " " << N << endl;
    for(int i = 0; i < N * (N + 1) / 2; i++) {
        string S;
        cin >> S;
        vector<int> v = h(S);
        st[0][S.size()].insert(v);
        if(S.size() == N) ALL = v;
    }
    cout << "? " << 2 << " " << N << endl;
    for(int i = 0; i < (N - 1) * N / 2; i++) {
        string S;
        cin >> S;
        auto v = h(S);
        auto itr = st[0][S.size()].lower_bound(v);
        st[0][S.size()].erase(itr);
        //st[1][S.size()].insert(h(S));
    }
    for(int sz = 1; sz <= N; sz++) {
        auto v = *st[0][sz].begin();
        for(int i = 0; i < sz - 1; i++) {
            v[(int)(ans[i] - 'a')]--;
        }
        for(int i = 0; i < 26; i++) {
            if(v[i]) ans[sz-1] = (char)('a' + i);
        }
    }
    //print(ALL);
    //f(0, 0, N - 1);
    cout << "! " << ans << endl;
    return 0;
}