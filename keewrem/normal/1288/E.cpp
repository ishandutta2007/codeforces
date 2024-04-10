#include <bits/stdc++.h>
using namespace std;
int N,M,k,first_available;
int best_min[300010];
int best_max[300010];
int pos[300010];
int fenw[700000];
void metti(int a){
    for(; a<700000; a+=a&-a)fenw[a]++;
}
void togli(int a){
    for(; a<700000; a+=a&-a)fenw[a]--;
}
int query(int a){
    int res = 0;
    for(; a; a-=a&-a)res+=fenw[a];
    return res;
}
int main(){
    scanf("%d %d", &N, &M);
    first_available = N + 1;
    for(int i = 1; i <= N; i++)metti(i);
    for(int i = 1; i <= N; i++){
        best_min[i] = i;
        best_max[i] = i;
        pos[i] = N + 1 - i;
    }
    while(M--){
        scanf("%d", &k);
        best_min[k] = 1;
        best_max[k] = max(best_max[k], N - query(pos[k]-1));
        togli (pos [k]);
        pos[k] = first_available++;
        metti (pos [k]);
    }
    for(int i = 1; i <= N; i++)best_max[i] = max(best_max[i], N - query(pos[i]-1));
    for(int i = 1; i <= N; i++)printf("%d %d\n", best_min[i], best_max[i]);
    return 0;
}