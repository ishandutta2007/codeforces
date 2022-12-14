#include <bits/stdc++.h>
using namespace std;

const int NS = 2*(1e5)+4;
int N, k;
int arr[NS];

int main(){
    scanf("%d %d", &N, &k);
    for(int i=0;i<N;i++) scanf("%d", arr+i);
    sort(arr, arr+N);
    if(k==0){
        if(arr[0]>1) puts("1");
        else puts("-1");
        return 0;
    }
    else if(k==N) printf("%d", arr[N-1]);
    else{
        if(arr[k]>arr[k-1]) printf("%d", arr[k-1]);
        else puts("-1");
    }

    return 0;
}