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

#define MAX   100100
#define MAX_BLOCK   333

#define POSITIVE   1
#define NEGATIVE   2

int numBook, delta, numValue;
int type[MAX], capa[MAX];
long long sum[MAX];
int smallMatchID[MAX], bigMatchID[MAX];

int blockID[MAX], numBlock, blockSize;
pair<int, int> blocks[MAX];
int tmpCount[MAX];

int numQuery;
pair<int, int> queries[MAX];
long long answer[MAX];
vector<int> queryAt[MAX];

void init(void) {
    scanf("%d%d", &numBook, &delta);
    FOR(i, 1, numBook) scanf("%d", &type[i]);
    FOR(i, 1, numBook) scanf("%d", &capa[i]);
}

void prepare(void) {
    FOR(i, 1, numBook) if (type[i] == NEGATIVE) capa[i] *= -1;
    FOR(i, 1, numBook) sum[i] = sum[i - 1] + capa[i];

    vector<long long> values;
    FOR(i, 0, numBook) values.push_back(sum[i]);
    sort(ALL(values));
    values.resize(unique(ALL(values)) - values.begin());

    numValue = values.size();
    FOR(i, 0 , numBook) sum[i] = lower_bound(ALL(values), sum[i]) - values.begin() + 1;

    FOR(i, 1, numValue) {
        long long cur = values[i - 1];
        int id = lower_bound(ALL(values), cur - delta) - values.begin();
        if (id < values.size() && values[id] == cur - delta) smallMatchID[i] = id + 1;
        else smallMatchID[i] = -1;

        id = lower_bound(ALL(values), cur + delta) - values.begin();
        if (id < values.size() && values[id] == cur + delta) bigMatchID[i] = id + 1;
        else bigMatchID[i] = -1;
    }

//    FORE(it, values) cout << *it << " "; cout << endl;
//    FOR(i, 1, numBook) cout << sum[i] << " "; cout << endl;
//    FOR(i, 1, numValue) printf("%d big %d small %d\n", i, bigMatchID[i], smallMatchID[i]);
}

void buildBlock(void) {
    while (1LL * blockSize * blockSize < numBook) blockSize++;
    while ((numBook + 1) / blockSize + ((numBook + 1) % blockSize > 0) > MAX_BLOCK) blockSize++;

    int i = 0;
    while (i <= numBook) {
        int j = min(i + blockSize - 1, numBook);
        blocks[++numBlock] = make_pair(i, j);
        FOR(k, i, j) blockID[k] = numBlock;
        i = j + 1;
    }

//    printf("%d blocks of %d\n", numBlock, blockSize);
//    FOR(i, 0, numBook) printf("%d ", blockID[i]); printf("\n");
}

void readQuery(void) {
    scanf("%d", &numQuery);
    FOR(i, 1, numQuery) {
        int l, r; scanf("%d%d", &l, &r); l--;
        queries[i] = make_pair(l, r);
        if (blockID[l] != blockID[r]) {
            int tmp = l == blocks[blockID[l]].fi ? blockID[l] : blockID[l] + 1;
            queryAt[tmp].push_back(i);
        }
    }
}

bool compare(const int &x, const int &y) {
    return queries[x].se < queries[y].se;
}

void answerLargeQuery(int blockID) {
    memset(tmpCount, 0, sizeof tmpCount);
    assert(!queryAt[blockID].empty());
    sort(ALL(queryAt[blockID]), compare);

    int start = blocks[blockID].fi;
    int j = start - 1;
    long long sumPair = 0;
    FORE(it, queryAt[blockID]) {
        int l = queries[*it].fi;
        int r = queries[*it].se;
        assert (j <= r);
        while (j < r) {
            j++;
            int match = smallMatchID[sum[j]] < 0 ? 0 : tmpCount[smallMatchID[sum[j]]];
            sumPair += match;
            tmpCount[sum[j]]++;
        }

        answer[*it] = sumPair;

//        printf("FOR #%d (%d, %d) is %lld\n", *it, l, r, answer[*it]);
        FORD(i, start - 1, l) {
            int match = bigMatchID[sum[i]] < 0 ? 0 : tmpCount[bigMatchID[sum[i]]];
//            printf("%d (%lld) matches %d\n", i, sum[i], match);
            answer[*it] += match;
            tmpCount[sum[i]]++;
        }
        FOR(i, l, start - 1) tmpCount[sum[i]]--;
    }
}

long long query(int l, int r) {
    assert(blockID[l] == blockID[r]);

    long long res = 0;
    FOR(i, l, r) {
        int match = smallMatchID[sum[i]] < 0 ? 0 : tmpCount[smallMatchID[sum[i]]];
        res += match;
        tmpCount[sum[i]]++;
    }
    FOR(i, l, r) tmpCount[sum[i]]--;
    return res;
}

void process(void) {
    FOR(i, 1, numBlock) if (!queryAt[i].empty()) answerLargeQuery(i);
    memset(tmpCount, 0, sizeof tmpCount);
    FOR(i, 1, numQuery) if (blockID[queries[i].fi] == blockID[queries[i].se])
        answer[i] = query(queries[i].fi, queries[i].se);

    FOR(i, 1, numQuery) cout << answer[i] << "\n";
}

int main(void) {
#ifdef SKY
    freopen("tmp.txt", "r", stdin);
#endif // SKY
    init();
    prepare();
    buildBlock();
    readQuery();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/