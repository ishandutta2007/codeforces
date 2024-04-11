#include <cstdio>
#include <vector>
using namespace std;
const int mod = 1e9 + 7;

struct disj{
    int pa[200005];
    void init(int n){
        for(int i=0; i<=n; i++) pa[i] = i;
    }
    int find(int x){
        return pa[x] = (pa[x] == x ? x : find(pa[x]));
    }
    int uni(int p, int q){
        p = find(p);
        q = find(q);
        if(p == q) return 0;
        pa[q] = p;
        find(q);
        return 1;
    }
}disj;

int n, m, vis[200005];

int main(){
    scanf("%d %d",&n,&m);
    disj.init(2*n);
    while (m--) {
        int s,e,x;
        scanf("%d %d %d",&s,&e,&x);
        if(x == 0){
            disj.uni(s,e+n);
            disj.uni(e,s+n);
        }
        else{
            disj.uni(s,e);
            disj.uni(s+n,e+n);
        }
    }
    for (int i=1; i<=n; i++) {
        if(disj.find(i) == disj.find(i+n)){
            puts("0");
            return 0;
        }
    }
    int cnt = 0;
    for (int i=1; i<=2*n; i++) {
        if(!vis[disj.find(i)]){
            vis[disj.find(i)] = 1;
            cnt++;
        }
    }
    int ret = 1;
    for (int i=0; i<cnt / 2 - 1; i++) {
        ret *= 2;
        ret %= mod;
    }
    printf("%d",ret);
}