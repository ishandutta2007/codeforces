#include <bits/stdc++.h>

using namespace std;

const int NS = (int)2e5+4;
int N, H;
int arr[NS][3];

int main(){
    scanf("%d %d", &N, &H);
    for(int i=1;i<=N;++i) scanf("%d %d", arr[i], arr[i]+1);
    int ans = arr[N][1]+H-arr[N][0], pos = arr[N][1]+H, apos = N;
    for(int i=N-1;i>=1;--i){
        pos -= arr[i+1][0]-arr[i][1];
        while(apos&&pos<=arr[apos][1]) pos -= arr[apos][1]-arr[apos][0], --apos;
        ans = max(ans, pos-arr[i][0]);
    }
    printf("%d", ans);
    return 0;
}