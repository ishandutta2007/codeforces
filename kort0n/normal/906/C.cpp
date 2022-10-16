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
typedef pair<int, i_i> iii;
bool IsClique[1<<22];
bool A[22][22];
int B[22];
iii dp[1<<22];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        A[a][b] = true;
        A[b][a] = true;
        B[a] |= (1 << b);
        B[b] |= (1 << a);
    }
    IsClique[0] = true;
    for(int bits = 1; bits < (1 << N); bits++) {
        int a;
        for(int i = 0; i < N; i++) {
            if(bits & (1 << i)) a = i;
        }
        bool tmp = IsClique[bits & (~(1<<a))];
        for(int i = 0; i < N; i++) {
            if(a == i) continue;
            if(!(bits & (1 << i))) continue;
            tmp &= A[i][a];
        }
        IsClique[bits] = tmp;
        //cerr << bitset<5>(bits) << " " << IsClique[bits] << endl;
    }
    for(int bits = 0; bits < (1 << N); bits++) {
        dp[bits] = {1e9, {-1, -1}};
        if(IsClique[bits]) dp[bits] = {-1, {-1, -1}};
    }
    for(int bits = 0; bits < (1 << N); bits++) {
        for(int i = 0; i < N; i++) {
            if(!(bits & (1 << i))) continue;
            int to = bits | B[i];
            iii nxt;
            nxt.first = dp[bits].first + 1;
            nxt.second.first = bits;
            nxt.second.second = i;
            chmin(dp[to], nxt);
        }
    }
    //cout << dp[(1<<N)-1].first << endl;
    vector<int> v;
    int now = (1 << N) - 1;
    while(now != -1) {
        if(dp[now].second.second == -1) break;
        v.push_back(dp[now].second.second);
        now = dp[now].second.first;
    }
    reverse(v.begin(), v.end());
    cout << v.size() << endl;
    if(!v.empty()) {
        for(auto val : v) cout << val + 1 << " ";
        cout << endl;
    }
    return 0;
}