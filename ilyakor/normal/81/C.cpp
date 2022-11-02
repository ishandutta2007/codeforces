#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

int n, a, b;

bool cmp(ii p, ii q) {
    if (p.first != q.first) return p.first > q.first;
    if (a <= b) {
        return p.second < q.second;
    }
    return p.second > q.second;
}

int main()
{
    cin >> n >> a >> b;
    vector<ii> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i].first);
        v[i].second = i;
    }
    if (a == b) {
        for (int i = 0; i < a; ++i)
            printf("1 ");
        for (int i = 0; i < b; ++i)
            printf("2 ");
        printf("\n");
        return 0;
    }
    sort(all(v), cmp);
    vi res(n);
    for (int i = 0; i < min(a, b); ++i) {
        if (a <= b) res[v[i].second] = 1;
        else res[v[i].second] = 2;
    }
    for (int i = 0; i < max(a, b); ++i) {
        if (a <= b) res[v[i + min(a, b)].second] = 2;
        else res[v[i + min(a, b)].second] = 1;
    }
    for (int i = 0; i < n; ++i)
        printf("%d ", res[i]);
    printf("\n");
    return 0;
}