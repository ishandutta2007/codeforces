#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int b_size = 350;
int n, s, e, cnt;
ll csum;
int segs[100010], sege[100010];
int num[100010], c[100010];
ll sum[100010];
int col[100010], ncol[100010];
vector<int> child[100010];
ll ans[100010];

struct Query{
    int idx;
    bool operator<(const Query &q) const {
        return segs[idx] / b_size == segs[q.idx] / b_size ?
               sege[idx] < sege[q.idx] :
               segs[idx] / b_size < segs[q.idx] / b_size;
    }
};

Query q[100010];

void f(int node, int prev){
    segs[node] = c[node] = ++cnt;
    for(int i = 0; i < child[node].size(); i++) if(child[node][i] != prev) f(child[node][i], node);
    sege[node] = cnt;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", col + i);
        csum += (ll)col[i];
    }
    for(int i = 0; i < n - 1; i++){
        scanf("%d%d", &s, &e);
        child[s].push_back(e);
        child[e].push_back(s);
    }
    f(1, 0);
    for(int i = 1; i <= n; i++) ncol[c[i]] = col[i];
    for(int i = 1; i <= n; i++) q[i].idx = i;
    int mcnt = 0;
    sum[0] = csum;
    sort(q + 1, q + n + 1);
    for(int j = segs[q[1].idx]; j <= sege[q[1].idx]; j++){
        num[ncol[j]]++;
        mcnt = max(mcnt, num[ncol[j]]);
        sum[num[ncol[j]] - 1] -= ncol[j];
        sum[num[ncol[j]]] += ncol[j];
    }
    ans[q[1].idx] = sum[mcnt];
    for(int i = 2; i <= n; i++){
        if(segs[q[i - 1].idx] <= segs[q[i].idx]){
        for(int j = segs[q[i - 1].idx]; j < segs[q[i].idx]; j++){
            num[ncol[j]]--;
            sum[num[ncol[j]] + 1] -= ncol[j];
            sum[num[ncol[j]]] += ncol[j];
            while(sum[mcnt] == 0) mcnt--;
        }
        }
        else{
        for(int j = segs[q[i - 1].idx] - 1; j >= segs[q[i].idx]; j--){
            num[ncol[j]]++;
            mcnt = max(mcnt, num[ncol[j]]);
            sum[num[ncol[j]] - 1] -= ncol[j];
            sum[num[ncol[j]]] += ncol[j];
        }
        }
        if(sege[q[i - 1].idx] <= sege[q[i].idx]){
        for(int j = sege[q[i - 1].idx] + 1; j <= sege[q[i].idx]; j++){
            num[ncol[j]]++;
            mcnt = max(mcnt, num[ncol[j]]);
            sum[num[ncol[j]] - 1] -= ncol[j];
            sum[num[ncol[j]]] += ncol[j];
        }
        }
        else{
        for(int j = sege[q[i - 1].idx]; j > sege[q[i].idx]; j--){
            num[ncol[j]]--;
            sum[num[ncol[j]] + 1] -= ncol[j];
            sum[num[ncol[j]]] += ncol[j];
            while(sum[mcnt] == 0) mcnt--;
        }
        }
        ans[q[i].idx] = sum[mcnt];
    }
    for(int i = 1; i <= n; i++) printf("%lld ", ans[i]);
}