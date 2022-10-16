#include <bits/stdc++.h>
//#include <atcoder/all>
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
string S;
ll N;
vector<ll> ans;
using ci = pair<char, int>;
vector<ci> v;

void print() {
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        if(i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

bool f() {
    ans.clear();
    if(S == string(N, '_')) {
        return true;
    }
    if(S[0] == '_') return false;
    if(S[N-1] == '_') return false;
    for(auto tmp : v) {
        if(tmp.first == '_' and tmp.second >= 2) return false;
    }
    for(auto tmp : v) {
        if(tmp.first == '#') ans.push_back(tmp.second);
    }
    return true;
}

bool g() {
    ans.clear();
    if(S[0] == '#') return false;
    if(S[N-1] == '#') return false;
    for(int i = 0; i < v.size(); i++) {
        if(v[i].first == '#') {
            ans.push_back(v[i].second + 1);
        } else {
            if(i == 0 or i + 1 == v.size()) {
                int len = v[i].second - 1;
                if(len % 2 == 1) return false;
                while(len != 0) {
                    len -= 2;
                    ans.push_back(1);
                }
            } else {
                int len = v[i].second - 2;
                if(len < 0 or len % 2 == 1) return false;
                while(len != 0) {
                    len -= 2;
                    ans.push_back(1);
                }
            }
        }
    }
    return true;
}

bool h(int x) {
    ans.clear();
    if(S[0] == '#') return false;
    if(S[N-1] == '#') return false;
    for(int i = 0; i < v.size(); i++) {
        if(v[i].first == '#') {
            ans.push_back(v[i].second + x);
        } else {
            if(i == 0 or i + 1 == v.size()) {
                int len = v[i].second - x;
                while(len != 0) {
                    if(len < 0) return false;
                    if(len % 2 == 1) {
                        len -= 3;
                        ans.push_back(2);
                    } else {
                        len -= 2;
                        ans.push_back(1);
                    }
                }
            } else {
                int len = v[i].second - x - 1;
                while(len != 0) {
                    if(len < 0) return false;
                    if(len % 2 == 1) {
                        len -= 3;
                        ans.push_back(2);
                    } else {
                        len -= 2;
                        ans.push_back(1);
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> S;
    N = S.size();
    for(int i = 0; i < N; i++) {
        if(v.empty() or v.back().first != S[i]) {
            v.push_back({S[i], 0});
        }
        v.back().second++;
    }
    if(f()) {
        print();
        //cerr << "F" << endl;
        return 0;
    }
    if(g()) {
        print();
        //cerr << "G" << endl;
        return 0;
    }
    for(int x = 2; x <= 5; x++) {
        if(h(x)) {
            print();
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}