// Template {{{
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

#ifdef LOCAL
#include "contest.h"
#else
#define dump(x) 
#endif

class range {
    struct Iterator {
        int val, inc;
        int operator*() {return val;}
        bool operator!=(Iterator& rhs) {return val < rhs.val;}
        void operator++() {val += inc;}
    };
    Iterator i, n;
    public:
    range(int e) : i({0, 1}), n({e, 1}) {}
    range(int b, int e) : i({b, 1}), n({e, 1}) {}
    range(int b, int e, int inc) : i({b, inc}), n({e, inc}) {}
    Iterator& begin() {return i;}
    Iterator& end() {return n;}
};

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}
//}}}
int N, K;
int cnt[2] = {};
int sum = 0;
const string WIN = "Stannis"; // odd, first
const string LOSE = "Daenerys"; // even, second
bool dfs(int a, int b, int k, int turn) {
    assert(k >= 0);
    if(k == 0) {
        return b % 2 == 1;
    }
    if(turn == 0) {
        if(a > 0 && dfs(a-1, b, k-1, 1)) return true;
        if(b > 0 && dfs(a, b-1, k-1, 1)) return true;
        return false;
    } else {
        if(a > 0 && !dfs(a-1, b, k-1, 0)) return false;
        if(b > 0 && !dfs(a, b-1, k-1, 0)) return false;
        return true;
    }
}
void input() {
    REP(i, N) {
        int a;
        cin >> a;
        a &= 1;
        cnt[a] ++;
        sum ^= a;
    }
}
string slow() {
    if(dfs(cnt[0], cnt[1], N-K, 0)) {
        return WIN;
    } else {
        return LOSE;
    }
}
bool ans(int a, int b, int n, int k) {
    if(n == k) return b % 2 == 1;

    if(k % 2 == 0) {
        if(n % 2 == 0){
            return false;
        }
        if(n % 2 == 1) {
            int t = (n - k) / 2;
            if(a <= t || b <= t) return false;
            return true;
        }
    }
    if(k % 2 == 1) {
        if(n % 2 == 0) {
            int t = (n - k) / 2;
            if(a <= t + 1) return true;
            if(b <= t) return false;
            return true;
        } 
        if(n % 2 == 1) {
            int t = (n - k) / 2;
            if(a <= t) return true;
            if(b <= t) return false;
            return false;
        }
    }
    assert(false);
}
void verify() {
    const int n = 100;
    for(int i = 1; i <= n; i++) {
        cout << i << endl;
        for(int j = 1; j <= i; j++) {
            for(int a = 0; a <= i; a++) {
                int b = i - a;
                if(!(dfs(a, b, i-j, 0) == ans(a, b, i, j))) {
                    cout << "n: " << i << endl;
                    cout << "k: " << j << endl;
                    cout << "a: " << a << endl;
                    cout << "b: " << b << endl;
                    cout << dfs(a, b, i-j, 0) << " " << ans(a, b, i, j) << endl;
                    assert(false);
                }
            }
        }
    }
}
int main(){
    iostream_init();
    //verify();
    while(cin >> N >> K) {
        input();
        cout << (ans(cnt[0], cnt[1], N, K) ? WIN : LOSE) << endl;
    }
    return 0;
}

/* vim:set foldmethod=marker: */