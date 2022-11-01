#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <assert.h>
#include <stack>
#include <unistd.h>
#include <bitset>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second
#define ll long long
#define TRACE(x) cerr << #x << " = " << x << endl

using namespace std;

int n, m;
vector < pii > E[100005];
bool Check = true;

bool bio[100005];
int clr[100005];
void DFS(int id){
    bio[id] = true;
    for (auto x : E[id]){
        if (!bio[x.x]) clr[x.x] = (clr[id] ^ x.y), DFS(x.x);
        else if (clr[x.x] != (clr[id] ^ x.y)) Check = false;
    }
}

int main(){
    scanf("%d%d", &n, &m);
    REP(m,i){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c), --a, --b, c ^= 1;
        E[a].pb({b, c}), E[b].pb({a, c});
    }
    ll R = 1;
    DFS(0);
    REP(n,i) if (!bio[i]) DFS(i), R = (R * 2) % 1000000007;
    R *= Check;
    printf("%d\n", (int)R);
    return 0;
}