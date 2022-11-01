#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 105;

int N, M;
bool adjmat[MAX_N][MAX_N];

int seen[MAX_N];

int tot;
bool change;

int dfs(int u) {
//    printf("dfs(%d)\n",u);
    int num = 1;
    for(int i=0;i<N;i++) {
        if(adjmat[u][i]) {
            if(seen[i] == -1) {
                if(seen[u] == 0) {
                    seen[i] = 1;
                } else {
                    seen[i] = 0;
                }
                num += dfs(i);
            } else if(seen[i] == seen[u]) {
                change = true;
                tot++;
            }
        }
    }
    return num;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
#endif
    scanf("%d %d",&N,&M);
    
    for(int i=0;i<M;i++) {
        int a, b;
        scanf("%d %d",&a,&b);
        a--;
        b--;
        adjmat[a][b] = true;
        adjmat[b][a] = true;
    }
    
    for(int i=0;i<MAX_N;i++) {
        seen[i] = -1;
    }
    
    int par = 0;
    for(int i=0;i<N;i++) {
        if(seen[i] == -1) {
            seen[i] = 0;
            change = false;
            int z = dfs(i);
            if(!change) {
                par += z%2;
            }
        }
    }
    
    printf("%d\n",tot/2 + par%2);
    
    return 0;
}