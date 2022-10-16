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
int N, M;
int a[105000], b[105000], c[105000], d[105000];
int rest[105000];
int ans[150000];
vector<int> compress;
int MAX;
vector<i_i> actor[405000], song[405000];
int main() {
    //cout.precision(10);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i] >> b[i];
        compress.push_back(a[i]);
        compress.push_back(b[i]);
    }
    cin >> M;
    for(int i = 1; i <= M; i++) {
        cin >> c[i] >> d[i] >> rest[i];
        compress.push_back(c[i]);
        compress.push_back(d[i]);
    }
    sort(compress.begin(), compress.end());
    compress.erase(unique(compress.begin(), compress.end()), compress.end());
    MAX = compress.size();
    for(int i = 1; i <= N; i++) {
        auto itr = lower_bound(compress.begin(), compress.end(), a[i]);
        a[i] = distance(compress.begin(), itr);
        itr = lower_bound(compress.begin(), compress.end(), b[i]);
        b[i] = distance(compress.begin(), itr);
        //cerr << a[i] << " " << b[i] << endl;
        song[a[i]].push_back({b[i], i});
    }
    for(int i = 1; i <= M; i++) {
        auto itr = lower_bound(compress.begin(), compress.end(), c[i]);
        c[i] = distance(compress.begin(), itr);
        itr = lower_bound(compress.begin(), compress.end(), d[i]);
        d[i] = distance(compress.begin(), itr);
        actor[c[i]].push_back({d[i], i});
        //cerr << c[i] << " " << d[i] << endl;
    }
    set<i_i> st;
    for(int voice = 0; voice < MAX; voice++) {
        for(int i = 0; i < actor[voice].size(); i++) {
            st.insert(actor[voice][i]);
        }
        for(int i = 0; i < song[voice].size(); i++) {
            int tmp = song[voice][i].first;
            auto itr = st.lower_bound({tmp, 0});
            if(itr == st.end()) {
                cout << "NO" << endl;
                return 0;
            }
            i_i now = *itr;
            ans[song[voice][i].second] = now.second;
            rest[now.second]--;
            if(rest[now.second] == 0) st.erase(itr);
        }
    }
    cout << "YES" << endl;
    for(int i = 1; i <= N; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}