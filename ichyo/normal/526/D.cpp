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

template<int B, int M>
struct RMHash{
    vector<int> pow;
    vector<int> hash;
    RMHash(const string& s) {
        int n = s.size();
        pow.assign(n + 1, 1);
        hash.assign(n + 1, 0);
        REP(i, n) {
            pow[i + 1] = ((long long)pow[i] * B) % M;
            hash[i + 1] = (s[i] + (long long)hash[i] * B) % M;
        }
    }
    // hash of s[0..i)
    int h(int i) {
        return hash[i];
    }
    // hash of s[i..j)
    int h(int i, int j) {
        if(i == 0) return h(j);
        int res = (h(j) - (long long)h(i) * pow[j-i]) % M;
        if(res < 0) res += M;
        return res;
    }
};
vector<int> Z_Algorithm(const string& s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i > r) {
            l = r = i;
            while (r < n && s[r-l] == s[r]){ r++; }
            z[i] = r-l;
            r--;
        } else {
            int k = i-l;
            if (z[k] < r-i+1){
                z[i] = z[k];
            } else {
                l = i;
                while (r<n && s[r-l] == s[r]){ r++; }
                z[i] = r-l;
                r--;
            }
        }
    }
    return z;
}

typedef RMHash<1000003, 1000000021> Hash1;
int main(){
    iostream_init();
    int n, k;
    while(cin >> n >> k) {
        string s;
        cin >> s;
        Hash1 hash1(s);
        vector<int> imos(n + 10);

        auto Z = Z_Algorithm(s);

        for(int l = 1; k * l <= s.size(); l++) {
            bool ok = true;
            const int h1 = hash1.h(l);
            for(int i = 1; i < k; i++) {
                const int b = i * l;
                const int e = b + l;
                const int g1 = hash1.h(b, e);
                if(g1 != h1) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                const int b = l * k - 1;
                const int e = min((int)s.size(), b+1 + min(Z[b+1], l));
                imos[b] ++;
                imos[e] --;
            }
        }

        vector<int> sum(n + 10);
        sum[0] = imos[0];
        for(int i = 1; i <= n; i++) {
            sum[i] = imos[i] + sum[i-1];
        }

        REP(i, n) {
            cout << (sum[i] > 0 ? 1 : 0);
        }
        cout << endl;
    }
    return 0;
}

/* vim:set foldmethod=marker: */