#include <bits/stdc++.h>

using namespace std;

const int NS = (int)3e5+4;
int N;
pair < int, int > arr[NS];

int main(){
    scanf("%d", &N);
    for(int i=1;i<=N;++i){
        scanf("%d %d", &arr[i].first, &arr[i].second);
        if(arr[i].first>arr[i].second) swap(arr[i].first, arr[i].second);
    }
    int A, B, val;
    val = (int)2e9;
    for(int i=1;i<=N;++i){
        if(arr[i].second<val||(arr[i].second==val&&arr[i].first>arr[A].first)){
            val = arr[i].second, A = i;
        }
    }
    val = -1;
    for(int i=1;i<=N;++i){
        if(arr[i].first>val||(arr[i].first==val&&arr[i].second<arr[B].second)){
            val = arr[i].first, B = i;
        }
    }

    int ans = 0;
    int l = -1, r = (int)2e9;
    for(int i=1;i<=N;++i) if(i!=A){
        l = max(l, arr[i].first), r = min(r, arr[i].second);
    }
    ans = max(ans, r-l);
    l = -1, r = (int)2e9;
    for(int i=1;i<=N;++i) if(i!=B){
        l = max(l, arr[i].first), r = min(r, arr[i].second);
    }
    ans = max(ans, r-l);
    printf("%d", ans);

    return 0;
}