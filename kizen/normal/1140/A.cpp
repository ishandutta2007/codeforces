#include <bits/stdc++.h>

using namespace std;

int N;
int arr[10004];

int main(){
    scanf("%d", &N);
    for(int i=1;i<=N;++i) scanf("%d", arr+i);
    int big = 0, cnt = 0;
    for(int i=1;i<=N;++i){
        ++cnt;
        int j = i;
        big = max(big, arr[i]);
        for(;j<=big;++j){
            big = max(big, arr[j]);
        }
        i = j-1;
    }
    printf("%d\n", cnt);
    return 0;
}