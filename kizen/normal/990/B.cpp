#include <bits/stdc++.h>

using namespace std;

const int NS = 2*(1e5)+4;
int N, k;
int arr[NS], ans;

int main(){
    scanf("%d %d", &N, &k);
    for(int i=0;i<N;i++) scanf("%d", arr+i);
    sort(arr, arr+N);
    for(int i=0;i<N;i++){
        int pos = lower_bound(arr, arr+N, arr[i]+1)-arr;
        if(pos==N) ans++;
        else if(arr[i]+k<arr[pos]) ans++;
    }
    printf("%d", ans);

    return 0;
}