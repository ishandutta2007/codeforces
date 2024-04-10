#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int n, m, a[405][405], dist[405];
priority_queue<pair<int,int> >pq;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) {
        int A, B;
        scanf("%d%d",&A,&B);
        a[A][B] = 1;
        a[B][A] = 1;
    }
    for(int i=2;i<=n;i++) dist[i] = inf;
    pq.push({0,1});
    while(!pq.empty()) {
        int cur = pq.top().second, val = -pq.top().first;
        pq.pop();
        if(dist[cur] != val) continue;
        for(int i=1;i<=n;i++) {
            if(a[cur][i] == a[1][n]) continue;
            if(dist[i] > dist[cur]+1) {
                dist[i] = dist[cur]+1;
                pq.push({-dist[i], i});
            }
        }
    }
    if(dist[n] == inf) puts("-1");
    else printf("%d\n",dist[n]);
}