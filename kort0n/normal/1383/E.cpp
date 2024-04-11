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
const ll mod = 1000000007;
ll dp[1050000];
string S;
ll ans;
ll TopZero, BottomZero;
vector<ll> v;
ll Next[1050000];

bool AllSame(string S) {
    for(int i = 0; i < S.size(); i++) {
        if(S[i] != S[0]) return false;
    }
    return true;
}

deque<l_l> deq;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> S;
    int N = S.size();
    if(AllSame(S)) {
        cout << N << endl;
        return 0;
    }
    for(int i = 0; ; i++) {
        if(S[i] == '0') {
            TopZero++;
        } else {
            break;
        }
    }
    S.erase(S.begin(), S.begin() + TopZero);
    while(S.back() == '0') {
        BottomZero++;
        S.pop_back();
    }
    ll tmpnum = 0;
    for(int i = 1; i < S.size(); i++) {
        if(S[i] == '0') tmpnum++;
        else {
            v.push_back(tmpnum);
            tmpnum = 0;
        }
    }
    N = v.size();
    /*
    cerr << S << endl;
    for(auto tmp : v) cerr << tmp << " ";
    cerr << endl;
    */
    for(int i = (int)v.size() - 1; i >= 0; i--) {
        while(!deq.empty() and deq.front().first <= v[i]) deq.pop_front();
        if(deq.empty()) Next[i] = -1;
        else Next[i] = deq.front().second;
        deq.push_front({v[i], i});
    }
    /*
    for(int i = 0; i < v.size(); i++) cerr << Next[i] << " ";
    cerr << endl;
    */
    dp[0] = 1;
    for(int i = 0; i <= N; i++) {
        //cerr << "-----" << i << "-----" << endl;
        ans += dp[i];
        ans %= mod;
        if(i == N) continue;
        ll idx = i;
        ll val = v[idx];
        dp[idx+1] += dp[i] * (val + 1);
        dp[idx+1] %= mod;
        //cerr << idx << " " << val << endl;
        while(Next[idx] != -1) {
            val = v[Next[idx]] - v[idx];
            idx = Next[idx];
            dp[idx+1] += dp[i] * val;
            dp[idx+1] %= mod;
            //cerr << idx << " " << val << endl;
        }
    }
    /*
    for(int i = 0; i < N; i++) {
        for(auto tmp : to[i]) {
            cerr << "{" << tmp.first << ", " << tmp.second << "} ";
        }
        cerr << endl;
    }
    */
    ans = ans * (TopZero + 1) % mod;
    ans = ans * (BottomZero + 1) % mod;
    cout << ans << endl;
    return 0;
}