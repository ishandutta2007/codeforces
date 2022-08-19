#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[100005];

int n,m;
int a[100005];
int dfn[100005], rev[100005], size[100005], piv;

struct query{int s,e,p,x;}q[100005];
bool cmp(query a, query b){return a.s / 300 == b.s / 300 ? (a.e < b.e) : (a.s < b.s);}

int ret[100005];

int dfs(int x, int pa){
    size[x] = 1;
    dfn[x] = ++piv;
    rev[dfn[x]] = x;
    for (int &i : graph[x]){
        if(i != pa) size[x] += dfs(i,x);
    }
    return size[x];
}

int cnt[100005]; // range color count
int cnt2[100005]; // count of range color count;
int col_cnt;

void solve(){
    int s = 2, e = 1;
    for (int i=0; i<m; i++) {
        while (s < q[i].s) {
            int piv = a[rev[s]];
            cnt2[cnt[piv]]--;
            cnt[piv]--;
            s++;
        }
        while (s > q[i].s) {
            s--;
            int piv = a[rev[s]];
            cnt[piv]++;
            cnt2[cnt[piv]]++;
        }
        while (e < q[i].e) {
            e++;
            int piv = a[rev[e]];
            cnt[piv]++;
            cnt2[cnt[piv]]++;
        }
        while (e > q[i].e) {
            int piv = a[rev[e]];
            cnt2[cnt[piv]]--;
            cnt[piv]--;
            e--;
        }
        ret[q[i].x] = cnt2[q[i].p];
    }
}

int main(){
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
    }
    for (int i=0; i<n-1; i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,0);
    for (int i=0; i<m; i++) {
        scanf("%d %d",&q[i].s,&q[i].p);
        q[i].e = dfn[q[i].s] + size[q[i].s] - 1;
        q[i].s = dfn[q[i].s];
        q[i].x = i;
    }
    sort(q,q+m,cmp);
    solve();
    for (int i=0; i<m; i++) {
        printf("%d\n",ret[i]);
    }
}