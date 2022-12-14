#include <bits/stdc++.h>

using namespace std;

int Q;
long long N, M, k;

int main(){
    scanf("%d", &Q);
    while(Q--){
        scanf("%lld %lld %lld", &N, &M, &k);
        if(N<M) swap(N, M);
        if(N%2!=M%2) k-=1;
        else if(N%2!=k%2) k-=2;
        --N;
        printf("%lld\n", k<N? -1:k);
    }

    return 0;
}