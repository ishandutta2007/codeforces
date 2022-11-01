#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <assert.h>
#include <stack>
#include <unistd.h>
#include <bitset>
#include <set>
#include <cstring>
#include <map>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second
#define ll long long
#define TRACE(x) // cerr << #x << " = " << x << endl
#define _ << " _ " <<
#define _T1 id * 2, lo, mid
#define _T2 id * 2 + 1, mid + 1, hi
#define pll pair < ll, ll >

using namespace std;

int n, m;
int x[200005];

vector < int > V1, V2;
map < int, int > M;

int GCD(int a, int l, bool num = false){ TRACE(a _ l);
    if (l == 0) return a;
    if (l > 0){
        int x = a + l;
        int p = lower_bound(V1.begin(), V1.end(), x + 1) - V1.begin();
        int y = V1[p - 1];
        if (y == a){
            if (num) return a;
            return GCD(a, -l, true);
        }
        int t = l / (y - a);
        if (t & 1) return GCD(y, -(l % (y - a)));
        else return GCD(a, l % (y - a));
    }
    else {
        int x = a + l;
        int p = lower_bound(V1.begin(), V1.end(), x) - V1.begin();
        int y = V1[p];
        if (y == a){
            if (num) return a;
            return GCD(a, -l, true);
        }
        int t = l / (a - y);
        if (t & 1) return GCD(y, -(l % (a - y)));
        else return GCD(a, l % (a - y));
    }
}

int GCD2(int a, int l){ TRACE(a _ l);
    if (l == 0) return a;
    int x = a + l;
    int p = lower_bound(V1.begin(), V1.end(), x + 1) - V1.begin();
    int y = V1[p - 1];
    return GCD(y, -(l - y + a));
}

int main(){
    scanf("%d%d", &n, &m);
    REP(n,i) scanf("%d", x + i), V1.pb(x[i]), V2.pb(-x[i]), M[x[i]] = i + 1;
    sort(V1.begin(), V1.end());
    sort(V2.begin(), V2.end());
    REP(m,i){
        int a, l;
        scanf("%d%d", &a, &l), --a;
        printf("%d\n", M[GCD2(x[a], l)]); //exit(0);
    }
    return 0;
}