#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    scanf("%d", &N);
    int val = 0;
    for(int i=0;i<N;++i){
        int a;
        scanf("%d", &a);
        val += a;
    }
    for(int i=0;i<N;++i){
        int a;
        scanf("%d", &a);
        val -= a;
    }
    if(val>=0) puts("Yes");
    else puts("No");

    return 0;
}