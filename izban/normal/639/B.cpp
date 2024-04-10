#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = -1;
const long long INF = 1e9 + 19;

int n, d, h;

void read() {
    scanf("%d%d%d", &n, &d, &h);
}

void solve() {
    if (h * 2 < d) {
        puts("-1");
        return;
    }

    vector < pair < int, int > > answer;
    int cur = 1;
    
    for (int i = 0; i < h; i++) {
       answer.pb(mp(i, i + 1)); 
    }
    cur = h + 1;
    int t = d - h;
    int last = 0;
    for (int i = 0; i < t; i++)  {
        answer.pb(mp(last, cur)); 
        last = cur;
        cur++;
    }

    int k = n - d - 1;
    if (k > 0 && h == 1 && d == 1) {
        puts("-1");
        return;
    }
    if (d > h) {
        for (int i = 0; i < k; i++) {
            answer.pb(mp(0, cur++));
        } 
    }
    else {
        for (int i = 0; i < k; i++) {
            answer.pb(mp(1, cur++));
        } 
    }

    for (auto x: answer)
        printf("%d %d\n", x.fr + 1, x.sc + 1);
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}