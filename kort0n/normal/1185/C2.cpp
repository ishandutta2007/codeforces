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
multiset<int> st;
int sum = 0;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        int t;
        cin >> t;
        auto itr = st.end();
        if(itr != st.begin()) itr--;
        int nowval = sum + t;
        //cerr << "INITIALVAL: " << nowval << endl;
        int ans = i - 1 - st.size();
        while(nowval > M) {
            nowval -= (*itr);
            //cerr << nowval << " " << t << " " << *itr << endl;
            if(itr == st.begin()) ans++;
            if(itr != st.begin()) itr--;
        }
        //cerr << "VAL: " << nowval << endl;
        //cerr << nowval << endl;
        if(itr != st.end()) {
            ans += distance(itr, st.end()) - 1;
        }
        cout << ans << endl;
        sum += t;
        //cerr << "T: " << t << endl;
        st.insert(t);
        while(sum > M) {
            auto itr = st.end();
            itr--;
            sum -= *itr;
            st.erase(itr);
        }
        //cerr << sum << " " << st.size() << endl;
    }
    return 0;
}