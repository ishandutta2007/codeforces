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

double res;
vector<ii> v;
int A;

double calc() {
    double cur = 0.0;
    for (int mask = 0; mask < (1 << sz(v)); ++mask) {
        double p = 1.0;
        int cnt = 0;
        int B = 0;
        for (int i = 0; i < sz(v); ++i) {
            double q = (v[i].second + 0.) / 100.0;
            q = max(q, 0.);
            q = min(q, 1.);
            if ((mask >> i) & 1) {
                ++cnt;
                p *= q;
            }
            else {
                B += v[i].first;
                p *= 1. - q;
            }           
        }
        if (cnt * 2 > sz(v)) {
            cur += p;
            continue;
        }
        p *= (A + 0.) / (A + B + 0.);
        cur += p;
    }
    return cur;
}

void dfs(int ind, int left) {
    if (ind >= sz(v)) {
        res = max(res, calc());
        return;
    }
    for (int i = 0; i <= left; ++i) {
        v[ind].second += 10 * i;
        dfs(ind + 1, left - i);
        v[ind].second -= 10 * i;
    }
}

int main()
{
    int n, k;
    cin >> n >> k >> A;
    v.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i].first >> v[i].second;
    res = 0.0;
    dfs(0, k);
    printf("%.10lf\n", res);
    return 0;
}