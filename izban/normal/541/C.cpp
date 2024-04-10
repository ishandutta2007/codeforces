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

#define equal equalll
#define less lesss
const int N = 1000;
const int INF = 1e9;

int n;
int a[N];
vector < int > e[N];
bool use[N];
bool circle[N];
vector < int > comp;

void dfs(int v) {
    use[v] = 1;
    comp.pb(v);
    for (auto u: e[v])
        if (!use[u])
            dfs(u);
}

long long lcm(long long a, long long b) {
    long long d = __gcd(a, b);
    return a / d * b;
}

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        e[i].pb(a[i]);
        e[a[i]].pb(i);
    }
    long long lcir = 1;
    int mxDist = 0;
    for (int i = 0; i < n; i++) {
        if (use[i]) continue;

        comp.clear();
        dfs(i);
        int v = comp[0];
        for (int i = 0; i < (int)comp.size(); i++) 
            v = a[v];
        
        //circle[v] = 1;
        int clen = 0; 
        for (; !circle[v]; clen++, v = a[v]) {
            circle[v] = 1; 
        }
        lcir = lcm(lcir, clen);
        for (int i = 0; i < (int)comp.size(); i++) {
            int v = comp[i];
            int d = 0;
            for (; !circle[v]; v = a[v], d++);
            mxDist = max(mxDist, d);
        }
    }
    //db(lcir);
    //db(mxDist);
    long long answer;
    answer = lcir;
    for (; answer < mxDist; answer += lcir);
    
    cout << answer << endl;
}

void printAns() {

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
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}