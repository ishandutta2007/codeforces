#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
const int N = 2e5 + 10, SQN = 505;
int par[N], rnk[N];
void pre(int n){
    for(int i = 1; i <= n; i++) par[i] = i;
}
int find(int x){
    return (par[x] == x ? x : (par[x] = find(par[x])));
}
void merge(int x, int y){
    x = find(x); y = find(y);
    if(x == y) return;
    if(rnk[x] < rnk[y]) swap(x, y);
    if(rnk[x] == rnk[y]) rnk[x]++;
    par[y] = x;
}

unordered_set<int> colorset[N];
int a[N], b[N], c[N], cnt = 0;
map<pair<int, int>, int> answers;
unordered_map<int, int> mapping[N];
pair<int, int> invmapping[N];

int answer_query(int u, int v){
    if(u > v) swap(u, v);
    if(answers.find({u, v}) != answers.end()) return answers[{u, v}];
    if(colorset[u].size() > colorset[v].size()) swap(u, v);
    int ans = 0;
    for(int col : colorset[u]){
        if(colorset[v].count(col))
            ans += (find(mapping[col][u]) == find(mapping[col][v]));
    }
    if(u > v) swap(u, v);
    return answers[{u, v}] = ans;
}
int main(){
    int n, m, u, v, q;
    sd(n); sd(m);
    pre(2 * m);
    for(int i = 1; i <= m; i++){    
        sd(a[i]); sd(b[i]); sd(c[i]);
        colorset[a[i]].insert(c[i]);
        colorset[b[i]].insert(c[i]);

        if(!mapping[c[i]][a[i]]){
            mapping[c[i]][a[i]] = ++cnt;
            invmapping[cnt] = {a[i], c[i]};
        }

        if(!mapping[c[i]][b[i]]){
            mapping[c[i]][b[i]] = ++cnt;
            invmapping[cnt] = {b[i], c[i]};
        }

        merge(mapping[c[i]][a[i]], mapping[c[i]][b[i]]);
    }
    sd(q);
    for(int i = 1; i <= q; i++){
        sd(u); sd(v);
        printf("%d\n", answer_query(u, v));
    }
}