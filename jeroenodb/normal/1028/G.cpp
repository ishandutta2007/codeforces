#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef __int128_t ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, K = 1e4, oo = 1e9;
ll dp[6][10000] = {};
ll solve(int q, int lo) {
    if(dp[q][lo]) {
        return dp[q][lo];
    }
    auto& res = dp[q][lo];
    if(q==1) {
        return res = lo;
    }
    // first one
    res = lo;
    int i=0;
    for(;i<=lo and res<K;++i) {
        auto cur = solve(q-1,res);
        res+=cur+1;
    }
    if(i<=lo) res+= (lo+1-i)*solve(q-1,K) + (lo+1-i);
    res-=lo+1;
    return res;
}

vector<ll> getMove(int q, int lo) {
    // shift at the end
    vector<ll> moves;
    if(q==1) {
        for(int i=0;i<lo;++i) moves.push_back(i);
        return moves;
    }

    // first one
    ll res = lo;
    int i=0;
    for(;i<lo and res<K;++i) {
        auto cur = solve(q-1,res);
        res+=cur;
        moves.push_back(res-lo);
        res++;

    }
    while(i<lo) {
        res+=solve(q-1,K);
        moves.push_back(res-lo);
        res++;
        ++i;
    }
    return moves;
}
int main() {
    debug((long long)solve(5,1));
    ll lo = 1;
    int q=5;
    while(q!=0) {
        auto mv = getMove(q,min(ll(K),lo));
        for(auto& i : mv) i+=lo;
        int k = mv.size();
        // no out of bounds!
        ll last = 10004205361450475;
        for(int i=k-1;i>=0;--i) {
            mv[i] = min(mv[i],last-1);
            last = mv[i];
        }
        cout << k << '\n';
        for(auto& i : mv) {
            cout << (long long)i << ' ';
        }
        cout <<  endl;
        int res; cin >> res;
        if(res<0) {
            exit(0);
        } else {
            if(res!=0) lo = mv[res-1]+1;
        }
        q--;
    }

}