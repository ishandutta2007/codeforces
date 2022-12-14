#include <bits/stdc++.h>

using namespace std;

int N;
int cnt;

int main(){
    scanf("%d", &N);
    for(int i=1;N;i<<=1){
        N-=i, ++cnt;
        N = max(N, 0);
    }
    printf("%d", cnt);

    return 0;
}