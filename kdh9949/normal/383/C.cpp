#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, m;
int s, e;
int order, x, v;
int num[200010], segs[200010], sege[200010], buho[200010];
ll ini[200010];

struct SegTree{
    ll data[1000010];
    int ts;
    SegTree(int n){
        for(ts = 1; ts < n; ts *= 2);
        for(int i = 1; i < ts + n; i++) data[i] = 0;
    }
    void update(int x, int s, int e, int val){
        s += ts - 1;
        e += ts - 1;
        if(buho[x] == -1) val *= -1;
        while(s <= e){
            if(s % 2 == 1) data[s++] += val;
            if(e % 2 == 0) data[e--] += val;
            s /= 2; e /= 2;
        }
    }
    ll nodesum(int x){
        ll sum = 0;
        int b = buho[x];
        x += ts - 1;
        while(x){
            sum += data[x];
            x /= 2;
        }
        return b * sum;
    }

} *ST;

vector<int> edge[200010];
int cnt;

void dfs(int node, int pre, int bh){
    num[node] = segs[node] = ++cnt;
    buho[num[node]] = bh;
    for(int i = 0; i < edge[node].size(); i++){
        if(edge[node][i] != pre) dfs(edge[node][i], node, bh * -1);
    }
    sege[node] = cnt;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld", ini + i);
    for(int i = 0; i < n - 1; i++){
        scanf("%d%d", &s, &e);
        edge[s].push_back(e);
        edge[e].push_back(s);
    }
    dfs(1, 0, 1);
    ST = new SegTree(n);
    for(int i = 0; i < m; i++){
        scanf("%d", &order);
        if(order == 1){
            scanf("%d%d", &x, &v);
            ST -> update(num[x], segs[x], sege[x], v);
        }
        else{
            scanf("%d", &x);
            printf("%lld\n", ST -> nodesum(num[x]) + ini[x]);
        }
    }
}