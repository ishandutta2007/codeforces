#include <bits/stdc++.h>

using namespace std;

int N;
int arr[104];

int main(){
    scanf("%d", &N);
    int a = 0, b = 0;
    for(int i=1;i<=N;++i) scanf("%d", arr+i);
    for(int i=1;i<=N;++i){
        if(arr[i]>0) ++a;
        else if(arr[i]<0) ++b;
    }
    if(a>=N/2+N%2) puts("1");
    else if(b>=N/2+N%2) puts("-1");
    else puts("0");
    return 0;
}