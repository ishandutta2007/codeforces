#include <bits/stdc++.h>

using namespace std;

const int NS = (int)3e5+4;
int N;
int arr[NS];

int main(){
    scanf("%d", &N);
    for(int i=0;i<N;++i) scanf("%d", arr+i);
    int ans;
    for(int i=0;i<N;++i) if(arr[i]!=arr[N-1]){
        ans = N-i-1; break;
    }
    for(int i=N-1;i>=0;--i) if(arr[i]!=arr[0]){
        ans = max(ans, i); break;
    }
    printf("%d\n", ans);
    return 0;
}