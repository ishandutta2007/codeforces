#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct edge{
    int a, b, c, ind;
};

edge edges[100005];

int n, m;
vector <int> graf[100005];
int indeg[100005];
int in[100005];

bool check(int k){
    for(int i=1; i<=n; i++){
        graf[i].clear();
        in[i] = 0;
        indeg[i] = 0;
    }
    for(int i=k+1; i<=m; i++){
        graf[edges[i].a].push_back(edges[i].b);
        indeg[edges[i].b]++;
    }
    int cnt = 0;
    queue <int> q;
    for(int i=1; i<=n; i++){
        if(!indeg[i]) q.push(i);
    }
    while(!q.empty()){
        int v = q.front();
        q.pop();
        in[v] = ++cnt;
        for(auto c : graf[v]){
            indeg[c]--;
            if(!indeg[c]) q.push(c);
        }
    }
    return cnt == n;
}

bool cmp(edge a, edge b){
    return a.c < b.c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    cin >> n >> m;
    for(int i=1; i<=m; i++){
        cin >> edges[i].a >> edges[i].b >> edges[i].c;
        edges[i].ind = i;
    }
    sort(edges+1, edges+1+m, cmp);
    int l = 0, r = m, res = m;
    while(l <= r){
        int mid = (l+r)/2;
        if(check(mid)){
            res = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    check(res);
    cout << edges[res].c << " ";
    int g = 0;
    for(int i=1; i<=res; i++){
        if(in[edges[i].a] > in[edges[i].b]) g++;
    }
    cout << g << "\n";
    for(int i=1; i<=res; i++){
        if(in[edges[i].a] > in[edges[i].b]) cout << edges[i].ind << " ";
    }
    return 0;
}