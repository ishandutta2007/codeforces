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

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second
#define ll long long
#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<
#define _T1 id * 2, lo, mid
#define _T2 id * 2 + 1, mid + 1, hi
#define pll pair < ll, ll >

using namespace std;

const int oo = 1000000000;
const ll ool = (ll)oo * oo;

int n, m;
pll pt[200005];
ll a[200005];

bool NO = false;
int out[200005];

vector < pair < pll, int > > Rel;
set < pair < ll, int > > S;

int main(){
    scanf("%d%d", &n, &m);
    REP(n,i) scanf("%I64d%I64d", &pt[i].x, &pt[i].y);
    REP(m,i) scanf("%I64d", a + i);
    REP(n-1,i) Rel.pb({{pt[i + 1].x - pt[i].y, pt[i + 1].y - pt[i].x}, -i - 1});
    REP(m,i) Rel.pb({{a[i], ool + 5}, i + 1});
    sort(Rel.begin(), Rel.end());

    for (auto x : Rel){
        ll lo = x.x.x, hi = x.x.y;
        int id = x.y;
        if (id < 0) S.insert({hi, -id - 1});
        else {
            auto it = S.lower_bound({lo, -oo});
            if (it == S.end()) continue;
            out[it->y] = id;
            S.erase(it);
        }
    }

    if (S.size()) printf("No\n");
    else {
        printf("Yes\n");
        REP(n-1,i) printf("%d ", out[i]);
        printf("\n");
    }
    return 0;
}