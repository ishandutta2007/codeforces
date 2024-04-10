#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define all(a) (a).begin(), (a).end()

const int MAXN = 1e5 + 5, B = 350, MAX = 1 << 20;
typedef long long int64;

struct query {
    int l, r;
    int index;
    query() {}
    query(int l, int r, int index) : l(l), r(r), index(index) {}
    friend bool operator < (const query &q1, const query &q2) {
        return q1.r < q2.r;
    }
};

int k, cnt[MAX];
int64 tmp;

int add(int v) {
    tmp += cnt[v ^ k];
    cnt[v]++;
}
int del(int v) {
    cnt[v]--;
    tmp -= cnt[v ^ k];
}

vector<query> v[B];

int pref[MAXN];
int64 sol[MAXN];

int main() {
    int n, q;
    scanf("%d", &n);
    scanf("%d", &q);
    scanf("%d", &k);
    for(int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        pref[i] = pref[i - 1] ^ x;
    }
    for(int i = 0; i < q; ++i) {
        int l, r;
        scanf("%d", &l); --l;
        scanf("%d", &r); ++r;
        v[l / B].push_back(query(l, r, i));
    }
    for(int i = 0; i < B; ++i)
        sort(all(v[i]));
    for(int i = 0; i < B; ++i) {
        tmp = 0;
        int left, right;
        left = right = B * i;
        for(auto q : v[i]) {
            while(right < q.r) {
                add(pref[right++]);
            }
            while(left < q.l) {
                del(pref[left++]);
            }
            while(left > q.l) {
                add(pref[--left]);
            }
            sol[q.index] = tmp;
        }
        memset(cnt, 0, sizeof cnt);
    }
    for(int i = 0; i < q; ++i) {
        printf("%I64d\n", sol[i]);
    }
    return 0;
}