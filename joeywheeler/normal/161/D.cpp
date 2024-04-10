#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

#ifdef DEBUG
#define D(x...) fprintf(stderr,x)
#else
#define D(x...)
#endif

typedef long long ll;
const int MAX_N = 50005;
const int MAX_K = 505;

int N, K;
vector<int> edges[MAX_N];
vector<int> children[MAX_N];

bool seen[MAX_N];
ll num[MAX_N][MAX_K];

ll tot = 0ll;

void build(int node) {
    for(int i=0;i<edges[node].size();i++) {
        int o = edges[node][i];
        if(!seen[o]) {
            children[node].push_back(o);
            seen[o] = true;
            build(o);
        }
    }
}

void paths(int u) {
//    D("*** paths(%d)\n",u);
    for(int i=0;i<children[u].size();i++) {
        paths(children[u][i]);
    }

    num[u][0] = 1ll;

    for(int i=0;i<children[u].size();i++) {
        int v = children[u][i];
//        D("** considering child %d\n",v);
        for(int j=0;j<K;j++) {
            int target = K-j-1;
//            D("%lld paths from v of length %d, %lld paths from u of length %d\n",num[v][j],j,num[u][target],target);
            tot += num[v][j] * num[u][target];
        }

        for(int j=0;j<K;j++) {
            num[u][j+1] += num[v][j];
        }
    }
}

int main() {
    scanf("%d %d",&N,&K);

    for(int i=0;i<N-1;i++) {
        int a, b;
        scanf("%d %d",&a,&b);
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    seen[0] = true;
    build(0);
    paths(0);

    cout << tot;

    return 0;
}