// Template {{{
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

template<typename T1, typename T2>
ostream& operator << (ostream& os, const pair<T1, T2>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template<typename T>
ostream& operator << (ostream& os, const vector<T>& v) {
    os << "{";
    for(int i = 0; i < v.size(); i++)
        os << v[i] << (i+1<v.size()?", ":"");
    os << "}";
    return os;
}

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}
//}}}

typedef pair<int, int> P;
typedef tuple<int, int, int> T;
int main(){
    iostream_init();
    int N;
    while(cin >> N) {
        set<T> s;
        vector<int> deg(N);
        vector<int> val(N);
        REP(i, N) {
            int d, t;
            cin >> d >> t;
            if(d > 0) s.insert(make_tuple(d, t, i));
            deg[i] = d;
            val[i] = t;
        }
        vector<P> ans;
        while(!s.empty()) {
            auto tp = *s.begin();
            int d, t, i;
            tie(d, t, i) = tp;
            assert(d == 1);
            assert(deg[t] >= 1);
            auto it = s.lower_bound(make_tuple(deg[t], val[t], t));
            assert(*it == make_tuple(deg[t], val[t], t));
            s.erase(s.begin());
            s.erase(it);
            deg[t] --;
            val[t] ^= i;
            if(deg[t] > 0) s.insert(make_tuple(deg[t], val[t], t));
            ans.push_back(make_pair(i, t));
        }
        cout << ans.size() << endl;
        for(auto p : ans) cout << p.first << " " << p.second << endl;

    }
    return 0;
}

/* vim:set foldmethod=marker: */