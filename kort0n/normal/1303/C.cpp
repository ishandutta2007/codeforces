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


void solve() {
    string S;
    cin >> S;
    if(S.size() == 1) {
        cout << "YES" << endl;
        for(char a = 'a'; a <= 'z'; a++) cout << a;
        cout << endl;
        return;
    }
    map<char, set<char>> paths;
    for(int i = 0; i + 1 < S.size(); i++) {
        paths[S[i]].insert(S[i+1]);
        paths[S[i+1]].insert(S[i]);
    }
    char s = '#';
    for(char a = 'a'; a <= 'z'; a++) {
        if(paths[a].size() >= 3) {
            cerr << a << " " << paths[a].size() << endl;
            cout << "NO" << endl;
            return;
        }
        if(paths[a].size() == 1) {
            s = a;
        }
    }
    if(s == '#') {
        cout << "NO" << endl;
        return;
    }
    char now = s;
    set<char> appear;
    cout << "YES" << endl;
    while(true) {
        cout << now;
        assert(appear.find(now) == appear.end());
        appear.insert(now);
        if(now != s and paths[now].size() == 1) break;
        for(auto c : paths[now]) {
            if(appear.find(c) == appear.end()) {
                now = c;
                break;
            }
        }
    }
    for(char a = 'a'; a <= 'z'; a++) {
        if(appear.find(a) == appear.end()) {
            cout << a;
        }
    }
    cout << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}