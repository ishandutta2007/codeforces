#include <bits/stdc++.h>

using namespace std;

int T;
int k;
int arr[14], sum;

int sol(int x){
    int rv = (k-1)/sum*7;
    k -= sum*rv/7;
    for(int i=x;k;++i){
        if(i==8) i = 1;
        ++rv, k-=arr[i];
    }
    return rv;
}

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &k); sum = 0;
        int vv = k;
        for(int i=1;i<=7;++i) scanf("%d", arr+i), sum += arr[i];
        int ans = (int)1e9;
        for(int i=1;i<=7;++i) ans = min(ans, sol(i)), k = vv;
        printf("%d\n", ans);
    }
    return 0;
}