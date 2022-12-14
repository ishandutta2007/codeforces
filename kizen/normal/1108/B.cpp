#include <bits/stdc++.h>

using namespace std;

int N;
int arr[300];

int main(){
    scanf("%d", &N);
    for(int i=0;i<N;++i) scanf("%d", arr+i);
    sort(arr, arr+N);
    printf("%d ", arr[N-1]);
    for(int i=N-2;i>=0;--i) if(arr[N-1]%arr[i]!=0||arr[i]==arr[i+1]){
        printf("%d", arr[i]); return 0;
    }
    return 0;
}