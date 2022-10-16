#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
class CompFirst {
    public:
    bool operator () (const pair<int, int> &a, const pair<int, int> &b) const {
        return a.fi < b.fi;
    }
};
int n, a[MAX];
long long sum[MAX];
set<pair<int, int>, CompFirst> segments;
multiset<long long> sumSegments;
void init(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    FOR(i, 1, n) sum[i] = sum[i - 1] + a[i];
}
void process(void) {
    segments.insert(make_pair(1, n));
    sumSegments.insert(sum[n]);
    REP(love, n) {
        int x; scanf("%d", &x);
        __typeof(segments.begin()) it = segments.upper_bound(make_pair(x, x)); it--;
        int L = it->fi;
        int R = it->se;
        assert(L <= x && x <= R);
        sumSegments.erase(sumSegments.find(sum[R] - sum[L - 1]));
        segments.erase(it);
        if (L < x) {
            sumSegments.insert(sum[x - 1] - sum[L - 1]);
            segments.insert(make_pair(L, x - 1));
        }
        if (x < R) {
            sumSegments.insert(sum[R] - sum[x]);
            segments.insert(make_pair(x + 1, R));
        }
        if (sumSegments.empty()) cout << 0;
        else {
            __typeof(sumSegments.begin()) jt = sumSegments.end(); jt--;
            cout << *jt;
        }
        cout << "\n";
    }
}
int main(void) {
    init();
    process();
    return 0;
}