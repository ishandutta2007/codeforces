#include <bits/stdc++.h>

using namespace std;

int N, M;
int cnt[5004], num[5004];

int main(){
    scanf("%d %d", &N, &M);
    while(M--){
        int s, e; scanf("%d %d", &s, &e);
        if(!num[s]) num[s] = e;
        else{
            ++cnt[s];
            if((e+N-s)%N<(num[s]+N-s)%N) num[s] = e;
        }
    }
    for(int i=1;i<=N;++i){
        int ans = 0;
        for(int j=1;j<=N;++j) if(num[j]){
            ans = max(ans, (j+N-i)%N+cnt[j]*N+(num[j]+N-j)%N);
        }
        printf("%d ", ans);
    }
    return 0;
}