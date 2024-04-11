#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
#include <sstream>
using namespace std;
typedef long long ll;
#define N 222222
#define MOD 1000003
struct cell {
    int l,r;
    ll res,add;
} a[3*N];
ll s[N],f[N];
struct race {
    int start;
    ll cost;
};
vector<race> g[N];

void build(int x, int l, int r) {
    a[x].l = l; a[x].r = r;
    if (l < r) {
    build(x+x,l,(l+r)>>1);
    build(x+x+1,((l+r)>>1)+1,r);
    }
}

void modify(int x, int l, int r, ll val) {
    if (l > r) return;
    if (l > a[x].r || r < a[x].l) return;
    if (l <= a[x].l && r >= a[x].r) {
    a[x].add += val;
    return;
    }
    
    modify(x+x,l,r,val);
    modify(x+x+1,l,r,val);
    
    a[x].res = max(a[x+x].res + a[x+x].add, a[x+x+1].res + a[x+x+1].add);
}

ll findmax(int x, int l, int r, ll sumadd) {
    if (l > r) return 0;
    if (a[x].l > r || a[x].r < l) return 0;
    if (l <= a[x].l && r >= a[x].r) return a[x].res + a[x].add + sumadd;
    return max(findmax(x+x,l,r,sumadd+a[x].add),findmax(x+x+1,l,r,sumadd+a[x].add));
}

int n,m;

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) {
    scanf("%I64d",&s[i]);
    s[i] += s[i-1];
    }
    while (m--) {
    int x; race cur;
    scanf("%d%d%I64d",&cur.start,&x,&cur.cost);
    g[x].push_back(cur);
    }
    
    build(1,0,n);
    
    ll curmax = 0;
    for (int i=1;i<=n;i++) {
    for (int j=0;j<g[i].size();j++)
        modify(1,0,g[i][j].start-1,g[i][j].cost);
    
    curmax = f[i] = max(curmax, findmax(1,0,i-1,0) - s[i]);
    modify(1,i,i,f[i] + s[i]);
    }
    
    cout << curmax << endl;
    
    // f[i] = f[j] - s[i] + s[j]
    
    return 0;
}