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

const LL LINF = LLONG_MAX / 4;
vector<LL> calc(string s, char L, char R, int w) {
    const int n = s.size();
    deque<LL> left, right;
    int x = 0;
    REP(i, n) {
        if(s[i] == L) {
            x++;
        } else if(s[i] == R) {
            x--;
        }
        if(x < 0) {
            int index = -x - 1;
            if(index >= right.size()) {
                right.push_back(i+1);
                assert(right.size() == index+1);
            }
        } else if(x > 0) {
            int index = x - 1;
            if(index >= left.size()) {
                left.push_back(i+1);
                assert(left.size() == index+1);
            }
        }
    }
    vector<LL> res(w, LINF);
    auto update = [&]{
        for(int i = 0; i < left.size() && i < w; i++) {
            if(res[i] > left[i]) {
                res[i] = left[i];
            }
        }
        for(int i = 0; i < right.size() && i < w; i++) {
            if(res[w - 1 - i] > right[i]) {
                res[w - 1 - i] = right[i];
            }
        }
    };
    if(x > 0) {
        int d = x;
        // assert(left.size() - d >= 0);
        while(left.size() < w) {
            REP(i, d) {
                int idx = left.size() - d;
                left.push_back(left[idx] + n);
                if(left.size() == w) break;
            }
        }
    } else if(x < 0) {
        int d = -x;
        // assert(right.size() - d >= 0);
        while(right.size() < w) {
            REP(i, d) {
                int idx = right.size() - d;
                right.push_back(right[idx] + n);
            }
        }
    }
    update();
    return res;
}
// ModInt (ref. anta) {{{
template<int MOD>
struct ModInt{
    static const int Mod = MOD;
    unsigned val;
    ModInt():val(0){}
    ModInt(unsigned x):val(x%MOD){}
    ModInt(signed x) {
        int y = x % MOD;
        if(y < 0) y += MOD;
        val = y;
    }
    ModInt(signed long long x) {
        int y = x % MOD;
        if(y < 0) y += MOD;
        val = y;
    }

    ModInt &operator+=(ModInt rhs) {
        val += rhs.val;
        if(val >= MOD) val -= MOD;
        return *this;
    }
    ModInt &operator-=(ModInt rhs) {
        val += MOD - rhs.val;
        if(val >= MOD) val -= MOD;
        return *this;
    }
    ModInt &operator*=(ModInt rhs) {
        val = (unsigned long long)val * rhs.val % MOD;
        return *this;
    }
    ModInt &operator/=(ModInt rhs) {
        return *this *= rhs.inv();
    }

    ModInt inv() const {
        signed a = val, b = MOD, u = 1, v = 0;
        while(b) {
            signed t = a / b;
            a -= t * b; std::swap(a, b);
            u -= t * v; std::swap(u, v);
        }
        if(u < 0) u += MOD;
        ModInt res;
        res.val = u;
        return res;
    }

    ModInt operator+(ModInt rhs) const {
        return ModInt(*this) += rhs;
    }
    ModInt operator-(ModInt rhs) const {
        return ModInt(*this) -= rhs;
    }
    ModInt operator*(ModInt rhs) const {
        return ModInt(*this) *= rhs;
    }
    ModInt operator/(ModInt rhs) const {
        return ModInt(*this) /= rhs;
    }

    // compare
    bool operator==(ModInt rhs) const {
        return val == rhs.val;
    }
    bool operator!=(ModInt rhs) const {
        return val != rhs.val;
    }
    bool operator< (ModInt rhs) const {
        return val <  rhs.val;
    }
    bool operator<=(ModInt rhs) const {
        return val <= rhs.val;
    }
    bool operator> (ModInt rhs) const {
        return val >  rhs.val;
    }
    bool operator>=(ModInt rhs) const {
        return val >= rhs.val;
    }
};
template<int MOD>
ostream& operator << (ostream& os, const ModInt<MOD> m) {
    return os << m.val;
}
template<int MOD, typename T>
ModInt<MOD> pow(ModInt<MOD> a, T b) {
    if(b == 0) {
        return 1;
    } else {
        auto w = pow(a*a, b/2);
        if(b&1) w *= a;
        return w;
    }
}
// }}}
typedef ModInt<1000000007> mint;
int main(){
    iostream_init();
    int n, h, w;
    while(cin >> n >> h >> w) {
        string s;
        cin >> s;
        auto wv = calc(s, 'L', 'R', w);
        auto hv = calc(s, 'U', 'D', h);
        sort(hv.begin(), hv.end());
        sort(wv.begin(), wv.end());
        if(hv.back() == LINF && wv.back() == LINF) {
            cout << -1 << endl;
            continue;
        }
        int index = 0;
        mint sum = 0;
        mint res = 0;
        for(int y = 0; y < h; y++) {
            while(index < wv.size() && wv[index] < hv[y]){
                sum += wv[index];
                index++;
            }
            // assert(index == wv.size() || wv[index] >= hv[y]);
            res += sum + mint(w - index) * mint(hv[y]);
        }
        cout << res.val << endl;
    }
    return 0;
}