#include <bits/stdc++.h>
using namespace std;

const int NS = 2*(1e5)+4;
int N, M;
int edgeCnt[NS];
int Start[NS], Link[NS*2], Child[NS*2], np=1;
int chk[NS];
int f;

void pushEdge(int a, int b){
    np++;
    Link[np] = Start[a], Child[np] = b, Start[a] = np;
    edgeCnt[a]++;
}

void Dfs(int x){
    chk[x] = 1;
    if(edgeCnt[x]!=2) f = 0;
    for(int i=Start[x];Child[i]!=0;i=Link[i]){
        int next = Child[i];
        if(!chk[next]){
            Dfs(next);
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0;i<M;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        pushEdge(a, b);
        pushEdge(b, a);
    }
    int ans = 0;
    for(int i=1;i<=N;i++){
        if(chk[i]==0){
            f = 1;
            Dfs(i);
            ans += f;
        }
    }

    printf("%d", ans);

    return 0;
}