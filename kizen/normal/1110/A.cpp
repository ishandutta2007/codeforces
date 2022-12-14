#include <bits/stdc++.h>

using namespace std;

const int NS = (int)1e5+4;
int N, k;
int arr[NS];

int main(){
    scanf("%d %d", &N, &k);
    for(int i=0;i<k;++i) scanf("%d", arr+i);
    int ans = 0, val = 1;
    for(int i=k-1;i>=0;--i,val=(val*N)%2){
        ans = (ans+arr[i]*val)%2;
    }
    printf("%s", ans%2? "odd":"even");
    return 0;
}