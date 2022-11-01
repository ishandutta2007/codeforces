#include <cstdio>
#include <tuple>
#include <algorithm>
#include <set>
using namespace std;

struct S {
    long long min, max;
    int id;
    S() {}
    S(long long a, long long b, int c) : min(a), max(b), id(c) {}
    bool operator < (const S& s) const {
        return max < s.max;
    }
};

S   reqs[199999];
pair<long long, int> vals[200000];
int ans[199999];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(long long i = 0, ll, rr; i < n; i++) {
        long long l, r;
        scanf("%I64d %I64d", &l, &r);
        if(i)
            reqs[i - 1] = S(l - rr, r - ll, i - 1);
        ll = l;
        rr = r;
    }
    for(int i = 0; i < m; i++) {
        scanf("%I64d", &vals[i].first);
        vals[i].second = i + 1;
    }
    sort(reqs, reqs + n - 1, [](const S& l, const S& r){ return l.min < r.min; });
    sort(vals, vals + m);
    multiset<S> s;
    int j = 0;
    for(int i = 0; i < m; i++) {
        while(j < n - 1 && reqs[j].min <= vals[i].first)
            s.insert(reqs[j++]);
        auto p = s.lower_bound(S(0, vals[i].first, 0));
        if(p != s.end()) {
            ans[p->id] = vals[i].second;
            s.erase(p);
        }
    }
    if(j == n - 1 && s.empty()) {
        puts("Yes");
        for(int i = 0; i < n - 1; i++)
            printf("%d%c", ans[i], i == n - 2 ? '\n' : ' ');
    } else {
        puts("No");
    }
}