#include <bits/stdc++.h>

using namespace std;

int seg[104];
int N, M;

int main(){
    scanf("%d %d", &N, &M);
    while(N--){
        int l, r;
        scanf("%d %d", &l, &r);
        for(int i=l;i<=r;++i) seg[i] = 1;
    }
    int ans = 0;
    for(int i=1;i<=M;++i) ans += !seg[i];
    printf("%d\n", ans);
    for(int i=1;i<=M;++i) if(!seg[i]) printf("%d ", i);

    return 0;
}