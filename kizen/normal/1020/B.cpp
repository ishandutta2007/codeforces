#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1004];
int chk[1004];

int main(){
    scanf("%d", &N);
    for(int i=1;i<=N;++i) scanf("%d", arr+i);
    for(int i=1;i<=N;++i){
        for(int j=0;j<1004;++j) chk[j] = 0;
        int x;
        for(x=i;!chk[x];x=arr[x]) chk[x] = 1;
        printf("%d ", x);
    }

    return 0;
}