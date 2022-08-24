//  Codeforces Beta Round #12
//  Problem D

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() {
    int x = 0, c;
    for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; }
    do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10);
    return x;
}

template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
const int INF = 1001001001;

struct T {
    int x, y, z;
    bool operator<(const T &a) const {
        return (x != a.x) ? (x > a.x) : (y != a.y) ? (y < a.y) : (z < a.z);
    }
};

int N;
T ts[500010];
map<int,int> w;

int main() {
    int i;
    int ans = 0;
    
    N = in();
    for (i = 0; i < N; ++i) ts[i].x = in();
    for (i = 0; i < N; ++i) ts[i].y = in();
    for (i = 0; i < N; ++i) ts[i].z = in();
    sort(ts, ts + N);
    w[-INF] = INF;
    w[INF] = -INF;
    for (i = 0; i < N; ++i) {
        int &y = ts[i].y, &z = ts[i].z;
//cout<<ts[i].x<<" "<<y<<" "<<z<<endl;
//cout<<" ";pvp(w.begin(),w.end());
        map<int,int>::iterator it = w.upper_bound(y);
        if (z < it->second) {
            ++ans;
        } else if (!w.count(y) || w[y] < z) {
            w[y] = z;
            for (it = --w.lower_bound(y); it->second < z; ) {
                w.erase(it--);
            }
        }
    }
    printf("%d\n", ans);
    
    return 0;
}