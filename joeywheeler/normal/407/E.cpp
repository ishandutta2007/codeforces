#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#include <map>

#define FO(i,a,b) for (int i = (a); i < (int)(b); i++)

using namespace std;

int n, k, d;
vector<int> a;

int L=0, R=1;

void update(int nl, int nr) {
    //printf("[%d,%d)\n", nl, nr);
    if (nr - nl > R - L || nr - nl == R - L && nl < L) {
        L = nl;
        R = nr;
    }
}

struct rtree {
    long long v[800000];
    long long o[800000];

    void clear(int i, int rs, int re) {
        if (rs+1 == re) v[i] = o[i] = 0;
        else {
            int m = (rs+re)/2;
            clear(2*i+1, rs, m);
            clear(2*i+2, m, re);
            v[i] = o[i] = 0;
        }
    }

    void inc(int i, int rs, int re, int qs, int qe, int dv) {
        if (rs == qs && re == qe) {
            v[i] += dv;
            o[i] += dv;
        } else {
            int m = (rs+re)/2;
            if (qs < m) inc(2*i+1, rs, m, qs, min(qe,m), dv);
            if (qe > m) inc(2*i+2, m, re, max(qs,m), qe, dv);

            v[i] = o[i] + min(v[2*i+1], v[2*i+2]);
        }
    }

    int fle(int i, int rs, int re, int qe, int q) {
        if (rs+1 == re) {
            assert(v[i] <= q);
            return rs;
        } else {
            q -= o[i];
            int m = (rs+re)/2;
            if (qe <= m || v[2*i+1] <= q) return fle(2*i+1, rs, m, min(qe,m), q);
            else return fle(2*i+2, m, re, qe, q);
        }
    }

    long long q(int i, int rs, int re, int j) {
        if (rs+1 == re) return v[i];
        else {
            int m = (rs+re)/2;
            if (j < m) return o[i] + q(2*i+1, rs, m, j);
            else return o[i] + q(2*i+2, m, re, j);
        }
    }
} T;

void solve(vector<int> &v, int init) {
    FO(i,0,v.size()) v[i] /= d;
    //FO(i,0,v.size()) printf("%d ", v[i]);
    //printf("\n");
    //printf("init=%d\n", init);

    map<int,int> last;

    T.clear(0, 0, v.size());

    vector<int> mx(1,0);
    vector<int> mn(1,0);
    
    last[v[0]] = 0;

    FO(i,1,v.size()) {
        if (last.count(v[i])) {
            T.inc(0, 0, v.size(), 0, last[v[i]]+1, k+2*n);
        }
        last[v[i]] = i;

        T.inc(0, 0, v.size(), 0, i, -1);

        while (!mx.empty() && v[mx.back()] < v[i]) {
            if (mx.size() >= 2)
                T.inc(0, 0, v.size(), mx[mx.size()-2]+1, mx[mx.size()-1]+1, v[i]-v[mx.back()]);
            else {
                T.inc(0, 0, v.size(), 0, mx[mx.size()-1]+1, v[i]-v[mx.back()]);
            }
            mx.pop_back();
        }
        mx.push_back(i);
        while (!mn.empty() && v[mn.back()] > v[i]) {
            if (mn.size() >= 2)
                T.inc(0, 0, v.size(), mn[mn.size()-2]+1, mn[mn.size()-1]+1, v[mn.back()]-v[i]);
            else
                T.inc(0, 0, v.size(), 0, mn[mn.size()-1]+1, v[mn.back()]-v[i]);
            mn.pop_back();
        }
        mn.push_back(i);

        //printf("mx-mn:");
        //FO(j,0,i+1) printf(" %lld", T.q(0, 0, v.size(), j));
        //printf("\n");

        update(init + T.fle(0, 0, v.size(), i+1, k), init+i+1);
    }
}

int main() {
    scanf("%d %d %d", &n, &k, &d);
    a.resize(n);
    FO(i,0,n) {
        scanf("%d", &a[i]);
        a[i] += 1e9 + 10;
    }

    if (d == 0) {
        int p = 0;
        FO(i,0,n) {
            if (a[i] != a[p]) {
                update(p,i);
                p = i;
            }
        }
        update(p,n);
        printf("%d %d\n", L+1, R);
        return 0;
    }

    vector<int> v;
    v.reserve(n);
    int init = 0;
    FO(i,0,n) {
        if (!v.empty() && abs(a[i]-v.back()) % d) {
            solve(v, init);
            v.clear();
            init = i;
        }
        v.push_back(a[i]);
    }
    solve(v, init);

    printf("%d %d\n", L+1, R);

    return 0;
}