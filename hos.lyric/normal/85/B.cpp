//  Yandex.Algorithm 2011 Round 1

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
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

int K[10];
Int T[10];
int N;
Int C[100010];

int main() {
    int i, j;
    
    for (; ~scanf("%d%d%d", &K[0], &K[1], &K[2]); ) {
        for (i = 0; i < 3; ++i) {
            T[i] = In();
        }
        N = in();
        for (j = 0; j < N; ++j) {
            C[j] = in();
        }
        sort(C, C + N);
        typedef pair<Int,pint> node;
        priority_queue< node,vector<node>,greater<node> > q;
        priority_queue< int,vector<int>,greater<int> > que[10];
        for (j = 0; j < N; ++j) {
            q.push(mp(C[j], mp(0, j)));
        }
        Int ans = 0;
        for (; !q.empty(); ) {
            Int t = q.top().first;
            int i = q.top().second.first;
            int j = q.top().second.second;
            q.pop();
            if (0 <= i - 1 && i - 1 < 3) {
                ++K[i - 1];
            }
            if (i == 3) {
                chmax(ans, t - C[j]);
            }
            if (0 <= i && i < 3) {
                que[i].push(j);
            }
            for (i = 0; i < 3; ++i) {
                for (; !que[i].empty() && K[i]; ) {
                    j = que[i].top();
                    que[i].pop();
                    --K[i];
//cout<<"deal "<<i<<" "<<j<<" : "<<t<<endl;
                    q.push(mp(t + T[i], mp(i + 1, j)));
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}