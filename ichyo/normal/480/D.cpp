#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
namespace {
int n, ST;
int in[1000];
int out[1000];
int w[1000];
int s[1000];
int v[1000];
}

int memo[505][1010];

int rec(int idx, int S) {
    int left = (idx == -1 ? 0 : in[idx]);
    int right = (idx == -1 ? 2*n:out[idx]);
    int val = (idx == -1 ? 0 : v[idx]);

    int& answer = memo[idx+1][S];
    if(answer != -1) return val + answer;
    answer = 0;

    int max_v[1010] = {};
    int cur = 0;
    int last = 0;
    for(int i = 0; i < n; i++) if(left <= in[i] && out[i] <= right && w[i] <= S && i != idx) {
        while(last < in[i]) {
            cur = max(cur, max_v[++last]);
        }

        int res = rec(i, min(S - w[i], s[i]));
        // cout << idx << "->" << i << " : " << res << " + " << cur << endl;

        answer = max(answer, res+cur);
        max_v[out[i]] = max(max_v[out[i]], res+cur);
        // cout << "max_v[" << out[i] << " <- " << res+cur << endl;
    }

    // cout << idx << " " << S << " " << val + answer << endl;
    return val + answer;
}

int main(){
    while(cin >> n >> ST){
        REP(i, n) cin >> in[i] >> out[i] >> w[i] >> s[i] >> v[i];
        REP(_, n) REP(i, n - 1) {
            if(make_pair(in[i], out[i]) > make_pair(in[i+1], out[i+1])) {
                swap(in[i], in[i+1]);
                swap(out[i], out[i+1]);
                swap(w[i], w[i+1]);
                swap(s[i], s[i+1]);
                swap(v[i], v[i+1]);
            }
        }
        // REP(i, n) cout << "[" << in[i] << "," << out[i] << "]" << endl;

        memset(memo, -1, sizeof(memo));
        cout << rec(-1, ST) << endl;
    }
    return 0;
}