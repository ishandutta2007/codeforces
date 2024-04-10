#include <bits/stdc++.h>

using namespace std;

const int NS = (int)1e5 + 4;
int N;
int arr[NS];
vector < int > same;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", arr + i);
    }
    sort(arr, arr + N);
    for(int i = 0; i < N; ++i){
        if(((i && arr[i - 1] + 1 == arr[i]) || !arr[i]) && i + 1 < N && arr[i] == arr[i + 1]){
            puts("cslnb"); return 0;
        }
        if(i + 1 < N && arr[i] == arr[i + 1]) same.push_back(i);
    }
    if((int)same.size() > 1){
        puts("cslnb"); return 0;
    }
    long long ans = 0;
    for(int i = 0; i < N; ++i){
        ans += arr[i] - i;
    }
    printf("%s\n", ans % 2 == 0 ? "cslnb" : "sjfnb");
    return 0;
}