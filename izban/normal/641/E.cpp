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
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;

struct Fenwick {
    vector < int > data;
    int n;
    Fenwick(int n): n(n) {
        data.resize(n + 1);
    }
    void add(int pos, int val) {
        for (; pos + 1 < (int)data.size(); pos |= (pos + 1))
            data[pos + 1] += val;
    }
    int get(int r) {
        int sum = 0;
        for (; r > 0; r &= (r - 1))
            sum += data[r];
        return sum;
    }
};

struct Query {
    int type, t, x;
    void read() {
        scanf("%d%d%d", &type, &t, &x);
    }
};

int n;
Query q[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        q[i].read();
    }
}

void solve() {
    vector < int > xx;
    vector < Fenwick > f;
    vector < vector < int > > d; 
    vector < pair < int, int > > b; 
    for (int i = 0; i < n; i++)
        b.pb(mp(q[i].x, q[i].t));

    sort(b.begin(), b.end());

    for (int i = 0; i < (int)b.size(); ) {
        int j = i;
        int x = b[j].fr;
        xx.pb(x);
        d.pb(vector < int >());
        for (; i < (int)b.size() && b[i].fr == b[j].fr; i++)
            d.back().pb(b[i].sc);

        f.pb(Fenwick(i - j));
    }

        
    for (int i = 0; i < n; i++) {
        int id = lower_bound(xx.begin(), xx.end(), q[i].x) - xx.begin();
        assert(0 <= id && id < (int)xx.size());
        assert(xx[id] == q[i].x);
    
        int id2 = lower_bound(d[id].begin(), d[id].end(), q[i].t) - d[id].begin();
        //db2(id, id2);
        //db(d[id].size());
        //db(q[i].type);

        if (q[i].type == 1) 
            f[id].add(id2, 1);
        if (q[i].type == 2)
            f[id].add(id2, -1);
        if (q[i].type == 3)
            printf("%d\n", f[id].get(id2));
   } 




    





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