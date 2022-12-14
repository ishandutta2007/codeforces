#include <bits/stdc++.h>

using namespace std;

const int NS = (int)1e5+4;
int N, M;
int chk[NS];
priority_queue < int, vector < int >, greater < int > > pq;
vector < int > way[NS];

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0;i<M;++i){
        int a, b; scanf("%d %d", &a, &b);
        way[a].push_back(b), way[b].push_back(a);
    }
    int cnt = 1;
    chk[1] = 1;
    printf("1 ");
    for(int i=0;i<(int)way[1].size();++i) pq.push(way[1][i]);
    while(cnt<N){
        while(chk[pq.top()]) pq.pop();
        printf("%d ", pq.top());
        chk[pq.top()] = 1;
        int a = pq.top();
        pq.pop();
        for(int i=0;i<(int)way[a].size();++i) if(!chk[way[a][i]]) pq.push(way[a][i]);
        ++cnt;
    }
    return 0;
}