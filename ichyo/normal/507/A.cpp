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

int main(){
    iostream_init();

    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> A(N);
    REP(i, N) cin >> A[i].first;
    REP(i, N) A[i].second = i;
    sort(A.begin(), A.end());
    vector<int> ans;
    for(int i = 0; i < N && K >= A[i].first; i++) {
        K -= A[i].first;
        ans.push_back(A[i].second);
    }
    cout << ans.size() << endl;
    if(ans.size()) {
        REP(i, ans.size()) {
            if(i > 0) cout << " ";
            cout << ans[i] + 1;
        }
        cout << endl;
    }
    return 0;
}

/* vim:set foldmethod=marker: */