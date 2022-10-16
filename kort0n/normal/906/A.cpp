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
set<char> st;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    for(char a = 'a'; a <= 'z'; a++) st.insert(a);
    int N;
    cin >> N;
    int ans = 0;
    while(N--) {
        char op;
        cin >> op;
        string S;
        cin >> S;
        if(op == '!') {
            if(st.size() == 1) {
                ans++;
            }
            sort(S.begin(), S.end());
            for(char a = 'a'; a <= 'z'; a++) {
                auto itr = lower_bound(S.begin(), S.end(), a);
                if(itr == S.end() or *itr != a) {
                    st.erase(a);
                }
            }
        } else if(op == '.') {
            for(auto c : S) {
                st.erase(c);
            }
        } else if(op == '?') {
            if(N != 0) {
                if(st.size() == 1) ans++;
                else {
                    st.erase(S[0]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}