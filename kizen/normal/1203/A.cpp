#include <bits/stdc++.h>

using namespace std;

int Q, N;
int arr[204];

int main(){
    scanf("%d", &Q);
    while(Q--){
        scanf("%d", &N);
        for(int i = 1; i <= N; ++i) scanf("%d", arr + i);
        int val = arr[2] - arr[1] + (abs(arr[2] - arr[1]) > 1 ? arr[2] - arr[1] > 0 ? -N : N : 0), f = 1;
        for(int i = 3; i <= N; ++i){
            if(arr[i] - arr[i - 1] + (abs(arr[i] - arr[i - 1]) > 1 ? arr[i] - arr[i - 1] > 0 ? -N : N : 0) != val){
                f = 0; break;
            }
        }
        printf("%s\n", f ? "YES" : "NO");
    }
    return 0;
}