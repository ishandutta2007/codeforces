#include <bits/stdc++.h>

using namespace std;

const long long NS = (long long)1e5 + 4;
long long N, Q;
long long arr[NS * 3];
struct data{
    long long num, pos;
    bool operator<(const data&r)const{
        return num < r.num;
    }
}brr[NS * 3];
long long ans[NS * 3][3];

int main(){
    scanf("%lld %lld", &N, &Q);
    for(long long i = 1; i <= N; ++i){
        scanf("%lld", arr + i);
    }
    for(long long i = 1; i <= Q; ++i){
        scanf("%lld", &brr[i].num);
        brr[i].pos = i;
    }
    sort(brr + 1, brr + Q + 1);
    long long sta = 1;
    for(long long i = 1; i <= Q; ++i){
        while(sta <= min(N - 1, brr[i].num - 1)){
            if(arr[sta] > arr[sta + 1]){
                arr[sta + N] = arr[sta + 1];
                arr[sta + 1] = arr[sta]; ++sta;
            }
            else{
                arr[sta + N] = arr[sta]; ++sta;
            }
        }
        if(brr[i].num < N){
            ans[brr[i].pos][1] = arr[sta];
            ans[brr[i].pos][2] = arr[sta + 1];
        }
        else{
            long long val = ((brr[i].num - N + 1) - 1) % (N - 1) + 1;
            ans[brr[i].pos][1] = arr[sta];
            ans[brr[i].pos][2] = arr[sta + val];
        }
    }
    for(long long i = 1; i <= Q; ++i){
        printf("%lld %lld\n", ans[i][1], ans[i][2]);
    }
    return 0;
}