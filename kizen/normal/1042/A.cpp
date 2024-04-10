#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[104];

int main(){
    scanf("%d %d", &N, &M);
    int big = 0;
    for(int i=1;i<=N;++i) scanf("%d", arr+i), big = max(big, arr[i]);
    int ans2 = M+big;
    while(M--){
        int low = 20000, pos;
        for(int i=1;i<=N;++i) if(arr[i]<low){
            low = arr[i], pos = i;
        }
        ++arr[pos];
    }
    int ans = 0;
    for(int i=1;i<=N;++i) ans = max(ans, arr[i]);
    printf("%d %d", ans, ans2);
    return 0;
}