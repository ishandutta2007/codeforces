#include <bits/stdc++.h>

using namespace std;

int N;
int arr[24], f;

void sol(int pos, int val){
    if(pos==N+1){
        if(((val+360000)%360)==0) f = 1;
        return;
    }
    sol(pos+1, val+arr[pos]);
    sol(pos+1, val-arr[pos]);
}

int main(){
    scanf("%d", &N);
    for(int i=1;i<=N;++i) scanf("%d", arr+i);
    sol(1, 0);
    if(f) printf("YES");
    else printf("NO");
    return 0;
}