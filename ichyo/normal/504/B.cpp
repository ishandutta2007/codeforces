// Template {{{
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

template<typename T1, typename T2>
ostream& operator << (ostream& os, const pair<T1, T2>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template<typename T>
ostream& operator << (ostream& os, const vector<T>& v) {
    os << "{";
    for(int i = 0; i < v.size(); i++)
        os << v[i] << (i+1<v.size()?", ":"");
    os << "}";
    return os;
}

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}
//}}}

struct BIT{
    vector<LL> sums;
    BIT(int n) : sums(n) {}

    // v[at] += by
    void add(int at, LL by) {
        while(at < sums.size()){
            sums[at] += by;
            at |= at + 1;
        }
    }

    // v[0] + ... + v[at]
    LL get(int at) {
        LL res = 0;
        while(at >= 0) {
            res += sums[at];
            at = (at & (at + 1)) - 1;
        }
        return res;
    }

    // --- optional ---
    int size() const { return sums.size(); }
    LL operator [](int idx) const { return sums[idx]; }
};
struct BITSet{
    BIT bit;
    BITSet(int n) : bit(n) {}
    bool insert(int x) {
        if(count(x) == 1) return false;
        bit.add(x, +1);
        return true;
    }

    bool erase(int x) {
        if(count(x) == 0) return false;
        bit.add(x, -1);
        return true;
    }

    int size() {
        return bit.get(bit.size() - 1);
    }

    void clear() {
        bit = BIT(bit.size());
    }

    int operator[](int idx) {
        if(idx < 0 || idx >= size()) return -1;
        idx ++;
        int x = -1;
        int k = 1;
        while(2 * k < bit.size()){
            k *= 2;
        }
        while(k > 0) {
           if(x + k < bit.size() && bit[x + k] < idx) {
                idx -= bit[x + k];
                x += k;
            }
            k >>= 1;
        }
        return x + 1;
    }

    int index(int x) {
        if(!count(x)) return -1;
        return bit.get(x) - 1;
    }

    int count(int x) {
        return bit.get(x) - bit.get(x - 1);
    }
};
int N;
vector<int> calc(const vector<int>& p) {
    vector<int> res(N);
    BITSet bit(N);
    REP(i, N) bit.insert(i);

    REP(i, N) {
        res[i] = bit.index(p[i]);
        bit.erase(p[i]);
    }
    return res;
}
vector<int> sum(const vector<int>& p, const vector<int>& q) {
    vector<int> res(N);
    int c = 0;
    for(int i = 0; i < N; i++) {
        const int j = N-1-i;
        const int B = i+1;
        res[j] = (p[j]+q[j]+c)%B;
        c = (p[j]+q[j]+c)/B;
    }
    return res;
}
vector<int> recover(const vector<int>& p) {
    BITSet bit(N);
    REP(i, N) bit.insert(i);
    vector<int> res(N);
    REP(i, N) {
        res[i] = bit[p[i]];
        bit.erase(res[i]);
    }
    return res;
}
int main(){
    iostream_init();
    while(cin >> N) {
        vector<int> p(N);
        vector<int> q(N);
        REP(i, N) cin >> p[i];
        REP(i, N) cin >> q[i];
        // cout << "p: " << p << endl;
        // cout << "q: " << q << endl;
        vector<int> pv = calc(p);
        // cout << "pv: " << pv << endl;
        vector<int> qv = calc(q);
        // cout << "qv: " << qv << endl;
        vector<int> rv = sum(pv, qv);
        // cout << "rv: " << rv << endl;
        vector<int> r = recover(rv);
        REP(i, N) {
            cout << r[i] << " \n"[i == N-1];
        }
    }
    return 0;
}

/* vim:set foldmethod=marker: */