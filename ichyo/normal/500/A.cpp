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
    int N, dst;
    while(cin >> N >> dst) {
        dst--;
        vector<int> A(N);
        REP(i, N-1) cin >> A[i];
        queue<int> que;
        que.push(0);
        vector<bool> used(N);
        used[0] = true;
        while(!que.empty()) {
            int u = que.front(); que.pop();
            int v = u + A[u];
            if(!used[v]) {
                used[v] = true;
                que.push(v);
            }
        }
        cout << (used[dst] ? "YES" : "NO") << endl;
    }
    return 0;
}