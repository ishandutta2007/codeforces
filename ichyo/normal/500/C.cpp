#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{"; for(T e : v) os << e << ","; os << "}"; return os;
}

int main(){
    int n, m;
    while(cin >> n >> m) {
        vector<int> w(n);
        REP(i, n) cin >> w[i];

        vector<int> b(m);
        REP(i, m) cin >> b[i];
        REP(i, m) b[i]--;

        vector<int> s;
        REP(i, m) if(find(s.begin(), s.end(), b[i]) == s.end()) {
            s.push_back(b[i]);
        }

        long long ans = 0;
        REP(i, m) {
            int k = find(s.begin(), s.end(), b[i]) - s.begin();
            REP(j, k) ans += w[ s[j] ];
            s.erase(s.begin() + k);
            s.insert(s.begin(), b[i]);
        }

        cout << ans << endl;
    }
    return 0;
}