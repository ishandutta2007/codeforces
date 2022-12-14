#include <bits/stdc++.h>
using namespace std;

const int NS = 1004;
int N;
int arr[NS];

int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++) scanf("%d", arr+i);
    sort(arr, arr+N);
    if(N%2) printf("%d", arr[N/2]);
    else printf("%d", arr[N/2-1]);

    return 0;
}