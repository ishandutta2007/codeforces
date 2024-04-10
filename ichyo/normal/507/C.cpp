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
    LL H, N;
    while(cin >> H >> N) {
        N--;
        int next = 0;
        LL ans = H;
        for(int i = H-1; i >= 0; i--) {
            if(next != (N >> i & 1)) {
                ans += (1LL << (i+1));
                ans -= 1;
            }
            next = 1 ^ (N >> i & 1);
        }
        cout << ans << endl;
    }
    return 0;
}

/* vim:set foldmethod=marker: */