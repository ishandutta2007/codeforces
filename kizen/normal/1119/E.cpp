#include <bits/stdc++.h>

using namespace std;

const long long NS = (long long)3e5+4;
long long N;
long long arr[NS];

int main(){
    scanf("%lld", &N);
    for(long long i=1;i<=N;++i) scanf("%lld", arr+i);
    long long ans = 0, j = 1;
    for(long long i=1;i<=N;++i){
        ans += arr[i]/3, arr[i]%=3;
        j = max(j, i+1);
        while(j<=N){
            if(arr[i]*2>=arr[j]){
                ans += arr[j]/2, arr[i] -= arr[j]/2, arr[j]%=2, ++j;
            }
            else{
                ans += arr[i], arr[j] -= arr[i]*2, arr[i] = 0; break;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}