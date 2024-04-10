#include <bits/stdc++.h>

using namespace std;

int main(){
    int N; scanf("%d", &N);
    N%=4;
    if(!N||N==3) puts("0");
    else puts("1");
    return 0;
}