#include <cstdio>
#include <cassert>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

struct ii {
    int first;
    int second;
    int i;

    ii(int a=0, int b=0) {
        first = a;
        second = b;
    }

    bool operator<(const ii &o) const {
        return first == o.first ? second < o.second : first < o.first;
    }
};

ii l[300010];
int n, w;
ll A[300010];
int tk[300010];

bool cmp(ii a, ii b) {
    return a.second-a.first > b.second-b.first;
}

ll cost(int n1, int n2, ll r = -1) {
    priority_queue<int> q;
    ll sum = 0;
    ll res = 1e15;

    int I = -1;

    FO(i,0,n+1) {
        if (sz(q) == n1) A[i] = sum;
        else A[i] = 1e15;
        if (n1 == 0) continue;
        if (i != n) {
            if (sz(q) == n1 && q.top() > l[i].first) {
                sum -= q.top();
                q.pop();
            }
            if (sz(q) < n1) {
                sum += l[i].first;
                q.push(l[i].first);
            }
        }
    }

    q = priority_queue<int>(); sum = 0;

    for (int i = n; i >= 0; i--) {
        if (sz(q) == n2) {
            res = min(res, A[i] + sum);
            if (A[i] + sum == r) {
                I = i;
                goto tkc;
            }
        }
        if (n2 == 0) continue;
        if (i != 0) {
            if (sz(q) == n2 && q.top() > l[i-1].second) {
                sum -= q.top();
                q.pop();
            }
            if (sz(q) < n2) {
                sum += l[i-1].second;
                q.push(l[i-1].second);
            }
        }
    }

    return res;

tkc:;
    priority_queue<ii> oq;

    FO(i,0,n+1) {
        if (i == I) {
            while (!oq.empty()) {
                tk[l[oq.top().second].i] = 1;
                oq.pop();
            }
            break;
        }
        if (n1 == 0) continue;
        if (i != n) {
            if (sz(oq) == n1 && oq.top().first > l[i].first) oq.pop();
            if (sz(oq) < n1) oq.push(ii(l[i].first, i));
        }
    }

    for (int i = n; i >= 0; i--) {
        if (i == I) {
            while (!oq.empty()) {
                tk[l[oq.top().second].i] = 2;
                oq.pop();
            }
        }
        if (n2 == 0) continue;
        if (i != 0) {
            if (sz(oq) == n2 && oq.top().first > l[i-1].second) oq.pop();
            if (sz(oq) < n2) oq.push(ii(l[i-1].second, i-1));
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &n, &w);
    FO(i,0,n) {
        scanf("%d %d", &l[i].first, &l[i].second);
        l[i].i = i;
    }
    if (n == 1) {
        if (w == 1) printf("%d\n1\n", l[0].first);
        else printf("%d\n2\n", l[0].second);
        return 0;
    }

    sort(l,l+n,cmp);
    vector<int> m;
    FO(i,0,n+1) {
        if ((w-i) % 2 == 0 && i + 2*(n-i) >= w) m.push_back(i);
    }
    pair<ll,int> res(1e15,-1);
    int s = 0, e = sz(m)-1;
    while (s <= e) {
        int md1 = s + (e-s)/3, md2 = s + 2*(e-s)/3;
        ll v1 = cost(m[md1], (w-m[md1]) / 2);
        res = min(res, make_pair(v1,m[md1]));
        if (s == e) break;
        else if (md1 == md2) md2++;
        ll v2 = cost(m[md2], (w-m[md2]) / 2);
        res = min(res, make_pair(v2,m[md2]));
        if (v1 <= v2) {
            e = md2-1;
        } else {
            s = md1+1;
        }
    }
    printf("%lld\n", res.first);
    cost(res.second, (w-res.second)/2, res.first);
    FO(i,0,n) {
        printf("%d", tk[i]);
    }
    printf("\n");
}