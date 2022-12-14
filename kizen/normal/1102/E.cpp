#include <bits/stdc++.h>

using namespace std;

const int NS = (int)2e5+4;
int N;
int arr[NS];
map < int, int > last;

int main(){
    scanf("%d", &N);
    for(int i=0;i<N;++i) scanf("%d", arr+i), last[arr[i]] = i;
    int val = 0;
    long long ans = 1;
    for(int i=0;i<N;++i){
        if(i>val) ans = ans*2%998244353;
        val = max(val, last[arr[i]]);
    }
    printf("%lld", ans);
    return 0;
}