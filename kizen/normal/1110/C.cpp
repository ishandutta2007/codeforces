#include <bits/stdc++.h>

using namespace std;

int T;

int gcd(int a, int b){
    return b==0? a:gcd(b, a%b);
}

int main(){
    scanf("%d", &T);
    while(T--){
        int N; scanf("%d", &N);
        if(__builtin_popcount(N+1)==1){
            int ans = 0;
            for(int i=2;i*i<=N;++i) if(N%i==0) ans = max(ans, N/i);
            printf("%d\n", max(ans, 1));
        }
        else{
            int i = 1;
            while(i<=N) i*=2;
            printf("%d\n", i-1);
        }
    }
    return 0;
}