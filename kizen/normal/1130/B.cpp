#include <bits/stdc++.h>

using namespace std;

const long long NS = (long long)1e5+4;
long long N;
long long arr[NS][3];
long long d[NS][3];

int main(){
    scanf("%lld", &N);
    arr[0][1] = arr[0][2] = 1;
    for(int i=1;i<=N*2;++i){
        long long num; scanf("%lld", &num);
        if(!arr[num][1]) arr[num][1] = i;
        else arr[num][2] = i;
    }
    for(int i=1;i<=N;++i){
        d[i][1] = d[i][2] = (long long)1e9;
        d[i][1] = min(d[i-1][1]+abs(arr[i][1]-arr[i-1][1])+abs(arr[i][2]-arr[i-1][2]),
                      d[i-1][2]+abs(arr[i][1]-arr[i-1][2])+abs(arr[i][2]-arr[i-1][1]));
        d[i][2] = min(d[i-1][1]+abs(arr[i][1]-arr[i-1][2])+abs(arr[i][2]-arr[i-1][1]),
                      d[i-1][2]+abs(arr[i][1]-arr[i-1][1])+abs(arr[i][2]-arr[i-1][2]));
    }
    printf("%lld", min(d[N][1], d[N][2]));
    return 0;
}