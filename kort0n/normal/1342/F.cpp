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

struct node {
    ll val;
    ll bits;
    ll Last;
    ll num;
    node() {
        Last = -1;
        val = 1e18;
        bits = -1;
        num = -1;
    }
    node(ll val, ll bits, ll Last, ll num) : val(val), bits(bits), Last(Last), num(num) {}
};

node dp[1 << 15][16][16];
vector<ll> a;
ll sum[1<<15];

void solve() {
    ll N;
    cin >> N;
    a.resize(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int bits = 0; bits < (1 << N); bits++) {
        sum[bits] = 0;
        for(int i = 0; i < N; i++) {
            if(bits & (1 << i)) sum[bits] += a[i];
        }
    }
    for(int i = 0; i < (1 << N); i++) {
        for(int j = 0; j <= N; j++) {
            for(int k = 0; k <= N; k++) {
                dp[i][j][k] = node();
            }
        }
    }
    dp[0][0][0] = node(0, 0, -1, 0);
    for(int bits = 0; bits < (1 << N); bits++) {
        for(int Last = 0; Last <= N; Last++) {
            for(int num = 0; num < N; num++) {
                if(dp[bits][Last][num].val == 1e18) continue;
                //cerr << bits << " " << Last << " " << num << " " << dp[bits][Last][num].val << endl;
                int C = (1 << N) - 1;
                C ^= bits;
                for(int sub = C + 1; ;) {
                    sub = (sub - 1) & C;
                    if(sub == 0) break;
                    if(sum[sub] <= dp[bits][Last][num].val) continue;
                    int subsub = sub / (1 << Last);
                    subsub *= (1 << Last);
                    if(subsub == 0) continue;
                    int NewLast = __builtin_ffs(subsub);
                    if(dp[bits|sub][NewLast][num+1].val > sum[sub]) {
                        dp[bits|sub][NewLast][num+1] = node(sum[sub], sub, Last, num);
                    }
                }
            }
        }
    }
    int ansnum = 0;
    int nowbits, nownum, nowLast;
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            if(dp[(1 << N) - 1][i][j].val != 1e18) {
                if(chmax(ansnum, j)) {
                    nowbits = (1 << N) - 1;
                    nownum = j;
                    nowLast = i;
                }
            }
        }
    }
    cout << N - ansnum << endl;
    vector<i_i> query;
    while(true) {
        if(dp[nowbits][nowLast][nownum].Last == -1) break;
        int sub = dp[nowbits][nowLast][nownum].bits;
        //cerr << bitset<10>(nowbits) << " " << nowLast << " " << nownum << endl;
        //cerr << bitset<10>(sub) << endl;
        for(int i = 0; i < N; i++) {
            if(sub & (1 << i)) {
                if(i != nowLast - 1) {
                    query.push_back({i, nowLast - 1});
                }
            }
        }
        int tmp1 = nowbits ^ sub;
        int tmp2 = dp[nowbits][nowLast][nownum].Last;
        int tmp3 = nownum - 1;
        nowbits = tmp1;
        nowLast = tmp2;
        nownum = tmp3;
    }
    //cerr << query.size() << endl;
    //assert(query.size() == N - ansnum);
    vector<int> v(N);
    for(int i = 0; i < N; i++) v[i] = i;
    for(auto q : query) {
        //cout << q.first << " " << q.second << endl;
        auto itr1 = v.begin();
        auto itr2 = v.begin();
        while(*itr1 != q.first) itr1++;
        while(*itr2 != q.second) itr2++;
        cout << itr1 - v.begin() + 1 << " " << itr2 - v.begin() + 1 << endl;
        v.erase(itr1);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}