#include<bits/stdc++.h>
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
#define rank   ___rank
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

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

const int INF = (int)1e9 + 7;

class SegmentTree {
private:

    vector<int> tree;
    int n;

    void assign(int i, int l, int r, int pos, int value) {
        if (l == r) {
            tree[i] = value;
            return;
        }

        int m = (l + r) >> 1;
        if (pos > m) assign(2 * i + 1, m + 1, r, pos, value);
        else assign(2 * i, l, m, pos, value);
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }

    int getMax(int i, int l, int r, int u, int v) const {
        if (l > v || r < u || l > r || v < u) return INF;
        if (u <= l && r <= v) return tree[i];
        int m = (l + r) >> 1;
        int L = getMax(2 * i, l, m, u, v);
        int R = getMax(2 * i + 1, m + 1, r, u, v);
        return max(L, R);
    }

public:
    SegmentTree(int n = 0) {
        this->n = n;
        tree.assign(4 * n + 7, INF);
    }

    void assign(int pos, int value) {
        assign(1, 1, n, pos, value);
    }

    int getMax(int l, int r) {
        return getMax(1, 1, n, l, r);
    }
};

const string YES = "YES";
const string NO = "NO";
void answer(const string &s) {
    cout << s << endl;
    exit(EXIT_SUCCESS);
}

#define MAX   500500

int a[MAX], n, range, rank[MAX], values[MAX];
int minRangeIndex[MAX], depends[MAX], minDependant[MAX];
vector<int> deadPoints;

void init(void) {
    scanf("%d%d", &n, &range);
    FOR(i, 1, n) scanf("%d", &a[i]);
}

bool compare(const int &x, const int &y) {
    return a[x] < a[y];
}

void prepare(void) {
    vector<int> indices;
    FOR(i, 1, n) indices.push_back(i);
    sort(ALL(indices), compare);
    FOR(i, 1, n) rank[indices[i - 1]] = i;
    FOR(i, 1, n) values[i] = a[indices[i - 1]];

    deque<int> dq;
    FOR(i, 1, n) {
        while (!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= range) {
            while (!dq.empty() && dq.front() < i - range + 1) dq.pop_front();
            minRangeIndex[i - range + 1] = dq.front();
        }
    }

    FOR(i, 1, n) if (i + range <= n && a[i] <= a[minRangeIndex[i + 1]]) deadPoints.push_back(i);

    set<int> lessIndices;
    int j = 0;
    FORE(it, indices) {
        while (j < indices.size() && a[indices[j]] < a[*it]) lessIndices.insert(indices[j++]);
        if (*it + range > n || binary_search(ALL(deadPoints), *it)) depends[*it] = -1;
        else {
            __typeof(lessIndices.begin()) L = lessIndices.upper_bound(*it);
            __typeof(lessIndices.begin()) R = lessIndices.upper_bound(*it + range);
            assert(L != lessIndices.end()); L++;
            depends[*it] = L == R ? minRangeIndex[*it + 1] : -1;
        }
    }
}

void process(void) {
    if (deadPoints.empty()) answer(YES);

    memset(minDependant, 0x3f, sizeof minDependant);
    SegmentTree myit(n);

    int minDeadPoint = INF, minDeadPointExceptLast = INF;
    FORE(it, deadPoints) {
        minimize(minDeadPoint, a[*it]);
        if (*it != deadPoints.back()) minimize(minDeadPointExceptLast, a[*it]);
    }

    FORD(left, n, 1) {
        if (left < n && depends[left + 1] > 0) {
            int pos = depends[left + 1];
            minimize(minDependant[pos], a[left + 1]);
            myit.assign(rank[pos], minDependant[pos]);
        }

        if (deadPoints.front() < left - range) continue;
        if (binary_search(ALL(deadPoints), left)) continue;
        if (deadPoints.size() > 1 && deadPoints[deadPoints.size() - 2] > left) continue;

        int minValue = left + range > n ? -INF : a[minRangeIndex[left + 1]] + 1;
        int maxValue = deadPoints.back() > left ? minDeadPointExceptLast - 1 : minDeadPoint - 1;
        minimize(maxValue, a[left] - 1);
        if (minValue > maxValue) continue;

        if (left > deadPoints.back()) {
            int L = lower_bound(values + 1, values + n + 1, minValue) - values;
            int R = upper_bound(values + 1, values + n + 1, maxValue) - values;
            if (L < R && myit.getMax(L, R - 1) > a[left]) answer(YES);
        } else {
            int pos = deadPoints.back();
            if (minValue <= a[pos] && a[pos] <= maxValue && minDependant[pos] > a[left]) answer(YES);
        }
    }

    answer(NO);
}

int main(void) {
    init();
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/