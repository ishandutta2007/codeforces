#include <bits/stdc++.h>

using namespace std;

const int NS = (int)2e5+4;
int N, M, q;
int un[NS], X[NS], Y[NS];

int fd(int x){
    return x==un[x]? x:un[x] = fd(un[x]);
}

int main(){
    scanf("%d %d %d", &N, &M, &q);
    for(int i=1;i<=q;++i) un[i] = i;

    for(int i=1;i<=q;++i){
        int x, y;
        scanf("%d %d", &x, &y);
        if(X[x]){
            int pos = fd(X[x]);
            un[i] = pos;
        }
        X[x] = fd(i);
        if(Y[y]){
            int pos = fd(Y[y]);
            int aaa = fd(i);
            un[aaa] = pos;
        }
        Y[y] = fd(i);
    }

    int ans = 0;
    for(int i=1;i<=q;++i) ans += un[i] == i;
    for(int i=1;i<=N;++i) ans += !X[i];
    for(int i=1;i<=M;++i) ans += !Y[i];

    printf("%d", ans-1);

    return 0;
}