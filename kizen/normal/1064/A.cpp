#include <bits/stdc++.h>

using namespace std;

int arr[5];

int main(){
    for(int i=0;i<3;++i) scanf("%d", arr+i);
    sort(arr, arr+3);
    printf("%d\n", max(0, arr[2]+1-arr[0]-arr[1]));
    return 0;
}