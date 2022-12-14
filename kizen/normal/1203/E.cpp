#include <bits/stdc++.h>

using namespace std;

const int NS = (int)2e5 + 4;
int N;
int arr[NS];

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i) scanf("%d", arr + i);
    sort(arr + 1, arr + N + 1);
    int val = 0, ans = 0;
    for(int i = 1; i <= N; ++i){
        if(arr[i] + 1 > val){
            ++ans; val = max(val + 1, arr[i] - 1);
        }
    }
    printf("%d\n", ans);
    return 0;
}