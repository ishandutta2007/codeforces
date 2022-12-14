#include <bits/stdc++.h>

using namespace std;

int T;
const int NS = (int)2e5 + 4;
int N;
int arr[NS];

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        for(int i = 1; i <= N; ++i){
            scanf("%d", arr + i);
        }
        int low = (int)1e9, ans = 0;
        for(int i = N; i >= 1; --i){
            if(arr[i] <= low) low = arr[i];
            else{
                ++ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}